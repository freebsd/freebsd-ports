--- net/proxy_resolution/proxy_config_service_linux.cc.orig	2020-03-16 18:40:33 UTC
+++ net/proxy_resolution/proxy_config_service_linux.cc
@@ -6,7 +6,9 @@
 
 #include <errno.h>
 #include <limits.h>
+#if !defined(OS_BSD)
 #include <sys/inotify.h>
+#endif
 #include <unistd.h>
 
 #include <map>
@@ -511,6 +513,7 @@ int StringToIntOrDefault(base::StringPiece value, int 
   return default_value;
 }
 
+#if !defined(OS_BSD)
 // This is the KDE version that reads kioslaverc and simulates gsettings.
 // Doing this allows the main Delegate code, as well as the unit tests
 // for it, to stay the same - and the settings map fairly well besides.
@@ -1000,6 +1003,7 @@ class SettingGetterImplKDE : public ProxyConfigService
 
   DISALLOW_COPY_AND_ASSIGN(SettingGetterImplKDE);
 };
+#endif
 
 }  // namespace
 
@@ -1214,8 +1218,10 @@ ProxyConfigServiceLinux::Delegate::Delegate(
     case base::nix::DESKTOP_ENVIRONMENT_KDE3:
     case base::nix::DESKTOP_ENVIRONMENT_KDE4:
     case base::nix::DESKTOP_ENVIRONMENT_KDE5:
+#if !defined(OS_BSD)
       setting_getter_.reset(new SettingGetterImplKDE(env_var_getter_.get()));
       break;
+#endif
     case base::nix::DESKTOP_ENVIRONMENT_XFCE:
     case base::nix::DESKTOP_ENVIRONMENT_OTHER:
       break;
