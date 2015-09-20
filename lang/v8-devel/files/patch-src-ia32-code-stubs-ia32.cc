--- src/ia32/code-stubs-ia32.cc.orig	2014-06-03 08:52:11 UTC
+++ src/ia32/code-stubs-ia32.cc
@@ -3143,7 +3143,7 @@ void StringCharFromCodeGenerator::Genera
   ASSERT(IsPowerOf2(String::kMaxOneByteCharCode + 1));
   __ test(code_,
           Immediate(kSmiTagMask |
-                    ((~String::kMaxOneByteCharCode) << kSmiTagSize)));
+                    ((~String::kMaxOneByteCharCodeU) << kSmiTagSize)));
   __ j(not_zero, &slow_case_);
 
   Factory* factory = masm->isolate()->factory();
