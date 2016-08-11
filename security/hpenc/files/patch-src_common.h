--- src/common.h.orig	2014-10-21 15:58:03 UTC
+++ src/common.h
@@ -28,7 +28,7 @@
 // Ugly, ugly hack
 #if defined(__clang__) && \
 	(__STDC_VERSION__ >= 201112L || __cplusplus >= 201103L) && \
-	!defined(__CLANG_MAX_ALIGN_T_DEFINED)
+	!defined(__CLANG_MAX_ALIGN_T_DEFINED) && !defined(_LIBCPP_STDDEF_H)
 typedef struct {
 	long long __clang_max_align_nonce1
 	__attribute__((__aligned__(__alignof__(long long))));
