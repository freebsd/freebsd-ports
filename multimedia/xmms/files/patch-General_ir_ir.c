--- General/ir/ir.c.orig	2005-05-21 18:04:04 UTC
+++ General/ir/ir.c
@@ -16,7 +16,7 @@
 #include "ir.h"
 
 /* Important stuff to know */
-static gboolean keepGoing = FALSE;
+static volatile gboolean keepGoing = FALSE;
 
 /* The thread handle */
 static pthread_t irapp_thread;
