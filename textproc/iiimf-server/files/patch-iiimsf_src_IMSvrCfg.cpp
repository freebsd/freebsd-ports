--- iiimsf/src/IMSvrCfg.cpp	Mon Oct  4 18:07:05 2004
+++ iiimsf/src/IMSvrCfg.cpp	Wed Feb 16 20:38:05 2005
@@ -90,14 +90,14 @@
 void
 IMSvrCfg::initialize()
 {
-    initstr(IMDIR, "IM main directory.", "/usr/lib/im");
+    initstr(IMDIR, "IM main directory.", "/usr/local/lib/im");
     initstr(BASICLOCALE, "Locale used by default", "C");
 #ifdef WIN32
     initstr(IFPATHNAME, "Language Engine module directory",
 	   "D:\\WINNT\\System32\\iiimf");
 #else
     initstr(IFPATHNAME, "Language Engine module directory",
-	   "/usr/lib/im/leif");
+	   "/usr/local/lib/im/leif");
 #endif
     initstr(IFNAME, "Language Engine name", "");
     initstr(PORT, "Port or service name", "9010");
@@ -115,7 +115,7 @@
     initstr(CONVERSIONKEYS, "Conversion ON keys", "<Ctrl>space");
     initstr(LABEL, "Label type", "numeric");
     initbool(SETTRIGGEROFFKEYS, "set trigger off keys", false);
-    // initstr(IMCONFIG, "/usr/lib/im/etc/im.config");
+    // initstr(IMCONFIG, "/usr/local/lib/im/etc/im.config");
     // initbool(DIRECT_XSUNIM, true);
     initstr(LOG_FACILITY, "syslog facility", "USER");
     initstr(LOG_LEVEL, "log level", "NORMAL");
