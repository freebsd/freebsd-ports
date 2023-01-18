--- cargo-crates/luajit-src-210.4.3+resty8384278/luajit2/src/lj_arch.h.orig	2023-01-17 22:53:47 UTC
+++ cargo-crates/luajit-src-210.4.3+resty8384278/luajit2/src/lj_arch.h
@@ -499,8 +499,14 @@
 #endif
 #endif
 #elif !LJ_TARGET_PS3
+#if __clang__
+#if ((__clang_major__ < 3) || ((__clang_major__ == 3) && __clang_minor__ < 5))
+#error "Need at least Clang 3.5 or newer"
+#endif
+#else
 #if (__GNUC__ < 4) || ((__GNUC__ == 4) && __GNUC_MINOR__ < 3)
 #error "Need at least GCC 4.3 or newer"
+#endif
 #endif
 #endif
 #endif
