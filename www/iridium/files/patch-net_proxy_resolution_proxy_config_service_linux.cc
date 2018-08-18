--- net/proxy_resolution/proxy_config_service_linux.cc.orig	2018-07-19 15:35:02.171066000 +0200
+++ net/proxy_resolution/proxy_config_service_linux.cc	2018-07-19 15:37:12.958237000 +0200
@@ -6,7 +6,9 @@
 
 #include <errno.h>
 #include <limits.h>
+#if !defined(OS_BSD)
 #include <sys/inotify.h>
+#endif
 #include <unistd.h>
 
 #include <map>
@@ -495,6 +497,7 @@
   return default_value;
 }
 
+#if !defined(OS_BSD)
 // This is the KDE version that reads kioslaverc and simulates gsettings.
 // Doing this allows the main Delegate code, as well as the unit tests
 // for it, to stay the same - and the settings map fairly well besides.
@@ -984,6 +987,7 @@
 
   DISALLOW_COPY_AND_ASSIGN(SettingGetterImplKDE);
 };
+#endif
 
 }  // namespace
 
@@ -1199,8 +1203,10 @@
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
