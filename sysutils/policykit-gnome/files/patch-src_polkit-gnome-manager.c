--- src/polkit-gnome-manager.c.orig	2008-03-28 13:00:47.000000000 -0400
+++ src/polkit-gnome-manager.c	2008-03-28 13:01:56.000000000 -0400
@@ -363,7 +363,11 @@ get_exe_for_pid (pid_t pid)
 
         result = NULL;
 
+#ifdef __FreeBSD__
+        snprintf (proc_name, sizeof (proc_name), "/proc/%d/file", pid);
+#else
         snprintf (proc_name, sizeof (proc_name), "/proc/%d/exe", pid);
+#endif
         len = readlink (proc_name, buf, sizeof (buf) - 1);
         if (len == -1) {
                 goto out;
