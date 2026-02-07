--- ldecod/src/configfile.c.orig	2020-09-29 10:22:20 UTC
+++ ldecod/src/configfile.c
@@ -66,6 +66,9 @@
 #include "configfile.h"
 #define MAX_ITEMS_TO_PARSE  10000
 
+InputParameters cfgparams;
+char errortext[ET_SIZE];
+
 static void PatchInp                (InputParameters *p_Inp);
 
 /*!
