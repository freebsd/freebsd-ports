--- egg/tests/test-dh.c.orig	Mon Sep  5 07:16:09 2011
+++ egg/tests/test-dh.c	Sat Oct 27 14:36:16 2012
@@ -35,7 +35,7 @@
 #include <stdio.h>
 #include <string.h>
 
-EGG_SECURE_GLIB_DEFINITIONS ();
+EGG_SECURE_DEFINE_GLIB_GLOBALS ();
 
 static void
 test_dh_perform (void)
