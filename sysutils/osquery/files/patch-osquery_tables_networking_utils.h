--- osquery/tables/networking/utils.h.orig	2015-05-05 00:16:41 UTC
+++ osquery/tables/networking/utils.h
@@ -19,10 +19,10 @@ namespace osquery {
 namespace tables {
 
 // Define AF_INTERFACE as the alias for interface details.
-#ifdef __APPLE__
-#define AF_INTERFACE AF_LINK
-#else
+#ifdef __linux__
 #define AF_INTERFACE AF_PACKET
+#else
+#define AF_INTERFACE AF_LINK
 #endif
 
 // Return a string representation for an IPv4/IPv6 struct.
