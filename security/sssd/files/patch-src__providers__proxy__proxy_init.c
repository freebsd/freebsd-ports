From 6d9c90d8cd4dedbc0f3642e9fc8287eb34504e1a Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 13/34] patch-src__providers__proxy__proxy_init.c

---
 src/providers/proxy/proxy_init.c | 22 +++++++++++-----------
 1 file changed, 11 insertions(+), 11 deletions(-)

diff --git src/providers/proxy/proxy_init.c src/providers/proxy/proxy_init.c
index de4d7b6..99b464a 100644
--- src/providers/proxy/proxy_init.c
+++ src/providers/proxy/proxy_init.c
@@ -123,7 +123,7 @@ int sssm_proxy_id_init(struct be_ctx *bectx,
     if (!ctx->handle) {
         DEBUG(0, ("Unable to load %s module with path, error: %s\n",
                   libpath, dlerror()));
-        ret = ELIBACC;
+        ret = ENOENT;
         goto done;
     }
 
@@ -131,7 +131,7 @@ int sssm_proxy_id_init(struct be_ctx *bectx,
                                       libname);
     if (!ctx->ops.getpwnam_r) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
@@ -139,14 +139,14 @@ int sssm_proxy_id_init(struct be_ctx *bectx,
                                       libname);
     if (!ctx->ops.getpwuid_r) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
     ctx->ops.setpwent = proxy_dlsym(ctx->handle, "_nss_%s_setpwent", libname);
     if (!ctx->ops.setpwent) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
@@ -154,14 +154,14 @@ int sssm_proxy_id_init(struct be_ctx *bectx,
                                       libname);
     if (!ctx->ops.getpwent_r) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
     ctx->ops.endpwent = proxy_dlsym(ctx->handle, "_nss_%s_endpwent", libname);
     if (!ctx->ops.endpwent) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
@@ -169,7 +169,7 @@ int sssm_proxy_id_init(struct be_ctx *bectx,
                                       libname);
     if (!ctx->ops.getgrnam_r) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
@@ -177,14 +177,14 @@ int sssm_proxy_id_init(struct be_ctx *bectx,
                                       libname);
     if (!ctx->ops.getgrgid_r) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
     ctx->ops.setgrent = proxy_dlsym(ctx->handle, "_nss_%s_setgrent", libname);
     if (!ctx->ops.setgrent) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
@@ -192,14 +192,14 @@ int sssm_proxy_id_init(struct be_ctx *bectx,
                                       libname);
     if (!ctx->ops.getgrent_r) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
     ctx->ops.endgrent = proxy_dlsym(ctx->handle, "_nss_%s_endgrent", libname);
     if (!ctx->ops.endgrent) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
-- 
1.8.0

