--- ../clang/lib/Driver/ToolChains.cpp~	2014-11-10 13:04:47.000000000 -0500
+++ ../clang/lib/Driver/ToolChains.cpp	2014-11-18 12:24:07.772342155 -0500
@@ -895,7 +895,7 @@
 
 Linux::Linux(const HostInfo &Host, const llvm::Triple& Triple)
   : Generic_GCC(Host, Triple) {
-  getFilePaths().push_back(getDriver().Dir + "/../lib/clang/1.0/");
+  getFilePaths().push_back(getDriver().Dir + "/../share/clambc/");
   getFilePaths().push_back("/lib/");
   getFilePaths().push_back("/usr/lib/");
 
