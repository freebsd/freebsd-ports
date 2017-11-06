--- content/browser/accessibility/browser_accessibility_auralinux.cc.orig	2017-09-07 11:43:10.700550000 +0200
+++ content/browser/accessibility/browser_accessibility_auralinux.cc	2017-09-07 11:41:51.229880000 +0200
@@ -571,7 +571,7 @@
 // it's best to leave this out rather than break people's builds:
 #if defined(ATK_CHECK_VERSION)
 #if ATK_CHECK_VERSION(2, 16, 0)
-      atk_state_set_add_state(atk_state_set, ATK_STATE_READ_ONLY);
+      atk_state_set_add_state(state_set, ATK_STATE_READ_ONLY);
 #endif
 #endif
       break;
