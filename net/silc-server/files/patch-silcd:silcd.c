--- silcd/silcd.c.orig	Wed Nov  7 18:33:19 2001
+++ silcd/silcd.c	Sat Nov 10 22:35:36 2001
@@ -43,6 +43,7 @@ static struct option long_opts[] = 
   { "config-file", 1, NULL, 'f' },
   { "debug", 1, NULL, 'd' },
   { "help", 0, NULL, 'h' },
+  { "no-daemon", 0, NULL, 'n' },
   { "version", 0, NULL,'V' },
 
   /* Key management options */
@@ -70,8 +71,9 @@ Usage: silcd [options]\n\
 \n\
   Generic Options:\n\
   -f  --config-file=FILE        Alternate configuration file\n\
-  -d  --debug=string            Enable debugging (no daemon)\n\
+  -d  --debug=string            Enable debugging (Implies --no-daemon)\n\
   -h  --help                    Display this message\n\
+  -n  --no-daemon		Dont fork\n\
   -V  --version                 Display version\n\
 \n\
   Key Management Options:\n\
@@ -99,6 +101,7 @@ int main(int argc, char **argv)
 {
   int ret;
   int opt, option_index;
+  int daemon = TRUE;
   char *config_file = NULL;
   SilcServer silcd;
   struct sigaction sa;
@@ -108,7 +111,7 @@ int main(int argc, char **argv)
 
   /* Parse command line arguments */
   if (argc > 1) {
-    while ((opt = getopt_long(argc, argv, "cf:d:hVC:",
+    while ((opt = getopt_long(argc, argv, "cf:d:hnVC:",
 			      long_opts, &option_index)) != EOF) {
       switch(opt) 
 	{
@@ -130,6 +133,9 @@ int main(int argc, char **argv)
 	case 'f':
 	  config_file = strdup(optarg);
 	  break;
+	case 'n':
+	  daemon = FALSE;
+	  break;
 
 	  /*
 	   * Key management options
@@ -195,9 +201,8 @@ int main(int argc, char **argv)
   sigemptyset(&sa.sa_mask);
   sigaction(SIGPIPE, &sa, NULL);
 
-  if (silc_debug == FALSE)
-    /* Before running the server, fork to background and set
-       both user and group no non-root */    
+  if ((silc_debug == FALSE) && daemon)
+    /* Before running the server, fork to background. */    
     silc_server_daemonise(silcd);
 
   /* Set /var/run/silcd.pid */
@@ -206,6 +211,9 @@ int main(int argc, char **argv)
   snprintf(pid, sizeof(pid) - 1, "%d\n", getpid());
   silc_file_writefile(SILC_SERVER_PID_FILE, pid, strlen(pid));
   
+  /* Drop root. */
+  silc_server_drop(silcd);
+
   /* Run the server. When this returns the server has been stopped
      and we will exit. */
   silc_server_run(silcd);
