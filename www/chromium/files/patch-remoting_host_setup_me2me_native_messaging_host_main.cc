--- remoting/host/setup/me2me_native_messaging_host_main.cc.orig	2017-08-10 16:30:29.861339000 +0200
+++ remoting/host/setup/me2me_native_messaging_host_main.cc	2017-08-10 16:31:13.891062000 +0200
@@ -44,7 +44,7 @@
 #include "remoting/host/win/elevation_helpers.h"
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include <glib-object.h>
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
 
@@ -64,7 +64,7 @@
   base::mac::ScopedNSAutoreleasePool pool;
 #endif  // defined(OS_MACOSX)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // g_type_init will be deprecated in 2.36. 2.35 is the development
 // version for 2.36, hence do not call g_type_init starting 2.35.
 // http://developer.gnome.org/gobject/unstable/gobject-Type-Information.html#g-type-init
