--- src/subshell.c.orig	Tue Jul 15 20:36:24 2003
+++ src/subshell.c	Tue Jul 15 20:36:56 2003
@@ -1166,6 +1166,8 @@
 #elif IS_AIX
     strcpy (pty_name, "/dev/ptc");
     pty_master = open (pty_name, O_RDWR);
+#elif defined(__FreeBSD__)
+    pty_master = posix_openpt(O_RDWR);
 #else
     strcpy (pty_name, "/dev/ptmx");
     pty_master = open (pty_name, O_RDWR);
