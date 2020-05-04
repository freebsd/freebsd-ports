--- include/sm/mapcnf.h.orig	2014-05-30 15:34:55 UTC
+++ include/sm/mapcnf.h
@@ -42,7 +42,7 @@ enum mapspec_kind_E
 	, MST_BHT	= 5
 	, MST_CDB	= 6
 	, MST_TST	= 7
-} mapspec_kind;
+};
 typedef enum mapspec_kind_E mapspec_kind_T;
 
 #define SM_MAPSPEC(what)	\
