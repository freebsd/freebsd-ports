--- UI/window-basic-main.cpp.orig	2016-09-28 09:24:18 UTC
+++ UI/window-basic-main.cpp
@@ -1930,6 +1930,10 @@ void trigger_sparkle_update();
 
 void OBSBasic::TimedCheckForUpdates()
 {
+#ifdef __FreeBSD__
+	// Update check seg faults on FreeBSD
+	return;
+#endif
 #ifdef UPDATE_SPARKLE
 	init_sparkle_updater(config_get_bool(App()->GlobalConfig(), "General",
 				"UpdateToUndeployed"));
