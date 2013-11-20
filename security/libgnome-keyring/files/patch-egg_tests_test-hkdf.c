--- egg/tests/test-hkdf.c.orig	Mon Sep  5 07:16:09 2011
+++ egg/tests/test-hkdf.c	Sat Oct 27 14:36:16 2012
@@ -33,7 +33,7 @@
 
 #include <gcrypt.h>
 
-EGG_SECURE_GLIB_DEFINITIONS ();
+EGG_SECURE_DEFINE_GLIB_GLOBALS ();
 
 static void
 test_hkdf_test_case_1 (void)
