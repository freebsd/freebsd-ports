--- cargo-crates/luajit-src-210.1.3+restyfe08842/luajit2/src/lj_prng.c.orig	2021-07-11 17:23:58 UTC
+++ cargo-crates/luajit-src-210.1.3+restyfe08842/luajit2/src/lj_prng.c
@@ -116,7 +116,7 @@ static PRGR libfunc_rgr;
 #define LJ_TARGET_HAS_GETENTROPY	1
 #endif
 #elif LJ_TARGET_BSD || LJ_TARGET_SOLARIS || LJ_TARGET_CYGWIN
-#define LJ_TARGET_HAS_GETENTROPY	1
+#define LJ_TARGET_HAS_GETENTROPY	0
 #endif
 
 #if LJ_TARGET_HAS_GETENTROPY
