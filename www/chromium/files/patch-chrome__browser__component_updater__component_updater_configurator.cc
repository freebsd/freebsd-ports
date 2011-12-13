--- chrome/browser/component_updater/component_updater_configurator.cc.orig	2011-11-22 01:09:14.000000000 +0200
+++ chrome/browser/component_updater/component_updater_configurator.cc	2011-11-22 01:17:26.000000000 +0200
@@ -63,6 +63,14 @@
   #else
     "os=linux&arch=unknown&prod=chrome&prodversion=";
   #endif
+#elif defined(OS_FREEBSD)
+  #if defined(__amd64__)
+    "os=freebsd&arch=x64&prod=chrome&prodversion=";
+  #elif defined(__i386__)
+    "os=freebsd&arch=x86&prod=chrome&prodversion=";
+  #else
+    "os=freebsd&arch=unknown&prod=chrome&prodversion=";
+  #endif
 #elif defined(OS_CHROMEOS)
   #if defined(__i386__)
     "os=cros&arch=x86&prod=chrome&prodversion=";
