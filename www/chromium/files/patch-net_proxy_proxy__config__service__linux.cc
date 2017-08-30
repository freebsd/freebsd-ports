--- net/proxy/proxy_config_service_linux.cc.orig	2017-07-25 21:04:58.000000000 +0200
+++ net/proxy/proxy_config_service_linux.cc	2017-08-02 14:35:59.532886000 +0200
@@ -11,7 +11,9 @@
 #include <limits.h>
 #include <stdio.h>
 #include <stdlib.h>
+#if !defined(OS_BSD)
 #include <sys/inotify.h>
+#endif
 #include <unistd.h>
 
 #include <map>
@@ -855,6 +857,7 @@
 }
 #endif  // defined(USE_GIO)
 
+#if !defined(OS_BSD)
 // This is the KDE version that reads kioslaverc and simulates gconf.
 // Doing this allows the main Delegate code, as well as the unit tests
 // for it, to stay the same - and the settings map fairly well besides.
@@ -1348,6 +1351,7 @@
 
   DISALLOW_COPY_AND_ASSIGN(SettingGetterImplKDE);
 };
+#endif
 
 }  // namespace
 
@@ -1549,8 +1553,10 @@
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
