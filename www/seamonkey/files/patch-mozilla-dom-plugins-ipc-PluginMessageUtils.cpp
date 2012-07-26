--- mozilla/dom/plugins/ipc/PluginMessageUtils.cpp~
+++ mozilla/dom/plugins/ipc/PluginMessageUtils.cpp
@@ -94,7 +94,7 @@ ReplaceAll(const string& haystack, const
     i += with.length();
   }
 
-  return munged;
+  return munged.c_str();
 }
 #endif
 
