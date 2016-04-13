--- clang/lib/Frontend/CompilerInvocation.cpp.orig	2014-11-10 18:04:47 UTC
+++ clang/lib/Frontend/CompilerInvocation.cpp
@@ -993,9 +993,8 @@ std::string CompilerInvocation::GetResourcesPath(const char *Argv0,
     P.eraseComponent();  // Remove /bin   from foo/bin
 
     // Get foo/lib/clang/<version>/include
-    P.appendComponent("lib");
-    P.appendComponent("clang");
-    P.appendComponent(CLANG_VERSION_STRING);
+    P.appendComponent("share");
+    P.appendComponent("clambc");
   }
 
   return P.str();
