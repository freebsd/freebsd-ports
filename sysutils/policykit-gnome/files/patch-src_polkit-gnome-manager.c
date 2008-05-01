--- src/polkit-gnome-manager.c.orig	2008-04-16 21:44:19.000000000 -0400
+++ src/polkit-gnome-manager.c	2008-04-19 01:17:11.000000000 -0400
@@ -364,7 +364,11 @@ get_exe_for_pid (pid_t pid)
 
         result = NULL;
 
+#ifdef __FreeBSD__
+        snprintf (proc_name, sizeof (proc_name), "/proc/%d/file", pid);
+#else
         snprintf (proc_name, sizeof (proc_name), "/proc/%d/exe", pid);
+#endif
         len = readlink (proc_name, buf, sizeof (buf) - 1);
         if (len == -1) {
                 goto out;
