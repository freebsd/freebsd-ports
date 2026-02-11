--- src/backends/freebsd/fbsdpkgindex.cpp.orig	2026-02-10 19:57:51 UTC
+++ src/backends/freebsd/fbsdpkgindex.cpp
@@ -154,7 +154,7 @@ std::shared_ptr<Package> FreeBSDPackageIndex::packageF
         return nullptr;
     }
 
-    return nullptr;
+    return std::shared_ptr<FreeBSDPackage>(FreeBSDPackage::CreateFromWorkdir(fname));
 }
 
 bool FreeBSDPackageIndex::hasChanges(
