--- lib/assert.cxx.orig	Wed Apr 25 12:42:54 2001
+++ lib/assert.cxx	Wed Apr 25 12:43:26 2001
@@ -6,7 +6,7 @@
 #include "macros.h"
 
 #ifdef __GNUG__
-void exit (int __status) __THROW __attribute__ ((__noreturn__));
+//void exit (int) __attribute__ ((__noreturn__));
 #endif
 
 #ifdef SP_NAMESPACE
