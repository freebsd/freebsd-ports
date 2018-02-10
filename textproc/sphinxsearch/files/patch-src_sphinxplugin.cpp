--- src/sphinxplugin.cpp.orig	2016-07-19 10:42:18 UTC
+++ src/sphinxplugin.cpp
@@ -219,7 +219,7 @@ static bool PluginLoadSymbols ( void * pDesc, const Sy
 
 #if !USE_WINDOWS
 #define offsetof(T, M) \
-	(reinterpret_cast<char*>(&(((T*)1000)->M)) - reinterpret_cast<char*>(1000))
+	((int)(reinterpret_cast<char*>(&(((T*)1000)->M)) - reinterpret_cast<char*>(1000)))
 #endif
 
 static SymbolDesc_t g_dSymbolsUDF[] =
