--- src/mod_magnet.c.orig	2015-07-26 10:36:36 UTC
+++ src/mod_magnet.c
@@ -24,6 +24,10 @@
 #define MAGNET_CONFIG_PHYSICAL_PATH "magnet.attract-physical-path-to"
 #define MAGNET_RESTART_REQUEST      99
 
+#if LUA_VERSION_NUM >= 502
+#define LUA_GLOBALSINDEX LUA_REGISTRYINDEX
+#endif
+
 /* plugin config for all request/connections */
 
 static jmp_buf exceptionjmp;
