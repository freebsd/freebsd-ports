--- ../clang/tools/CIndex/CIndexer.cpp.orig
+++ ../clang/tools/CIndex/CIndexer.cpp
@@ -87,9 +87,8 @@ std::string CIndexer::getClangResourcesPath() {
     P.eraseComponent();  // Remove /bin   from foo/bin
 
     // Get foo/lib/clang/<version>/include
-    P.appendComponent("lib");
-    P.appendComponent("clang");
-    P.appendComponent(CLANG_VERSION_STRING);
+    P.appendComponent("local");
+    P.appendComponent("clambc");
   }
 
   return P.str();
