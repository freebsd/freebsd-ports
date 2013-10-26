From 7223f18bd8ea22ed801a115934a2fe8dc0c0cdb8 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 27 Jul 2013 15:03:49 +0200
Subject: [PATCH 32/34] patch-src__providers__ad__ad_common.c

---
 src/providers/ad/ad_common.c | 6 +++---
 1 file changed, 3 insertions(+), 3 deletions(-)

diff --git src/providers/ad/ad_common.c src/providers/ad/ad_common.c
index 8600dab..d628385 100644
--- src/providers/ad/ad_common.c
+++ src/providers/ad/ad_common.c
@@ -38,7 +38,7 @@ ad_get_common_options(TALLOC_CTX *mem_ctx,
     char *server;
     char *realm;
     char *ad_hostname;
-    char hostname[HOST_NAME_MAX + 1];
+    char hostname[_POSIX_HOST_NAME_MAX + 1];
 
     opts = talloc_zero(mem_ctx, struct ad_options);
     if (!opts) return ENOMEM;
@@ -75,7 +75,7 @@ ad_get_common_options(TALLOC_CTX *mem_ctx,
      */
     ad_hostname = dp_opt_get_string(opts->basic, AD_HOSTNAME);
     if (ad_hostname == NULL) {
-        gret = gethostname(hostname, HOST_NAME_MAX);
+        gret = gethostname(hostname, _POSIX_HOST_NAME_MAX);
         if (gret != 0) {
             ret = errno;
             DEBUG(SSSDBG_FATAL_FAILURE,
@@ -83,7 +83,7 @@ ad_get_common_options(TALLOC_CTX *mem_ctx,
                    strerror(ret)));
             goto done;
         }
-        hostname[HOST_NAME_MAX] = '\0';
+        hostname[_POSIX_HOST_NAME_MAX] = '\0';
         DEBUG(SSSDBG_CONF_SETTINGS,
               ("Setting ad_hostname to [%s].\n", hostname));
         ret = dp_opt_set_string(opts->basic, AD_HOSTNAME, hostname);
-- 
1.8.0

