--- gl/stdbool.in.h.orig	2011-12-16 17:10:10 UTC
+++ gl/stdbool.in.h
@@ -105,11 +105,6 @@ typedef bool _Bool;
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
