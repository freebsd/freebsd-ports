From 18614fe436d525826e260e7a0e8334c41bd2ce37 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 03/34] patch-src__confdb__confdb.c

---
 src/confdb/confdb.c | 5 +++++
 1 file changed, 5 insertions(+)

diff --git src/confdb/confdb.c src/confdb/confdb.c
index d70dc36..9ee1f8c 100644
--- src/confdb/confdb.c
+++ src/confdb/confdb.c
@@ -28,6 +28,11 @@
 #include "util/strtonum.h"
 #include "db/sysdb.h"
 
+char *strchrnul(const char *s, int ch) {
+       char *ret = strchr(s, ch);
+       return ret == NULL ? ((char *)s) + strlen(s) : ret;
+}
+
 #define CONFDB_ZERO_CHECK_OR_JUMP(var, ret, err, label) do { \
     if (!var) { \
         ret = err; \
-- 
1.8.0

