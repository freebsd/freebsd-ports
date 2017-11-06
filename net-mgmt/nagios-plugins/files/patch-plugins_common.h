From 930ede8378245eb6bd31eaf1d9103f027df0f7a0 Mon Sep 17 00:00:00 2001
From: Bernard Spil <brnrd@FreeBSD.org>
Date: Sun, 5 Nov 2017 10:43:56 +0100
Subject: [PATCH] plugins/common.h: Set default MySQL port

As of MariaDB 10.2 the headers for client no longer set the
default MySQL port. Patch fixes this for any version of MariaDB
or MySQL into the future.

See also: https://bugs.freebsd.org/223387
--- plugins/common.h.orig	2017-01-19 16:01:31 UTC
+++ plugins/common.h
@@ -168,6 +168,11 @@
 #  endif
 #endif
 
+/* MariaDB 10.2 client does not set MYSQL_PORT */
+#ifndef MYSQL_PORT
+#  define MYSQL_PORT 3306
+#endif
+
 /*
  *
  * Standard Values
