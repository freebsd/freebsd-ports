--- Linphone/model/setting/SettingsModel.cpp.orig
+++ Linphone/model/setting/SettingsModel.cpp
@@ -1,6 +1,6 @@
 void SettingsModel::accessCallSettings() {
 	mustBeInLinphoneThread(log().arg(Q_FUNC_INFO));
-	startCaptureGraph();
+	if (mSimpleCaptureGraph) deleteCaptureGraph();
 
 	// Audio
 	CoreModel::getInstance()->getCore()->reloadSoundDevices();
@@ -1,4 +1,6 @@
 	// Video
 	CoreModel::getInstance()->getCore()->reloadVideoDevices();
 	emit videoDevicesChanged(getVideoDevices());
+
+	startCaptureGraph();
 }
