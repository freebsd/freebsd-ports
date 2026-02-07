--- lencod/inc/configfile.h.orig	2015-06-19 11:50:52 UTC
+++ lencod/inc/configfile.h
@@ -20,7 +20,7 @@
 #define PROFILE_IDC     88
 #define LEVEL_IDC       21
 
-InputParameters cfgparams;
+extern InputParameters cfgparams;
 
 
 #ifdef INCLUDED_BY_CONFIGFILE_C
