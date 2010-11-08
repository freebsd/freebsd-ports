--- ./modules/services_discovery/upnp_intel.cpp.orig	2010-11-08 01:05:00.000000000 -0500
+++ ./modules/services_discovery/upnp_intel.cpp	2010-11-08 01:06:43.000000000 -0500
@@ -36,6 +36,7 @@
 
 #include "upnp_intel.hpp"
 
+#include <assert.h>
 #include <vlc_plugin.h>
 #include <vlc_services_discovery.h>
 
