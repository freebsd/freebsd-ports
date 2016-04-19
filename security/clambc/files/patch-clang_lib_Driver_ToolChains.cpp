--- clang/lib/Driver/ToolChains.cpp.orig	2014-11-10 18:04:47 UTC
+++ clang/lib/Driver/ToolChains.cpp
@@ -895,7 +895,7 @@ Tool &AuroraUX::SelectTool(const Compila
 
 Linux::Linux(const HostInfo &Host, const llvm::Triple& Triple)
   : Generic_GCC(Host, Triple) {
-  getFilePaths().push_back(getDriver().Dir + "/../lib/clang/1.0/");
+  getFilePaths().push_back(getDriver().Dir + "/../share/clambc/");
   getFilePaths().push_back("/lib/");
   getFilePaths().push_back("/usr/lib/");
 
