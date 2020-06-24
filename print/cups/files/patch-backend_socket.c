--- backend/socket.c.orig	2020-04-27 18:04:29 UTC
+++ backend/socket.c
@@ -292,7 +292,6 @@ main(int  argc,				/* I - Number of command-line argum
   */
 
   fprintf(stderr, "DEBUG: Connecting to %s:%d\n", hostname, port);
-  _cupsLangPrintFilter(stderr, "INFO", _("Connecting to printer."));
 
   for (delay = 5;;)
   {
@@ -372,7 +371,6 @@ main(int  argc,				/* I - Number of command-line argum
   }
 
   fputs("STATE: -connecting-to-device\n", stderr);
-  _cupsLangPrintFilter(stderr, "INFO", _("Connected to printer."));
 
   fprintf(stderr, "DEBUG: Connected to %s:%d...\n",
 	  httpAddrString(&(addr->addr), addrname, sizeof(addrname)),
@@ -403,7 +401,7 @@ main(int  argc,				/* I - Number of command-line argum
       tbytes = bytes;
 
     if (print_fd != 0 && tbytes >= 0)
-      _cupsLangPrintFilter(stderr, "INFO", _("Print file sent."));
+      fputs("DEBUG: Print file sent.\n", stderr);
   }
 
   fputs("STATE: +cups-waiting-for-job-completed\n", stderr);
@@ -414,7 +412,7 @@ main(int  argc,				/* I - Number of command-line argum
     * Shutdown the socket and wait for the other end to finish...
     */
 
-    _cupsLangPrintFilter(stderr, "INFO", _("Waiting for printer to finish."));
+    fputs("DEBUG: Waiting for printer to finish.\n", stderr);
 
     shutdown(device_fd, 1);
 
