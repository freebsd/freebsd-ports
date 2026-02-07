--- spreadlogd.c.orig	Tue Jul  3 22:09:48 2001
+++ spreadlogd.c	Sat May 14 12:47:05 2005
@@ -114,9 +114,15 @@
   }
 }
 void daemonize(void) {
+  FILE *fd;
+  char buf[16];
   if(fork()!=0) exit(0);
   setsid();
   if(fork()!=0) exit(0);
+  fd = fopen("/var/run/spreadlogd.pid", "w");
+  sprintf(buf, "%d", getpid());
+  fputs(buf, fd);
+  fclose(fd);
 }
 int getnropen(void) {
   struct rlimit rlim;
@@ -127,9 +133,6 @@
 }
 
 int main(int argc, char **argv) {
-#ifdef SPREAD_VERSION
-  int mver, miver, pver;
-#endif
   char *configfile = default_configfile;
   char *message;
   int getoption, debug = 0;
@@ -137,7 +140,8 @@
   sigset_t ourmask;
 	nr_open = getnropen();
 
-  fdsetsize = getdtablesize();
+  fdsetsize = 512; /* getdtablesize(); ugly fix for freebsd but the select fdset 
+	           is not as big as dtablesize returns so we receive some cores MENO */
   fds = (SpreadConfiguration **)malloc(sizeof(SpreadConfiguration *)*
 				       fdsetsize);
   memset(fds, 0, sizeof(SpreadConfiguration *)*fdsetsize);
@@ -182,7 +186,7 @@
 	    buffsize);
   }
 
-  if(!debug) daemonize();
+  if(!debug) { daemonize(); }
  
   /* Set up HUP signal */
   signalaction.sa_handler = sig_handler;
