--- src/ia32/code-stubs-ia32.cc.orig	2013-05-01 12:56:29 UTC
+++ src/ia32/code-stubs-ia32.cc
@@ -5650,7 +5650,7 @@ void StringCharFromCodeGenerator::Genera
   ASSERT(IsPowerOf2(String::kMaxOneByteCharCode + 1));
   __ test(code_,
           Immediate(kSmiTagMask |
-                    ((~String::kMaxOneByteCharCode) << kSmiTagSize)));
+                    ((~String::kMaxOneByteCharCodeU) << kSmiTagSize)));
   __ j(not_zero, &slow_case_);
 
   Factory* factory = masm->isolate()->factory();
