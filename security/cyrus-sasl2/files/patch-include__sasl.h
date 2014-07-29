From 67a188693796a14e3a76ac603104807fbbfddfc4 Mon Sep 17 00:00:00 2001
From: Ken Murchison <murch@andrew.cmu.edu>
Date: Thu, 20 Dec 2012 23:14:50 +0000
Subject: sasl.h: #include <stddef.h> for size_t on NetBSD

---
(limited to 'include/sasl.h')

diff --git a/include/sasl.h b/include/sasl.h
index fef4d51..8b8a63f 100755
--- include/sasl.h
+++ include/sasl.h
@@ -121,6 +121,8 @@
 #ifndef SASL_H
 #define SASL_H 1
 
+#include <stddef.h>  /* For size_t */
+
 /* Keep in sync with win32/common.mak */
 #define SASL_VERSION_MAJOR 2
 #define SASL_VERSION_MINOR 1
--
cgit v0.9.0.2
