--- plugin.c.orig
+++ plugin.c
@@ -198,11 +198,14 @@ bool cDll::Load(bool Log)
      }
   handle = dlopen(fileName, RTLD_NOW);
   const char *error = dlerror();
-  if (!error) {
+  if (handle) {
      void *(*creator)(void);
      creator = (void *(*)(void))dlsym(handle, "VDRPluginCreator");
-     if (!(error = dlerror()))
+     error = dlerror();
+     if (creator) {
         plugin = (cPlugin *)creator();
+        error = NULL;
+        }
      }
   if (!error) {
      if (plugin && args) {
