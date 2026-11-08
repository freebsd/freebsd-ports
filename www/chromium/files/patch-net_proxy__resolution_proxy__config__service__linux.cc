--- net/proxy_resolution/proxy_config_service_linux.cc.orig	2026-10-18 13:29:39 UTC
+++ net/proxy_resolution/proxy_config_service_linux.cc
@@ -6,7 +6,9 @@
 
 #include <errno.h>
 #include <limits.h>
+#if !BUILDFLAG(IS_BSD)
 #include <sys/inotify.h>
+#endif
 #include <unistd.h>
 
 #include <array>
@@ -499,6 +501,7 @@ bool SettingGetterImplGSettings::CheckVersion() {
 }
 #endif  // defined(USE_GIO)
 
+#if !BUILDFLAG(IS_BSD)
 // Converts |value| from a decimal string to an int. If there was a failure
 // parsing, returns |default_value|.
 int StringToIntOrDefault(std::string_view value, int default_value) {
@@ -1039,6 +1042,7 @@ class SettingGetterImplKDE : public ProxyConfigService
   // events on.
   scoped_refptr<base::SequencedTaskRunner> file_task_runner_;
 };
+#endif
 
 }  // namespace
 
@@ -1259,9 +1263,11 @@ ProxyConfigServiceLinux::Delegate::Delegate(
     case base::nix::DESKTOP_ENVIRONMENT_KDE4:
     case base::nix::DESKTOP_ENVIRONMENT_KDE5:
     case base::nix::DESKTOP_ENVIRONMENT_KDE6:
+#if !BUILDFLAG(IS_BSD)
       setting_getter_ =
           std::make_unique<SettingGetterImplKDE>(env_var_getter_.get());
       break;
+#endif
     case base::nix::DESKTOP_ENVIRONMENT_XFCE:
     case base::nix::DESKTOP_ENVIRONMENT_LXQT:
     case base::nix::DESKTOP_ENVIRONMENT_OTHER:
