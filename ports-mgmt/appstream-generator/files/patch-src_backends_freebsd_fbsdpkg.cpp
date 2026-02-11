--- src/backends/freebsd/fbsdpkg.cpp.orig	2026-02-10 19:57:51 UTC
+++ src/backends/freebsd/fbsdpkg.cpp
@@ -40,7 +40,7 @@ FreeBSDPackage *FreeBSDPackage::CreateFromWorkdir(cons
         if (!entry.is_regular_file())
             continue;
 
-        if (entry.path().extension() != "pkg")
+        if (entry.path().extension() != ".pkg")
             continue;
 
         count++;
