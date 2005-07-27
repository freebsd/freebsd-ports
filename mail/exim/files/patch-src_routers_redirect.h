
$FreeBSD$

--- src/routers/redirect.h.orig
+++ src/routers/redirect.h
@@ -37,10 +37,6 @@
 
 #ifdef EXPERIMENTAL_SRS
   uschar *srs;
-  uschar *srs_alias;
-  uschar *srs_condition;
-  uschar *srs_dbinsert;
-  uschar *srs_dbselect;
 #endif
 
   int   modemask;
