--- webkit/plugins/npapi/plugin_utils.cc.orig	2013-05-12 20:08:18.000000000 +0300
+++ webkit/plugins/npapi/plugin_utils.cc	2013-05-12 20:10:33.000000000 +0300
@@ -45,7 +45,7 @@
 }
 
 bool NPAPIPluginsSupported() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(USE_AURA))
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || (defined(OS_LINUX) && !defined(USE_AURA))
   return true;
 #else
   return false;
