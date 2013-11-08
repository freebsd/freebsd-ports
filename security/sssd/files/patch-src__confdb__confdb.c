From 756e37d0ef957b15d782d5dd87d24e9359541931 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Wed, 6 Nov 2013 22:01:20 +0100
Subject: [PATCH 02/25] patch-src__confdb__confdb.c

---
 src/confdb/confdb.c | 5 +++++
 1 file changed, 5 insertions(+)

diff --git src/confdb/confdb.c src/confdb/confdb.c
index 72c74fe..78b69b8 100644
--- src/confdb/confdb.c
+++ src/confdb/confdb.c
@@ -28,6 +28,11 @@
 #include "util/strtonum.h"
 #include "db/sysdb.h"
 
+char *strchrnul(const char *s, int ch) {
+       char *ret = strchr(s, ch);
+       return ret == NULL ? discard_const_p(char, s) + strlen(s) : ret;
+}
+
 #define CONFDB_ZERO_CHECK_OR_JUMP(var, ret, err, label) do { \
     if (!var) { \
         ret = err; \
-- 
1.8.0

