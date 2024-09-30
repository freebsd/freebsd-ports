--- src/libcharon/plugins/kernel_pfkey/kernel_pfkey_ipsec.c.orig	2023-06-08 10:35:17 UTC
+++ src/libcharon/plugins/kernel_pfkey/kernel_pfkey_ipsec.c
@@ -765,6 +765,11 @@ ENUM(sadb_ext_type_names, SADB_EXT_RESERVED, SADB_EXT_
 	"SADB_X_EXT_SA_REPLAY",
 	"SADB_X_EXT_NEW_ADDRESS_SRC",
 	"SADB_X_EXT_NEW_ADDRESS_DST",
+#ifdef SADB_X_EXT_IF_HW_OFFL
+	"SADB_X_EXT_LFT_CUR_SW_OFFL",
+	"SADB_X_EXT_LFT_CUR_HW_OFFL",
+	"SADB_X_EXT_IF_HW_OFFL",
+#endif
 #endif /* __linux__ */
 #endif /* __APPLE__ */
 );
