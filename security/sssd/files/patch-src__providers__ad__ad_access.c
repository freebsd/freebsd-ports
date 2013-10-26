From 630e5b96040869f6ce24ac1d10bb370e819795e7 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 27 Jul 2013 15:04:27 +0200
Subject: [PATCH 33/34] patch-src__providers__ad__ad_access.c

---
 src/providers/ad/ad_access.c | 1 +
 1 file changed, 1 insertion(+)

diff --git src/providers/ad/ad_access.c src/providers/ad/ad_access.c
index 314cdcf..ca0fb8b 100644
--- src/providers/ad/ad_access.c
+++ src/providers/ad/ad_access.c
@@ -21,6 +21,7 @@
 */
 
 #include <security/pam_modules.h>
+#include <security/pam_appl.h>
 #include "src/util/util.h"
 #include "src/providers/data_provider.h"
 #include "src/providers/dp_backend.h"
-- 
1.8.0

