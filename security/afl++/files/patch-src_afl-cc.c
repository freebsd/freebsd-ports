--- src/afl-cc.c.orig	2021-10-09 18:30:48 UTC
+++ src/afl-cc.c
@@ -395,7 +395,7 @@ static void edit_params(u32 argc, char **argv, char **
           snprintf(llvm_fullpath, sizeof(llvm_fullpath), "%s/clang",
                    LLVM_BINDIR);
         else
-          snprintf(llvm_fullpath, sizeof(llvm_fullpath), CLANGPP_BIN);
+          snprintf(llvm_fullpath, sizeof(llvm_fullpath), CLANG_BIN);
         alt_cc = llvm_fullpath;
 
       }
