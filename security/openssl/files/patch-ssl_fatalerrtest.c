From a4597f079bf2662e06d505538f83b6b610c41c7c Mon Sep 17 00:00:00 2001
From: Matt Caswell <matt@openssl.org>
Date: Thu, 7 Dec 2017 14:40:49 +0000
Subject: [PATCH] Fix initialisation in fatalerrtest

---
 ssl/fatalerrtest.c | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git a/ssl/fatalerrtest.c b/ssl/fatalerrtest.c
index 0288c33fa2e..749bc3697ea 100644
--- ssl/fatalerrtest.c.orig
+++ ssl/fatalerrtest.c
@@ -13,8 +13,8 @@
 
 int main(int argc, char *argv[])
 {
-    SSL_CTX *sctx, *cctx;
-    SSL *sssl, *cssl;
+    SSL_CTX *sctx = NULL, *cctx = NULL;
+    SSL *sssl = NULL, *cssl = NULL;
     const char *msg = "Dummy";
     BIO *err = NULL, *wbio = NULL;
     int ret = 1, len;
From b24e0573c6838e8d726fb16d558c562ce4e8f025 Mon Sep 17 00:00:00 2001
From: Matt Caswell <matt@openssl.org>
Date: Thu, 7 Dec 2017 14:41:21 +0000
Subject: [PATCH] Fix the buffer sizing in the fatalerrtest

Fixes #4865
---
 ssl/fatalerrtest.c | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/ssl/fatalerrtest.c b/ssl/fatalerrtest.c
index 749bc3697ea..f9d66e27b30 100644
--- ssl/fatalerrtest.c.orig
+++ ssl/fatalerrtest.c
@@ -76,7 +76,7 @@ int main(int argc, char *argv[])
     }
 
     /* SSL_read()/SSL_write should fail because of a previous fatal error */
-    if ((len = SSL_read(sssl, buf, sizeof(buf - 1))) > 0) {
+    if ((len = SSL_read(sssl, buf, sizeof(buf) - 1)) > 0) {
         buf[len] = '\0';
         printf("Unexpected success reading data: %s\n", buf);
         goto err;

