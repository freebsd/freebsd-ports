--- gpgme_n.c.orig	Mon Dec 20 21:38:14 2004
+++ gpgme_n.c	Mon Sep 29 21:35:59 2003
@@ -34,7 +34,7 @@
    this purpose.  */
 
 #include "ruby.h"
-#include "gpgme.h"
+#include "gpgme03/gpgme.h"
 
 /* StringValuePtr is not available in 1.6. */
 #ifndef StringValuePtr
