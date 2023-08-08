--- ThirdParty/cgns/vtkcgns/src/adfh/ADFH.c.orig	2022-10-02 11:37:19 UTC
+++ ThirdParty/cgns/vtkcgns/src/adfh/ADFH.c
@@ -287,6 +287,10 @@ if (mta_root == NULL){set_error(ADFH_ERR_ROOTNULL, err
 #define CMP_OINFO(r,n) ((r)->fileno==(n)->fileno && \
                         (r)->addr==(n)->addr && (r)->addr != HADDR_UNDEF)
 
+#if H5_VERSION_GE(1,12,0)
+#undef H5L_info_t
+#define H5L_info_t H5L_info2_t
+#endif
 
 static herr_t gfind_by_name(hid_t, const char *, const H5L_info_t*, void *);
 static herr_t find_by_name(hid_t, const char *, const H5A_info_t*, void *);
