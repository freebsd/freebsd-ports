--- General/ir/ir.c.orig	Mon Mar  5 14:17:44 2001
+++ General/ir/ir.c	Sat Dec 16 15:41:23 2006
@@ -16,7 +16,7 @@
 #include "ir.h"
 
 /* Important stuff to know */
-static gboolean keepGoing = FALSE;
+static volatile gboolean keepGoing = FALSE;
 
 /* The thread handle */
 static pthread_t irapp_thread;
