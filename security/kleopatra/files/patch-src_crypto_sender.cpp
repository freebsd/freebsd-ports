Submitted upstream: https://invent.kde.org/pim/kleopatra/-/merge_requests/205.
To remove when updating to next release.

--- src/crypto/sender.cpp.orig	2024-02-11 04:00:57 UTC
+++ src/crypto/sender.cpp
@@ -91,7 +91,7 @@ void Sender::detach()
 
 void Sender::detach()
 {
-    if (d && !d.unique()) {
+    if (d && d.use_count() != 1) {
         d.reset(new Private(*d));
     }
 }
