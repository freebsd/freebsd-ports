--- viz.h.orig	1995-04-14 13:30:56 UTC
+++ viz.h
@@ -82,7 +82,7 @@ typedef MEMBER *MEMP;
 
 #define NIL ((MEMP) 0)
 
-MEMP rootlist;
+extern MEMP rootlist;
 
 
 typedef union {
