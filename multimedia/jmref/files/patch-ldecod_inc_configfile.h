--- ldecod/inc/configfile.h.orig	2015-06-19 11:50:48 UTC
+++ ldecod/inc/configfile.h
@@ -18,7 +18,7 @@
 //#define LEVEL_IDC       21
 
 
-InputParameters cfgparams;
+extern InputParameters cfgparams;
 
 #ifdef INCLUDED_BY_CONFIGFILE_C
 // Mapping_Map Syntax:
