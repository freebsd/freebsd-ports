--- lib/ftpaths.h.in	Thu Aug 15 17:28:04 2002
+++ lib/ftpaths.h.in	Mon Apr 22 11:29:07 2002
@@ -29,16 +29,16 @@
 #ifndef FTPATHS_H
 #define FTPATHS_H
 
-#define FT_PATH_CFG_MAP             "@localstatedir@/cfg/map"
-#define FT_PATH_CFG_TAG             "@localstatedir@/cfg/tag"
-#define FT_PATH_CFG_FILTER          "@localstatedir@/cfg/filter"
-#define FT_PATH_CFG_STAT            "@localstatedir@/cfg/stat"
+#define FT_PATH_CFG_MAP             "@localstatedir@/etc/flow-tools/map"
+#define FT_PATH_CFG_TAG             "@localstatedir@/etc/flow-tools/tag"
+#define FT_PATH_CFG_FILTER          "@localstatedir@/etc/flow-tools/filter"
+#define FT_PATH_CFG_STAT            "@localstatedir@/etc/flow-tools/stat"
 
-#define FT_PATH_SYM_IP_PROT         "@localstatedir@/sym/ip-prot"
-#define FT_PATH_SYM_IP_CLASS        "@localstatedir@/sym/ip-class"
-#define FT_PATH_SYM_IP_TYPE         "@localstatedir@/sym/ip-type"
-#define FT_PATH_SYM_TCP_PORT        "@localstatedir@/sym/tcp-port"
-#define FT_PATH_SYM_ASN             "@localstatedir@/sym/asn"
-#define FT_PATH_SYM_TAG             "@localstatedir@/sym/tag"
+#define FT_PATH_SYM_IP_PROT         "@localstatedir@/share/flow-tools/ip-prot"
+#define FT_PATH_SYM_IP_CLASS        "@localstatedir@/share/flow-tools/ip-class"
+#define FT_PATH_SYM_IP_TYPE         "@localstatedir@/share/flow-tools/ip-type"
+#define FT_PATH_SYM_TCP_PORT        "@localstatedir@/share/flow-tools/tcp-port"
+#define FT_PATH_SYM_ASN             "@localstatedir@/share/flow-tools/asn"
+#define FT_PATH_SYM_TAG             "@localstatedir@/share/flow-tools/tag"
 
 #endif /* FTPATHS_H */
