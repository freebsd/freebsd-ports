From 5363fb5cefbf8f9f0f4d38f81252ce93942665e4 Mon Sep 17 00:00:00 2001
From: Jongsung Kim <jongsung.kim@gmail.com>
Date: Tue, 20 Nov 2018 17:36:10 +0900
Subject: [PATCH 2/2] webui: epg: fix compatibility issue for FreeBSD

The EPG screen serviced by FreeBSD port of tvheadend has two abnormal control
behaviors:

    Reset All button makes the list empty
    Typing and then deleting any search string also makes the list empty.

This patch fixes the symptoms above.

Patch tested with the latest FreeBSD port of tvheadend-4.2.7.

Changes since v1:
- call reset only if required
---
 src/webui/static/app/epg.js | 9 +++++----
 1 file changed, 5 insertions(+), 4 deletions(-)

diff --git a/src/webui/static/app/epg.js b/src/webui/static/app/epg.js
index 2c8b914b2..7337177ef 100644
--- src/webui/static/app/epg.js
+++ src/webui/static/app/epg.js
@@ -902,10 +902,11 @@ tvheadend.epg = function() {
     epgFilterTitle.on('valid', function(c) {
         var value = c.getValue();
 
-        if (value.length < 1)
-            value = null;
-
-        if (epgStore.baseParams.title !== value) {
+        if (value.length < 1) {
+            delete epgStore.baseParams.title;
+            epgView.reset();
+        }
+        else if (epgStore.baseParams.title !== value) {
             epgStore.baseParams.title = value;
             epgView.reset();
         }
-- 
2.19.1

