--- net/proxy/proxy_config_service_linux.cc.orig	2018-03-20 23:05:28.000000000 +0100
+++ net/proxy/proxy_config_service_linux.cc	2018-03-24 18:11:27.991396000 +0100
@@ -6,7 +6,9 @@
 
 #include <errno.h>
 #include <limits.h>
+#if !defined(OS_BSD)
 #include <sys/inotify.h>
+#endif
 #include <unistd.h>
 
 #include <map>
@@ -483,6 +485,7 @@
   return default_value;
 }
 
+#if !defined(OS_BSD)
 // This is the KDE version that reads kioslaverc and simulates gsettings.
 // Doing this allows the main Delegate code, as well as the unit tests
 // for it, to stay the same - and the settings map fairly well besides.
@@ -976,6 +979,7 @@
 
   DISALLOW_COPY_AND_ASSIGN(SettingGetterImplKDE);
 };
+#endif
 
 }  // namespace
 
@@ -1173,8 +1177,10 @@
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
