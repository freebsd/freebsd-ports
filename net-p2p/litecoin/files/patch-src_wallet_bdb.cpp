--- src/wallet/bdb.cpp	2024-03-28 17:05:26.000000000 +0000
+++ src/wallet/bdb.cpp	2024-11-20 13:23:51.628575000 +0000
@@ -627,7 +627,7 @@
                         return false;
                     }
 
-                    fs::copy_file(pathSrc, pathDest, fs::copy_option::overwrite_if_exists);
+                    fs::copy_file(pathSrc, pathDest, fs::copy_options::overwrite_existing);
                     LogPrintf("copied %s to %s\n", strFile, pathDest.string());
                     return true;
                 } catch (const fs::filesystem_error& e) {
