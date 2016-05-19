--- obs/window-basic-main.cpp.orig	2016-04-24 23:05:32 UTC
+++ obs/window-basic-main.cpp
@@ -1824,6 +1824,10 @@ void OBSBasic::TimedCheckForUpdates()
 
 void OBSBasic::CheckForUpdates()
 {
+#ifdef __FreeBSD__
+	// Update check seg faults on FreeBSD
+	return;
+#endif
 #ifdef UPDATE_SPARKLE
 	trigger_sparkle_update();
 #else
