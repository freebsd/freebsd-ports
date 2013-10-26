From 1295f600b3e94e02d8c5181b1b156325619c449f Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:12 +0200
Subject: [PATCH 25/34] patch-src__util__murmurhash3.c

---
 src/util/murmurhash3.c | 3 +--
 1 file changed, 1 insertion(+), 2 deletions(-)

diff --git src/util/murmurhash3.c src/util/murmurhash3.c
index 80e52ed..341505c 100644
--- src/util/murmurhash3.c
+++ src/util/murmurhash3.c
@@ -8,9 +8,8 @@
 
 #include <stdlib.h>
 #include <stdint.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include <string.h>
-#include <byteswap.h>
 
 /* support RHEL5 lack of definitions */
 #ifndef le32toh
-- 
1.8.0

