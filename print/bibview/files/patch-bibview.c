--- bibview.c.orig	Fri Apr 21 10:49:15 1995
+++ bibview.c	Sun Apr 19 07:33:25 1998
@@ -170,9 +170,9 @@
 /* fallback resources */
 static char *fallback_resources[] = {
 #ifdef GERMAN
-   #include "fb_ger.h"
+#include "fb_ger.h"
 #else
-   #include "fb_res.h"
+#include "fb_res.h"
 #endif
    NULL
 };
@@ -824,7 +824,7 @@
 
    /* install signal handler */
    for (i = 1; i<= 15; i++)
-      signal(i, signalHandler); 
+      signal(i, (sig_t)signalHandler); 
 
    /* install Xtoolkit handlers */
    XtSetWarningHandler((XtErrorHandler)Xt_warningHandler);
@@ -891,7 +891,7 @@
 static void
 signalHandler (int s, int code)
 {  
-  signal(s, signalHandler); 
+  signal(s, (sig_t)signalHandler); 
 }
 
 
