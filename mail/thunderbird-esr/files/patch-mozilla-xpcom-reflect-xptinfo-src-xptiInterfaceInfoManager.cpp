--- mozilla/xpcom/reflect/xptinfo/src/xptiInterfaceInfoManager.cpp.orig
+++ mozilla/xpcom/reflect/xptinfo/src/xptiInterfaceInfoManager.cpp
@@ -629,16 +629,17 @@ IndexOfDirectoryOfFile(nsISupportsArray* aSearchPath, nsILocalFile* aFile)
         NS_ASSERTION(count, "broken search path! bad count");
         for(PRUint32 i = 0; i < count; i++)
         {
-            nsCOMPtr<nsIFile> current;
+            nsCOMPtr<nsIFile> current, normalized;
             aSearchPath->QueryElementAt(i, NS_GET_IID(nsIFile), 
                                         getter_AddRefs(current));
             NS_ASSERTION(current, "broken search path! bad element");
             // nsIFile::Equals basically compares path strings so normalize
             // before the comparison.
             parent->Normalize();
-            current->Normalize();
+            current->Clone(getter_AddRefs(normalized));
+            normalized->Normalize();
             PRBool same;
-            if (NS_SUCCEEDED(parent->Equals(current, &same)) && same)
+            if (NS_SUCCEEDED(parent->Equals(normalized, &same)) && same)
                 return (int) i;
         }
     }
