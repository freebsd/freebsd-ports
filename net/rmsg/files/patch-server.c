--- server.c	Tue Jun  4 21:40:19 2002
+++ server.c	Tue Jun  4 21:42:56 2002
@@ -146,7 +146,7 @@
 {
      int child, pid, fd;
      unsigned int retval = 0;
-#if defined(HPUX) || defined(SVR4)
+#if defined(HPUX) || defined(SVR4) || defined(BSD)
      int status;
 #else
      union wait status;
@@ -202,6 +202,9 @@
 #if defined(HPUX) || defined(SVR4)
           if (status & 0xff) retval = -1;
           else retval = ((status & 0xffff) >> 8);
+#elif defined(BSD)
+          if (WIFSIGNALED(status)) retval = -1;
+          else retval = WEXITSTATUS(status);
 #else
           if (status.w_termsig) retval = -1;       /* ended in signal */
           else retval = status.w_retcode;
