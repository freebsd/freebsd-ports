--- src/subshell.c.orig	Sat Jan 25 03:37:28 2003
+++ src/subshell.c	Tue Jun 15 03:15:09 2004
@@ -710,7 +710,9 @@
     }
 
     g_free (subshell_prompt);
+    g_free (pty_buffer);
     subshell_prompt = NULL;
+    pty_buffer = NULL;
 
     return quit;
 }
@@ -1166,6 +1168,8 @@
 #elif IS_AIX
     strcpy (pty_name, "/dev/ptc");
     pty_master = open (pty_name, O_RDWR);
+#elif defined(__FreeBSD__)
+    pty_master = posix_openpt(O_RDWR);
 #else
     strcpy (pty_name, "/dev/ptmx");
     pty_master = open (pty_name, O_RDWR);
