--- controller/seafile-controller.c.orig	2014-08-05 01:28:35.000000000 -0400
+++ controller/seafile-controller.c	2014-11-22 22:00:58.614945337 -0500
@@ -18,10 +18,23 @@
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
+#endif
+
 #define CHECK_PROCESS_INTERVAL 10        /* every 10 seconds */
 
 SeafileController *ctl;
 
+static char *command_name = NULL;
 static char *controller_pidfile = NULL;
 
 char *bin_dir = NULL;
@@ -273,7 +286,20 @@
 init_seafile_path ()
 {
     GError *error = NULL;
+#if defined(__linux__)
     char *executable = g_file_read_link ("/proc/self/exe", &error);
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    /*
+     * seafile.sh starts the process using abs path
+     */ 
+    char executable[_POSIX_PATH_MAX];
+    memset(executable, 0, _POSIX_PATH_MAX);
+    char * rc = realpath(command_name, executable);
+    if (!rc) {
+        seaf_warning ("failed to readpath: %s\n", executable);
+	return;
+    }
+#endif
     char *tmp = NULL;
     if (error != NULL) {
         seaf_warning ("failed to readlink: %s\n", error->message);
@@ -287,7 +313,9 @@
 
     topdir = g_path_get_dirname (installpath);
 
+#if defined(__linux__)
     g_free (executable);
+#endif
     g_free (tmp);
 }
 
@@ -427,12 +455,41 @@
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
-        }
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
+	}
     }
 }
 
@@ -892,6 +949,7 @@
         exit (1);
     }
 
+    command_name = argv[0];
     char *config_dir = DEFAULT_CONFIG_DIR;
     char *seafile_dir = NULL;
     char *logdir = NULL;
