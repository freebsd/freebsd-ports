--- kbx/keybox-blob.c.orig	Mon Jul 22 11:26:51 2002
+++ kbx/keybox-blob.c	Wed Jan 29 17:00:14 2003
@@ -119,8 +119,8 @@
 #include <ksba.h>
 #endif
 
+#include "../jnlib/types.h"
 #include "keybox-defs.h"
-
 
 /* special values of the signature status */
 #define SF_NONE(a)  ( !(a) )
