--- controller/seafile-controller.c.orig	2016-11-12 03:30:44 UTC
+++ controller/seafile-controller.c
@@ -17,6 +17,19 @@
 #include "log.h"
 #include "seafile-controller.h"
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#include <sys/user.h>
+#include <limits.h>
+
+#ifndef WITH_PROC_FS
+#define WITH_PROC_FS g_file_test("/proc/curproc", G_FILE_TEST_EXISTS)
+#endif
+
+static char *command_name = NULL;
+#endif
+
 #define CHECK_PROCESS_INTERVAL 10        /* every 10 seconds */
 
 SeafileController *ctl;
@@ -244,7 +257,20 @@ static void
 init_seafile_path ()
 {
     GError *error = NULL;
+#if defined(__linux__)
     char *binary = g_file_read_link ("/proc/self/exe", &error);
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    /*
+     * seafile.sh starts the process using abs path
+     */
+    char binary[_POSIX_PATH_MAX];
+    memset(binary, 0, _POSIX_PATH_MAX);
+    char * rc = realpath(command_name, binary);
+    if (!rc) {
+        seaf_warning ("failed to readpath: %s\n", binary);
+        return;
+    }
+#endif
     char *tmp = NULL;
     if (error != NULL) {
         seaf_warning ("failed to readlink: %s\n", error->message);
@@ -258,7 +284,9 @@ init_seafile_path ()
 
     topdir = g_path_get_dirname (installpath);
 
+#if defined(__linux__)
     g_free (binary);
+#endif
     g_free (tmp);
 }
 
@@ -400,11 +428,40 @@ need_restart (int which)
         return FALSE;
     } else {
         char buf[256];
+	gboolean with_procfs;
+#if defined(__linux__)
+	with_procfs = g_file_test("/proc/self", G_FILE_TEST_EXISTS | G_FILE_TEST_IS_DIR);
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+	with_procfs = g_file_test("/proc/curproc", G_FILE_TEST_EXISTS | G_FILE_TEST_IS_DIR);
+#else
+	with_procfs = FALSE;
+#endif
+	if (with_procfs) {
         snprintf (buf, sizeof(buf), "/proc/%d", pid);
         if (g_file_test (buf, G_FILE_TEST_IS_DIR)) {
             return FALSE;
         } else {
             return TRUE;
+	}
+
+	} else {
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#ifdef __OpenBSD__
+            int min[6] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, pid, sizeof(struct kinfo_proc), 1};
+#else
+            int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, pid};
+#endif
+            size_t len = sizeof(struct kinfo_proc);
+            struct kinfo_proc kp;
+            if (sysctl(mib, sizeof(mib)/sizeof(mib[0]), &kp, &len, NULL, 0) != -1 && 
+	        len == sizeof(struct kinfo_proc)) {
+                return FALSE;        
+            } else {
+                return TRUE;
+            }
+#else
+	return FALSE;
+#endif
         }
     }
 }
@@ -890,6 +947,9 @@ int main (int argc, char **argv)
         exit (1);
     }
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    command_name = argv[0];
+#endif
     char *config_dir = DEFAULT_CONFIG_DIR;
     char *central_config_dir = NULL;
     char *seafile_dir = NULL;
@@ -926,7 +986,7 @@ int main (int argc, char **argv)
         case 'f':
             daemon_mode = 0;
             break;
-        case 'L':
+        case 'l':
             logdir = g_strdup(optarg);
             break;
         case 'g':
