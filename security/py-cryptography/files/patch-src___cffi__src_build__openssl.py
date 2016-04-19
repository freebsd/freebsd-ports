Use upstream post-1.3.1 patch for LibreSSL

From 1e88d741f6e15d9170466a08dfe85f28b12c7623 Mon Sep 17 00:00:00 2001
From: Paul Kehrer <paul.l.kehrer@gmail.com>
Date: Mon, 28 Mar 2016 22:00:00 -0400
Subject: [PATCH] fix libressl breakage reported in #2858

---
 src/_cffi_src/build_openssl.py | 9 ++++++++-
 1 file changed, 8 insertions(+), 1 deletion(-)

diff --git a/src/_cffi_src/build_openssl.py b/src/_cffi_src/build_openssl.py
index 2ff28d7..3f92529 100644
--- src/_cffi_src/build_openssl.py.orig
+++ src/_cffi_src/build_openssl.py
@@ -38,8 +38,15 @@ def _osx_libraries(build_static):
 
 
 _PRE_INCLUDE = """
+#include <openssl/opensslv.h>
+/*
+    LibreSSL removed e_os2.h from the public headers so we'll only include it
+    if we're using vanilla OpenSSL.
+*/
+#if !defined(LIBRESSL_VERSION_NUMBER)
 #include <openssl/e_os2.h>
-#if defined(OPENSSL_SYS_WINDOWS)
+#endif
+#if defined(OPENSSL_SYS_WINDOWS) || defined(_WIN32)
 #include <windows.h>
 #endif
 """
