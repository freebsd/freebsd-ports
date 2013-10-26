From 194aa2e2960a2a67f9c0beb771635b8392e6e337 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 27 Jul 2013 15:25:53 +0200
Subject: [PATCH 34/34] patch-src__lib__idmap__sss_idmap_conv.c

---
 src/lib/idmap/sss_idmap_conv.c | 1 +
 1 file changed, 1 insertion(+)

diff --git src/lib/idmap/sss_idmap_conv.c src/lib/idmap/sss_idmap_conv.c
index a336042..ac07746 100644
--- src/lib/idmap/sss_idmap_conv.c
+++ src/lib/idmap/sss_idmap_conv.c
@@ -26,6 +26,7 @@
 #include <stdio.h>
 #include <errno.h>
 #include <ctype.h>
+#include <sys/endian.h>
 
 #include "lib/idmap/sss_idmap.h"
 #include "lib/idmap/sss_idmap_private.h"
-- 
1.8.0

