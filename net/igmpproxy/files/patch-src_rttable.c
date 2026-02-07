From e49fb373da9044dfb00ffbcd3e1f68ca7107af75 Mon Sep 17 00:00:00 2001
From: Jan Klemkow <j.klemkow@wemelug.de>
Date: Thu, 17 Apr 2025 18:53:18 +0200
Subject: [PATCH] Fix use after free(3) in internAgeRoute().

removeRoute(croute) calls free(croute).  Thus, the zeroing of
croute->ageVifBits afterwards is unnecessary, illegal and an
undefined behavior.
---
 src/rttable.c | 4 +++-
 1 file changed, 3 insertions(+), 1 deletion(-)

diff --git a/src/rttable.c b/src/rttable.c
index bcafa3fe..04e24f3b 100644
--- src/rttable.c
+++ src/rttable.c
@@ -704,13 +704,15 @@ int internAgeRoute(struct RouteTable*  croute) {
 
             // No activity was registered within the timelimit, so remove the route.
             removeRoute(croute);
+            croute = NULL;
         }
         // Tell that the route was updated...
         result = 1;
     }
 
     // The aging vif bits must be reset for each round...
-    BIT_ZERO(croute->ageVifBits);
+    if (croute != NULL)
+        BIT_ZERO(croute->ageVifBits);
 
     return result;
 }
