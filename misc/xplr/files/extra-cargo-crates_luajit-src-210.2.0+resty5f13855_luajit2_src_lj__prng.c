--- cargo-crates/luajit-src-210.2.0+resty5f13855/luajit2/src/lj_prng.c.orig	2021-08-01 16:29:04 UTC
+++ cargo-crates/luajit-src-210.2.0+resty5f13855/luajit2/src/lj_prng.c
@@ -122,7 +122,7 @@ static PRGR libfunc_rgr;
 #define LJ_TARGET_HAS_GETENTROPY	1
 #endif
 #elif (LJ_TARGET_BSD && !defined(__NetBSD__)) || LJ_TARGET_SOLARIS || LJ_TARGET_CYGWIN
-#define LJ_TARGET_HAS_GETENTROPY	1
+#define LJ_TARGET_HAS_GETENTROPY	0
 #endif
 
 #if LJ_TARGET_HAS_GETENTROPY
