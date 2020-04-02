--- UI/window-basic-main.cpp.orig	2020-03-19 16:51:06 UTC
+++ UI/window-basic-main.cpp
@@ -3207,6 +3207,10 @@ void OBSBasic::TimedCheckForUpdates()
 
 void OBSBasic::CheckForUpdates(bool manualUpdate)
 {
+#ifdef __FreeBSD__
+	// Update check seg faults on FreeBSD
+	return;
+#endif
 #ifdef UPDATE_SPARKLE
 	trigger_sparkle_update();
 #elif _WIN32
