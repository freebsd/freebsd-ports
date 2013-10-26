From acb17ace2b204146e4b821fd7d5e27de5d8ee588 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 07/34] patch-src__providers__ipa__ipa_common.c

---
 src/providers/ipa/ipa_common.c | 6 +++---
 1 file changed, 3 insertions(+), 3 deletions(-)

diff --git src/providers/ipa/ipa_common.c src/providers/ipa/ipa_common.c
index eb384a1..d7d8052 100644
--- src/providers/ipa/ipa_common.c
+++ src/providers/ipa/ipa_common.c
@@ -47,7 +47,7 @@ int ipa_get_options(TALLOC_CTX *memctx,
     char *realm;
     char *ipa_hostname;
     int ret;
-    char hostname[HOST_NAME_MAX + 1];
+    char hostname[_POSIX_HOST_NAME_MAX + 1];
 
     opts = talloc_zero(memctx, struct ipa_options);
     if (!opts) return ENOMEM;
@@ -76,14 +76,14 @@ int ipa_get_options(TALLOC_CTX *memctx,
 
     ipa_hostname = dp_opt_get_string(opts->basic, IPA_HOSTNAME);
     if (ipa_hostname == NULL) {
-        ret = gethostname(hostname, HOST_NAME_MAX);
+        ret = gethostname(hostname, _POSIX_HOST_NAME_MAX);
         if (ret != EOK) {
             DEBUG(1, ("gethostname failed [%d][%s].\n", errno,
                       strerror(errno)));
             ret = errno;
             goto done;
         }
-        hostname[HOST_NAME_MAX] = '\0';
+        hostname[_POSIX_HOST_NAME_MAX] = '\0';
         DEBUG(9, ("Setting ipa_hostname to [%s].\n", hostname));
         ret = dp_opt_set_string(opts->basic, IPA_HOSTNAME, hostname);
         if (ret != EOK) {
-- 
1.8.0

