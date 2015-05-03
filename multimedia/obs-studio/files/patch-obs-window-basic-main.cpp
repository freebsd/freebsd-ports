--- obs/window-basic-main.cpp.orig	2015-03-27 21:29:37 UTC
+++ obs/window-basic-main.cpp
@@ -1056,6 +1056,10 @@ void OBSBasic::TimedCheckForUpdates()
 
 void OBSBasic::CheckForUpdates()
 {
+#ifdef __FreeBSD__
+	// Update check seg faults on FreeBSD
+	return;
+#endif
 #ifdef UPDATE_SPARKLE
 	trigger_sparkle_update();
 #else
