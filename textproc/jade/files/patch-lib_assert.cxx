--- lib/assert.cxx.orig	1998-10-07 05:15:50 UTC
+++ lib/assert.cxx
@@ -6,7 +6,7 @@
 #include "macros.h"
 
 #ifdef __GNUG__
-void exit (int __status) __THROW __attribute__ ((__noreturn__));
+//void exit (int) __attribute__ ((__noreturn__));
 #endif
 
 #ifdef SP_NAMESPACE
