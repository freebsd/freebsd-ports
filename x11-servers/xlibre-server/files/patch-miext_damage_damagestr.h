From 10249fc458c59755aade79caefb84b6cd953e77d Mon Sep 17 00:00:00 2001
From: "Enrico Weigelt, metux IT consult" <info@metux.net>
Date: Fri, 13 Nov 2026 14:38:06 +0100
Subject: [PATCH 1/2] miext: damage: fix ABI mismatch caused by Xorg patch

The xorg commit da72833185481481052972f031262e94976131ef which had been
cherry-picked introduces a new field in the middle of the DamageRec struct,
which is part of the public driver ABI.

It broke at least the amdgpu driver (at time of writing no others known yet)

So doing what's the correct approach here: always put new fields at the
end of the struct, never change existing layout.

Signed-off-by: Enrico Weigelt, metux IT consult <info@metux.net>
---
 miext/damage/damagestr.h | 15 +++++++++------
 1 file changed, 9 insertions(+), 6 deletions(-)

diff --git miext/damage/damagestr.h miext/damage/damagestr.h
index 41f4afe38cf..e2287402ba8 100644
--- miext/damage/damagestr.h
+++ miext/damage/damagestr.h
@@ -1,3 +1,4 @@
+/* PART OF PUBLIC SDK */
 /*
  * Copyright © 2003 Keith Packard
  *
@@ -35,12 +36,6 @@
 typedef struct _damage {
     DamagePtr pNext;
     DamagePtr pNextWin;
-    /*
-     * Head of the pNext list this damage is currently linked on, or NULL if it is not linked on any list.  Recorded at
-     * insertion time so that removal always unlinks from the list the damage actually went onto; see
-     * damageInsertDamage().
-     */
-    DamagePtr *pListHead;
     RegionRec damage;
 
     DamageReportLevel damageLevel;
@@ -55,6 +50,14 @@ typedef struct _damage {
     Bool reportAfter;
     RegionRec pendingDamage;    /* will be flushed post submission at the latest */
     ScreenPtr pScreen;
+
+    /* --- not part of ABI beyond here --- */
+    /*
+     * Head of the pNext list this damage is currently linked on, or NULL if it is not linked on any list.  Recorded at
+     * insertion time so that removal always unlinks from the list the damage actually went onto; see
+     * damageInsertDamage().
+     */
+    DamagePtr *pListHead;
 } DamageRec;
 
 typedef struct _damageScrPriv {
