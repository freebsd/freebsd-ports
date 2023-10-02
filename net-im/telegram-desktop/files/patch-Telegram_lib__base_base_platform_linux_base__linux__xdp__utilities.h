--- Telegram/lib_base/base/platform/linux/base_linux_xdp_utilities.h.orig	2023-10-01 14:40:15 UTC
+++ Telegram/lib_base/base/platform/linux/base_linux_xdp_utilities.h
@@ -78,7 +78,7 @@ class SettingWatcher { (public)
 
 	template <typename Callback>
 	SettingWatcher(Callback callback)
-	: SettingWatcher(Fn(callback)) {
+	: SettingWatcher(std::function(callback)) {
 	}
 
 	template <typename ...Args>
@@ -101,7 +101,7 @@ class SettingWatcher { (public)
 		const Glib::ustring &group,
 		const Glib::ustring &key,
 		Callback callback)
-	: SettingWatcher(group, key, Fn(callback)) {
+	: SettingWatcher(group, key, std::function(callback)) {
 	}
 
 	~SettingWatcher();
