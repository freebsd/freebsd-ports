--- iiimsf/src/IMSvrCfg.cpp	Mon Oct  4 18:07:05 2004
+++ iiimsf/src/IMSvrCfg.cpp	Wed Feb 16 20:38:05 2005
@@ -90,14 +90,14 @@
 void
 IMSvrCfg::initialize()
 {
-    initstr(IMDIR, "IM main directory.", "/usr/lib/im");
+    initstr(IMDIR, "IM main directory.", IM_DIRECTORY);
     initstr(BASICLOCALE, "Locale used by default", "C");
 #ifdef WIN32
     initstr(IFPATHNAME, "Language Engine module directory",
 	   "D:\\WINNT\\System32\\iiimf");
 #else
     initstr(IFPATHNAME, "Language Engine module directory",
-	   "/usr/lib/im/leif");
+	   (IM_DIRECTORY "/leif"));
 #endif
     initstr(IFNAME, "Language Engine name", "");
     initstr(PORT, "Port or service name", "9010");
