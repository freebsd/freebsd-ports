--- async/daemonize.C.orig	2002-10-10 13:20:16.000000000 -0400
+++ async/daemonize.C	2007-09-15 17:00:51.000000000 -0400
@@ -49,18 +49,19 @@
 	      const str &logfile, int flags, mode_t mode)
 {
 #ifdef PATH_LOGGER
-  char *av[] = { PATH_LOGGER, "-p", NULL, "-t", NULL, NULL, NULL };
+  char *av[] = { const_cast<char *> (PATH_LOGGER), const_cast<char *> ("-p"),
+		 NULL, const_cast<char *> ("-t"), NULL, NULL, NULL };
   av[2] = const_cast<char *> (priority.cstr ());
   
   if (line)
     av[5] = const_cast<char *> (line.cstr ());
   else
-    av[5] = "log started";
+    av[5] = const_cast<char *> ("log started");
 
   if (tag)
     av[4] = const_cast<char *> (tag.cstr ());
   else 
-    av[4] = "";
+    av[4] = const_cast<char *> ("");
 
   pid_t pid;
   int status;
@@ -93,9 +94,9 @@
 start_logger ()
 {
 #ifdef PATH_LOGGER
-  char *av[] = { PATH_LOGGER, "-p",
+  char *av[] = { const_cast<char *> (PATH_LOGGER), const_cast<char *> ("-p"),
 		 const_cast<char *> (syslog_priority.cstr ()),
-		 "-t", "", NULL};
+		 const_cast<char *> ("-t"), const_cast<char *> (""), NULL};
   int fds[2];
 
   close (0);
