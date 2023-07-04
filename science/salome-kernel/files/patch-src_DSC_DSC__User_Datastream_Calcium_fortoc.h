--- src/DSC/DSC_User/Datastream/Calcium/fortoc.h.orig	2023-07-03 21:45:58 UTC
+++ src/DSC/DSC_User/Datastream/Calcium/fortoc.h
@@ -23,7 +23,7 @@
 /* Operateur de concatenation */
 #define  _(A,B)   A##B
 
-#if defined __linux || defined  __APPLE__
+#if defined __linux || defined __FreeBSD__ || defined  __APPLE__
 #define F_FUNC(lname,uname) _(lname,_)        /* Fortran function name */
 #define F_CALL(lname,uname) _(lname,_)        /* Fortran function call */
 #define STR_PSTR(str)       char *str         /* fortran string arg pointer */
