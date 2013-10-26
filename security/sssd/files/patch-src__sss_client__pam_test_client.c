From d15b99c87c08f17eef814f431a4a58ed4a3ba9b6 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 20/34] patch-src__sss_client__pam_test_client.c

---
 src/sss_client/pam_test_client.c | 5 +++--
 1 file changed, 3 insertions(+), 2 deletions(-)

diff --git src/sss_client/pam_test_client.c src/sss_client/pam_test_client.c
index ef424e7..d8cf36c 100644
--- src/sss_client/pam_test_client.c
+++ src/sss_client/pam_test_client.c
@@ -24,12 +24,13 @@
 
 #include <stdio.h>
 #include <unistd.h>
+#include <string.h>
 
 #include <security/pam_appl.h>
-#include <security/pam_misc.h>
+#include <security/openpam.h>
 
 static struct pam_conv conv = {
-    misc_conv,
+    openpam_ttyconv,
     NULL
 };
 
-- 
1.8.0

