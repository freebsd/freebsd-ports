--- includes/site.h.orig	Thu Sep 28 11:24:17 2000
+++ includes/site.h	Sat Dec  2 00:46:53 2000
@@ -159 +159 @@
-/* #define DHCPD_LOG_FACILITY LOG_DAEMON */
+#define DHCPD_LOG_FACILITY LOG_!!USE_FACILITY!!
