From 64a507ad6b3c7e8455c67b452160b9e4211fd872 Mon Sep 17 00:00:00 2001
From: "Jason A. Donenfeld" <Jason@zx2c4.com>
Date: Mon, 7 Jun 2021 11:50:20 +0200
Subject: compat: taskqueue draining was backported to stable/13

Since 407b687dfef ("Make sure all tasklets are drained before unloading
the LinuxKPI. Else use-after-free may happen."), stable/13 now has the
taskqueue API that we need.

Reported-by: Herbert J. Skuhra <herbert@gojira.at>
Signed-off-by: Jason A. Donenfeld <Jason@zx2c4.com>
--- compat.h.orig	2021-06-06 13:35:25 UTC
+++ compat.h
@@ -8,7 +8,7 @@
 
 #include <sys/param.h>
 
-#if __FreeBSD_version < 1400000
+#if __FreeBSD_version < 1300507
 #include <sys/smp.h>
 #include <sys/gtaskqueue.h>
 
