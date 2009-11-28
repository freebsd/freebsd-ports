--- tools/ck-log-system-start.c.orig	2009-09-14 20:08:10.000000000 -0400
+++ tools/ck-log-system-start.c	2009-09-26 01:35:37.000000000 -0400
@@ -26,6 +26,9 @@
 #include <unistd.h>
 #include <errno.h>
 #include <fcntl.h>
+#ifdef __FreeBSD__
+#include <kenv.h>
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/utsname.h>
@@ -41,7 +44,9 @@
 
 #define DEFAULT_LOG_FILENAME LOCALSTATEDIR "/log/ConsoleKit/history"
 
+#ifdef __linux__
 #define LINUX_KERNEL_CMDLINE "/proc/cmdline"
+#endif
 
 /* Adapted from auditd auditd-event.c */
 static gboolean
@@ -162,6 +167,7 @@ write_log_for_event (CkLogEvent *event)
 static char *
 get_boot_arguments (void)
 {
+#if defined(__linux__)
         char *contents;
         gboolean res;
 
@@ -178,6 +184,29 @@ get_boot_arguments (void)
         }
 
         return contents;
+#elif defined(__FreeBSD__)
+        char kern_name[1024], root[1024], mopts[1024];
+        char *options;
+
+        options = NULL;
+        if (kenv(KENV_GET, "kernelname", kern_name, sizeof (kern_name)) == -1) {
+                return options;
+        }
+
+        if (kenv(KENV_GET, "vfs.root.mountfrom.options", mopts, sizeof (mopts)) == -1) {
+                g_strlcpy (mopts, "ro", sizeof (mopts));
+        }
+
+        if (kenv(KENV_GET, "vfs.root.mountfrom", root, sizeof (root)) == -1) {
+                g_strlcpy (root, "/", sizeof (root));
+        }
+
+        options = g_strdup_printf ("%s %s root=%s", mopts, kern_name, root);
+
+        return options;
+#else
+        return NULL;
+#endif
 }
 
 int
