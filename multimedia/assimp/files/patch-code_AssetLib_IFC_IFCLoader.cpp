--- code/AssetLib/IFC/IFCLoader.cpp.orig	2026-11-09 20:32:25 UTC
+++ code/AssetLib/IFC/IFCLoader.cpp
@@ -50,11 +50,7 @@ ------------------------------------------------------
 #include <tuple>
 
 #ifndef ASSIMP_BUILD_NO_COMPRESSED_IFC
-#ifdef ASSIMP_USE_HUNTER
 #include <minizip/unzip.h>
-#else
-#include <unzip.h>
-#endif
 #endif
 
 #include "../STEPParser/STEPFileReader.h"
