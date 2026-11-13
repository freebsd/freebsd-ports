--- code/Common/ZipArchiveIOSystem.cpp.orig	2026-11-09 20:32:25 UTC
+++ code/Common/ZipArchiveIOSystem.cpp
@@ -51,11 +51,7 @@ ------------------------------------------------------
 #include <map>
 #include <memory>
 
-#ifdef ASSIMP_USE_HUNTER
 #    include <minizip/unzip.h>
-#else
-#    include <unzip.h>
-#endif
 
 namespace Assimp {
 
