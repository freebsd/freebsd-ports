--- net/proxy_resolution/proxy_config_service_linux.cc.orig	2021-07-19 18:45:19 UTC
+++ net/proxy_resolution/proxy_config_service_linux.cc
@@ -6,7 +6,9 @@
 
 #include <errno.h>
 #include <limits.h>
+#if !defined(OS_BSD)
 #include <sys/inotify.h>
+#endif
 #include <unistd.h>
 
 #include <map>
@@ -504,6 +506,7 @@ bool SettingGetterImplGSettings::CheckVersion(
 }
 #endif  // defined(USE_GIO)
 
+#if !defined(OS_BSD)
 // Converts |value| from a decimal string to an int. If there was a failure
 // parsing, returns |default_value|.
 int StringToIntOrDefault(base::StringPiece value, int default_value) {
@@ -1003,6 +1006,7 @@ class SettingGetterImplKDE : public ProxyConfigService
 
   DISALLOW_COPY_AND_ASSIGN(SettingGetterImplKDE);
 };
+#endif
 
 }  // namespace
 
@@ -1217,9 +1221,11 @@ ProxyConfigServiceLinux::Delegate::Delegate(
     case base::nix::DESKTOP_ENVIRONMENT_KDE3:
     case base::nix::DESKTOP_ENVIRONMENT_KDE4:
     case base::nix::DESKTOP_ENVIRONMENT_KDE5:
+#if !defined(OS_BSD)
       setting_getter_ =
           std::make_unique<SettingGetterImplKDE>(env_var_getter_.get());
       break;
+#endif
     case base::nix::DESKTOP_ENVIRONMENT_XFCE:
     case base::nix::DESKTOP_ENVIRONMENT_OTHER:
       break;
