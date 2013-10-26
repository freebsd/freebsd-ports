From f6d110d1f78a78ee957f7fce975d09fc698e0949 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 05/34] patch-src__providers__data_provider_be.c

---
 src/providers/data_provider_be.c | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git src/providers/data_provider_be.c src/providers/data_provider_be.c
index 33590ae..1a25959 100644
--- src/providers/data_provider_be.c
+++ src/providers/data_provider_be.c
@@ -2316,7 +2316,7 @@ static int load_backend_module(struct be_ctx *ctx,
         if (!handle) {
             DEBUG(0, ("Unable to load %s module with path (%s), error: %s\n",
                       mod_name, path, dlerror()));
-            ret = ELIBACC;
+            ret = ENOENT;
             goto done;
         }
 
@@ -2336,7 +2336,7 @@ static int load_backend_module(struct be_ctx *ctx,
         } else {
             DEBUG(0, ("Unable to load init fn %s from module %s, error: %s\n",
                       mod_init_fn_name, mod_name, dlerror()));
-            ret = ELIBBAD;
+            ret = ENOENT;
         }
         goto done;
     }
-- 
1.8.0

