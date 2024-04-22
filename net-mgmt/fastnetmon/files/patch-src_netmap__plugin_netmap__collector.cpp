--- netmap_plugin/netmap_collector.cpp.orig	2023-03-01 14:23:34 UTC
+++ netmap_plugin/netmap_collector.cpp
@@ -19,6 +19,7 @@
 
 // Disable debug messages from Netmap
 #define NETMAP_NO_DEBUG
+typedef bool _Bool;
 #include <boost/thread.hpp>
 #include <net/netmap_user.h>
 
