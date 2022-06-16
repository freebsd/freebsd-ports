--- coreapi/linphonecore.c.orig	2022-06-16 11:26:25 UTC
+++ coreapi/linphonecore.c
@@ -720,7 +720,7 @@ static void _close_log_collection_file(void) {
 	}
 }
 
-#if (!__ANDROID__ && !__APPLE__) || (__ANDROID__ && __ANDROID_API__ < 21)
+#if (!__ANDROID__ && !__APPLE__ && !__FreeBSD__) || (__ANDROID__ && __ANDROID_API__ < 21)
 static const char* getprogname() {
 #if defined(__GLIBC__)
   	return program_invocation_short_name;
@@ -2085,8 +2085,8 @@ static void video_config_read(LinphoneCore *lc){
 
 	str = linphone_config_get_string(lc->config, "video", "device", NULL);
 	linphone_core_set_video_device(lc, str);
-	
 
+
 	str = linphone_config_get_string(lc->config, "video", "size", "vga");
 	if (str && str[0] != 0) linphone_core_set_preferred_video_definition_by_name(lc, str);
 
@@ -2801,7 +2801,7 @@ static void linphone_core_init(LinphoneCore * lc, Linp
 	bool_t push_notification_default = FALSE;
 	bool_t auto_iterate_default = FALSE;
 	bool_t vibration_incoming_call_default = FALSE;
-	
+
 #if __ANDROID__ || TARGET_OS_IPHONE
 	auto_iterate_default = TRUE;
 #endif
@@ -5303,7 +5303,7 @@ void linphone_core_reload_sound_devices(LinphoneCore* 
 	build_sound_devices_table(lc);
 
 // Set selection
-	
+
 	linphone_core_set_ringer_device(lc, ringer_copy);
 	if (ringer_copy != NULL)
 		ms_free(ringer_copy);
@@ -7275,10 +7275,10 @@ void _linphone_core_uninit(LinphoneCore *lc)
 		bctbx_list_free(lc->supported_encryptions);
 	}
 	lc->supported_encryptions = NULL;
-	
+
 	if (lc->platform_helper) delete getPlatformHelpers(lc);
 	lc->platform_helper = NULL;
-	
+
 	linphone_config_unref(lc->config);
 	lc->config = NULL;
 #ifdef __ANDROID__
