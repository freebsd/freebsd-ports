--- libs/libnapi_wrappers.sh.orig	2020-04-24 07:38:48 UTC
+++ libs/libnapi_wrappers.sh
@@ -129,13 +129,20 @@ wrappers_isSystemDarwin() {
 }
 
 #
+# @brief returns true if system is FreeBSD
+#
+wrappers_isSystemFreeBSD() {
+    [ "$(wrappers_getSystem_SO)" = "freebsd" ]
+}
+
+#
 # @brief determines number of available cpu's in the system
 #
 # @param system type (linux|darwin)
 #
 wrappers_getCores_SO() {
     local os="${1:-linux}"
-    if wrappers_isSystemDarwin; then
+    if wrappers_isSystemDarwin || wrappers_isSystemFreeBSD; then
         sysctl hw.ncpu | cut -d ' ' -f 2
 	else
         grep -i processor /proc/cpuinfo | wc -l
