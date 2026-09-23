From 54f8a4a848fa02d06fefc5543f35224eef73670c Mon Sep 17 00:00:00 2001
From: Matthias Kurz <m.kurz@irregular.at>
Date: Wed, 19 Aug 2026 17:51:12 +0200
Subject: [PATCH] Avoid low battery alerts for unknown percentages

Peripheral batteries with an unavailable charge return a negative percentage. Exclude all non-positive values from low-battery notification handling so an unknown device cannot be mistaken for an empty one.

--- daemon/powerdevilcore.cpp.orig	2026-09-08 11:00:22 UTC
+++ daemon/powerdevilcore.cpp
@@ -521,9 +521,9 @@ bool Core::emitBatteryChargePercentNotification(int cu
             return false;
         }
 
-        // if you leave the device out of reach or it has not been initialized yet
-        // it won't be "there" and report 0%, don't show anything in this case
-        if (!b->isPresent() || b->chargePercent() == 0) {
+        // If you leave the device out of reach or it has not been initialized yet,
+        // it won't be "there" and can report an empty or unknown percentage.
+        if (!b->isPresent() || b->chargePercent() <= 0) {
             return false;
         }
 
