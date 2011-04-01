--- gpu/demos/framework/main_pepper.cc.orig	2011-01-06 10:01:08.000000000 +0100
+++ gpu/demos/framework/main_pepper.cc	2011-01-09 19:58:46.000000000 +0100
@@ -97,7 +97,7 @@
   NPError err = NPERR_NO_ERROR;
 
   switch (variable) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     case NPPVpluginNameString:
       *(static_cast<const char**>(value)) = "Pepper GPU Demo";
       break;
@@ -153,16 +153,16 @@
 }
 
 EXPORT NPError API_CALL NP_Initialize(NPNetscapeFuncs* browser_funcs
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
                                      , NPPluginFuncs* plugin_funcs
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_FREEBSD
                                      ) {
   gpu::demos::g_browser = browser_funcs;
   pglInitialize();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   NP_GetEntryPoints(plugin_funcs);
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_FREEBSD
   return NPERR_NO_ERROR;
 }
 
@@ -170,7 +170,7 @@
   pglTerminate();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 EXPORT NPError API_CALL NP_GetValue(NPP instance, NPPVariable variable,
                                     void* value) {
   return gpu::demos::NPP_GetValue(instance, variable, value);
@@ -179,5 +179,5 @@
 EXPORT const char* API_CALL NP_GetMIMEDescription() {
   return "pepper-application/x-gpu-demo::Pepper GPU Demo";
 }
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_FREEBSD
 }  // extern "C"
