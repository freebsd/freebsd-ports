--- src/lib/barrier/KeyMap.h.orig	2020-07-17 08:20:18 UTC
+++ src/lib/barrier/KeyMap.h
@@ -24,8 +24,6 @@
 #include "common/stdset.h"
 #include "common/stdvector.h"
 
-#include <gtest/gtest_prod.h>
-
 namespace barrier {
 
 //! Key map
@@ -325,21 +323,6 @@ class KeyMap { (public)
     static bool            parseModifiers(String&, KeyModifierMask&);
 
     //@}
-
-private:
-    FRIEND_TEST(KeyMapTests,
-                findBestKey_requiredDown_matchExactFirstItem);
-    FRIEND_TEST(KeyMapTests,
-        findBestKey_requiredAndExtraSensitiveDown_matchExactFirstItem);
-    FRIEND_TEST(KeyMapTests,
-        findBestKey_requiredAndExtraSensitiveDown_matchExactSecondItem);
-    FRIEND_TEST(KeyMapTests,
-        findBestKey_extraSensitiveDown_matchExactSecondItem);
-    FRIEND_TEST(KeyMapTests,
-                findBestKey_noRequiredDown_matchOneRequiredChangeItem);
-    FRIEND_TEST(KeyMapTests,
-                findBestKey_onlyOneRequiredDown_matchTwoRequiredChangesItem);
-    FRIEND_TEST(KeyMapTests, findBestKey_noRequiredDown_cannotMatch);
 
 private:
     //! Ways to synthesize a key
