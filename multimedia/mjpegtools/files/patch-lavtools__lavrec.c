--- lavtools/lavrec.c.orig	2021-09-05 06:14:13 UTC
+++ lavtools/lavrec.c
@@ -196,7 +196,9 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <termios.h>
+#ifdef __linux
 #include <sys/fsuid.h>
+#endif
 #include <signal.h>
 #include <fcntl.h>
 #include <errno.h>
@@ -1149,6 +1151,7 @@ int main(int argc, char **argv)
   sigset_t sigmask;
   pthread_t input_thread;
 
+#ifdef __linux
   /* no root please (only during audio setup) */
   if (getuid() != geteuid())
   {
@@ -1159,6 +1162,7 @@ int main(int argc, char **argv)
       return 0;
     }
   }
+#endif
 
   info = lavrec_malloc();
   info->state_changed = statechanged;
