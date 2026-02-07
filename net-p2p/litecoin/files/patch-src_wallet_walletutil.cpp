--- src/wallet/walletutil.cpp	2024-03-28 17:05:26.000000000 +0000
+++ src/wallet/walletutil.cpp	2024-11-20 13:28:06.157704000 +0000
@@ -58,7 +58,7 @@
                 (ExistsBerkeleyDatabase(it->path()) || ExistsSQLiteDatabase(it->path()))) {
                 // Found a directory which contains wallet.dat btree file, add it as a wallet.
                 paths.emplace_back(path);
-            } else if (it.level() == 0 && it->symlink_status().type() == fs::regular_file && ExistsBerkeleyDatabase(it->path())) {
+            } else if (it.depth() == 0 && it->symlink_status().type() == fs::regular_file && ExistsBerkeleyDatabase(it->path())) {
                 if (it->path().filename() == "wallet.dat") {
                     // Found top-level wallet.dat btree file, add top level directory ""
                     // as a wallet.
@@ -73,7 +73,7 @@
             }
         } catch (const std::exception& e) {
             LogPrintf("%s: Error scanning %s: %s\n", __func__, it->path().string(), e.what());
-            it.no_push();
+            it.disable_recursion_pending();
         }
     }
 
