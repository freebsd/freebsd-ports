From 08d2bd8bcd975f1bbd2ea3671ba42f022779d3a8 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 08/34] patch-src__providers__ipa__ipa_hbac.h

---
 src/providers/ipa/ipa_hbac.h | 1 +
 1 file changed, 1 insertion(+)

diff --git src/providers/ipa/ipa_hbac.h src/providers/ipa/ipa_hbac.h
index 02077e3..b1d8efa 100644
--- src/providers/ipa/ipa_hbac.h
+++ src/providers/ipa/ipa_hbac.h
@@ -39,6 +39,7 @@
 
 #include <stdint.h>
 #include <stdbool.h>
+#include <time.h>
 
 /** Result of HBAC evaluation */
 enum hbac_eval_result {
-- 
1.8.0

