--- gl/stdbool.in.h.orig	2010-04-19 14:33:17.000000000 +0800
+++ gl/stdbool.in.h	2010-04-19 14:36:05.000000000 +0800
@@ -102,11 +102,6 @@
         The only benefit of the enum, debuggability, is not important
         with these compilers.  So use 'signed char' and no enum.  */
 #  define _Bool signed char
-# else
-   /* With this compiler, trust the _Bool type if the compiler has it.  */
-#  if !@HAVE__BOOL@
-typedef enum { _Bool_must_promote_to_int = -1, false = 0, true = 1 } _Bool;
-#  endif
 # endif
 #endif
 #define bool _Bool
