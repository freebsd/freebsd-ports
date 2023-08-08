--- aclocal.m4.orig	2023-07-27 14:09:54.000000000 -0700
+++ aclocal.m4	2023-07-31 09:20:10.684567000 -0700
@@ -545,7 +545,7 @@
     TRY_WARN_CC_FLAG(-Wno-format-zero-length)
     # Other flags here may not be supported on some versions of
     # gcc that people want to use.
-    for flag in overflow strict-overflow missing-format-attribute missing-prototypes return-type missing-braces parentheses switch unused-function unused-label unused-variable unused-value unknown-pragmas sign-compare newline-eof error=uninitialized no-maybe-uninitialized error=pointer-arith error=int-conversion error=incompatible-pointer-types error=discarded-qualifiers error=implicit-int error=strict-prototypes; do
+    for flag in overflow strict-overflow missing-format-attribute missing-prototypes return-type missing-braces parentheses switch unused-function unused-label unused-variable unused-value unknown-pragmas sign-compare newline-eof error=uninitialized no-maybe-uninitialized error=pointer-arith error=int-conversion error=incompatible-pointer-types error=discarded-qualifiers error=implicit-int; do
       TRY_WARN_CC_FLAG(-W$flag)
     done
     #  old-style-definition? generates many, many warnings
