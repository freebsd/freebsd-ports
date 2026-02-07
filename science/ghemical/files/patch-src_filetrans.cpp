attempt at OpenBabel-3 compatibility
--- src/filetrans.cpp.orig	2011-09-14 17:10:38 UTC
+++ src/filetrans.cpp
@@ -38,6 +38,8 @@ using namespace std;
 #include <openbabel/data.h>
 #include <openbabel/typer.h>
 #include <openbabel/obconversion.h>
+#include <openbabel/atom.h>
+#include <openbabel/bond.h>
 
 using namespace std;
 using namespace OpenBabel;
@@ -46,6 +48,7 @@ using namespace OpenBabel;
 #define FORMAT_PATH (char *) project::appdata_path
 #endif	// FORMAT_PATH
 
+#if 0
 namespace OpenBabel
 {
 	extern OBAromaticTyper aromtyper;
@@ -55,6 +58,7 @@ namespace OpenBabel
 	extern OBChainsParser chainsparser;
 	extern OBIsotopeTable isotab;
 }
+#endif
 
 /*################################################################################################*/
 
