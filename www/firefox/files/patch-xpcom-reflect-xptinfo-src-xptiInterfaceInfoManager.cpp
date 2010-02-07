--- xpcom/reflect/xptinfo/src/xptiInterfaceInfoManager.cpp.orig
+++ xpcom/reflect/xptinfo/src/xptiInterfaceInfoManager.cpp
@@ -633,10 +633,17 @@ IndexOfDirectoryOfFile(nsISupportsArray*
             aSearchPath->QueryElementAt(i, NS_GET_IID(nsIFile), 
                                         getter_AddRefs(current));
             NS_ASSERTION(current, "broken search path! bad element");
+#if 0
+            // XXX #if 0'd because this breaks
+            //   xptiInterfaceInfoManager::DoFullValidationMergeFromFileList()
+            // causing ff failing to start when there are symlinks in .xpt
+            // file paths, like those from addons when /home is a symlink.
+
             // nsIFile::Equals basically compares path strings so normalize
             // before the comparison.
             parent->Normalize();
             current->Normalize();
+#endif
             PRBool same;
             if (NS_SUCCEEDED(parent->Equals(current, &same)) && same)
                 return (int) i;
