--- UI/window-basic-main.cpp.orig	2017-10-25 18:45:20 UTC
+++ UI/window-basic-main.cpp
@@ -2461,6 +2461,10 @@ void OBSBasic::TimedCheckForUpdates()
 
 void OBSBasic::CheckForUpdates(bool manualUpdate)
 {
+#ifdef __FreeBSD__
+	// Update check seg faults on FreeBSD
+	return;
+#endif
 #ifdef UPDATE_SPARKLE
 	trigger_sparkle_update();
 #elif ENABLE_WIN_UPDATER
