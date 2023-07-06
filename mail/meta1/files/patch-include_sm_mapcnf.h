--- include/sm/mapcnf.h.orig	2020-12-27 19:02:05 UTC
+++ include/sm/mapcnf.h
@@ -50,7 +50,7 @@ typedef enum mapspec_kind_E mapspec_kind_T;
 	sm_map_P		 mst_##what##_map;	\
 	char			*mst_##what##_name;	\
 	char			*mst_##what##_type;	\
-	sm_ret_T		*mst_##what##_ret
+	sm_ret_T		 mst_##what##_ret
 
 #define SM_MAPSPEC_FL_IMPLDET	0x00000001u
 
