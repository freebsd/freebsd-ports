--- lib/ftpaths.h.in	Sun Apr 21 04:08:41 2002
+++ lib/ftpaths.h.in	Mon Apr 22 11:29:07 2002
@@ -29,12 +29,12 @@
 #ifndef FTPATHS_H
 #define FTPATHS_H
 
-#define FT_PATH_MAP             "@localstatedir@/cfg/map"
+#define FT_FILE_MAP             "@localstatedir@/etc/flow-tools/map"
 
-#define FT_PATH_IP_PROT         "@localstatedir@/sym/ip-prot"
-#define FT_PATH_IP_CLASS        "@localstatedir@/sym/ip-class"
-#define FT_PATH_TCP_PORT        "@localstatedir@/sym/tcp-port"
-#define FT_PATH_ASN             "@localstatedir@/sym/asn"
-#define FT_PATH_TAG             "@localstatedir@/cfg/tag_defs"
+#define FT_PATH_IP_PROT         "@localstatedir@/share/flow-tools/ip-prot"
+#define FT_PATH_IP_CLASS        "@localstatedir@/share/flow-tools/ip-class"
+#define FT_PATH_TCP_PORT        "@localstatedir@/share/flow-tools/tcp-port"
+#define FT_PATH_ASN             "@localstatedir@/share/flow-tools/asn"
+#define FT_PATH_TAG             "@localstatedir@/etc/flow-tools/tag_defs"
 
 #endif /* FTPATHS_H */
