--- src/libexpr/primops/fetchGit.cc.orig	2019-10-10 13:03:46 UTC
+++ src/libexpr/primops/fetchGit.cc
@@ -6,6 +6,7 @@
 #include "hash.hh"
 
 #include <sys/time.h>
+#include <sys/wait.h>
 
 #include <regex>
 
@@ -173,7 +174,7 @@ GitInfo exportGit(ref<Store> store, const std::string 
     Path tmpDir = createTempDir();
     AutoDelete delTmpDir(tmpDir, true);
 
-    runProgram("tar", true, { "x", "-C", tmpDir }, tar);
+    runProgram("tar", true, { "x", "-C", tmpDir, "-f", "-"}, tar);
 
     gitInfo.storePath = store->addToStore(name, tmpDir);
 
