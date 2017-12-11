From 9f74e09373f3be7b77f510ef8b0ae2c887f7b325 Mon Sep 17 00:00:00 2001
From: Natanael Copa <ncopa@alpinelinux.org>
Date: Tue, 4 Oct 2016 14:35:33 +0200
Subject: [PATCH] [280] Fix build with libressl

Closes #280

Fix building with libressl which broke in commit fff741613 (Support for
openssl 1.1.0).

Bug: #280

Signed-off-by: Natanael Copa <ncopa@alpinelinux.org>
--- lib/mosquitto_internal.h.orig	2017-07-10 22:46:01 UTC
+++ lib/mosquitto_internal.h
@@ -25,6 +25,9 @@ Contributors:
 
 #ifdef WITH_TLS
 #  include <openssl/ssl.h>
+#  if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#    define HAVE_OPENSSL_OPAQUE_STRUCTS
+#  endif
 #else
 #  include <time.h>
 #endif
