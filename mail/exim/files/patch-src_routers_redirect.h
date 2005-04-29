
$FreeBSD$

--- src/routers/redirect.h.orig
+++ src/routers/redirect.h
@@ -35,9 +35,6 @@
 
 #ifdef EXPERIMENTAL_SRS
   uschar *srs;
-  uschar *srs_condition;
-  uschar *srs_db;
-  uschar *srs_alias;
 #endif
 
   int   modemask;
