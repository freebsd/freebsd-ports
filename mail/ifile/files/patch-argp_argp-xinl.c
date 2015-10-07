--- argp/argp-xinl.c.orig	2006-05-22 16:49:22 UTC
+++ argp/argp-xinl.c
@@ -24,7 +24,8 @@
 
 #define ARGP_EI
 #undef __OPTIMIZE__
-#define __OPTIMIZE__
+#define __OPTIMIZE__	0
+#define	__OPTIMIZE_INLINE__
 #include "argp.h"
 
 /* Add weak aliases.  */
