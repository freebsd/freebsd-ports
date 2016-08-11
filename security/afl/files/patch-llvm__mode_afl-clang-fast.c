--- llvm_mode/afl-clang-fast.c.orig	2016-06-07 18:07:43 UTC
+++ llvm_mode/afl-clang-fast.c
@@ -106,10 +106,10 @@ static void edit_params(u32 argc, char**
 
   if (!strcmp(name, "afl-clang-fast++")) {
     u8* alt_cxx = getenv("AFL_CXX");
-    cc_params[0] = alt_cxx ? alt_cxx : (u8*)"clang++";
+    cc_params[0] = alt_cxx ? alt_cxx : (u8*)"clang++37";
   } else {
     u8* alt_cc = getenv("AFL_CC");
-    cc_params[0] = alt_cc ? alt_cc : (u8*)"clang";
+    cc_params[0] = alt_cc ? alt_cc : (u8*)"clang37";
   }
 
   /* There are two ways to compile afl-clang-fast. In the traditional mode, we
