--- lib/ftpaths.h	2003/04/03 18:24:08
+++ lib/ftpaths.h	2003/04/03 18:38:09
@@ -29,16 +29,16 @@
 #ifndef FTPATHS_H
 #define FTPATHS_H
 
-#define FT_PATH_CFG_MAP             "/usr/local/netflow/var/cfg/map.cfg"
-#define FT_PATH_CFG_TAG             "/usr/local/netflow/var/cfg/tag.cfg"
-#define FT_PATH_CFG_FILTER          "/usr/local/netflow/var/cfg/filter.cfg"
-#define FT_PATH_CFG_STAT            "/usr/local/netflow/var/cfg/stat.cfg"
-#define FT_PATH_CFG_MASK            "/usr/local/netflow/var/cfg/mask.cfg"
+#define FT_PATH_CFG_MAP             "/usr/local/etc/flow-tools/map.cfg"
+#define FT_PATH_CFG_TAG             "/usr/local/etc/flow-tools/tag.cfg"
+#define FT_PATH_CFG_FILTER          "/usr/local/etc/flow-tools/filter.cfg"
+#define FT_PATH_CFG_STAT            "/usr/local/etc/flow-tools/stat.cfg"
+#define FT_PATH_CFG_MASK            "/usr/local/etc/flow-tools/mask.cfg"
 
-#define FT_PATH_SYM_IP_PROT         "/usr/local/netflow/var/sym/ip-prot.sym"
-#define FT_PATH_SYM_IP_TYPE         "/usr/local/netflow/var/sym/ip-type.sym"
-#define FT_PATH_SYM_TCP_PORT        "/usr/local/netflow/var/sym/tcp-port.sym"
-#define FT_PATH_SYM_ASN             "/usr/local/netflow/var/sym/asn.sym"
-#define FT_PATH_SYM_TAG             "/usr/local/netflow/var/sym/tag.sym"
+#define FT_PATH_SYM_IP_PROT         "/usr/local/share/flow-tools/ip-prot.sym"
+#define FT_PATH_SYM_IP_TYPE         "/usr/local/share/flow-tools/ip-type.sym"
+#define FT_PATH_SYM_TCP_PORT        "/usr/local/share/flow-tools/tcp-port.sym"
+#define FT_PATH_SYM_ASN             "/usr/local/share/flow-tools/asn.sym"
+#define FT_PATH_SYM_TAG             "/usr/local/share/flow-tools/tag.sym"
 
 #endif /* FTPATHS_H */
--- lib/ftpaths.h.in	2003/04/03 18:24:08
+++ lib/ftpaths.h.in	2003/04/03 18:38:09
@@ -29,16 +29,16 @@
 #ifndef FTPATHS_H
 #define FTPATHS_H
 
-#define FT_PATH_CFG_MAP             "@localstatedir@/cfg/map.cfg"
-#define FT_PATH_CFG_TAG             "@localstatedir@/cfg/tag.cfg"
-#define FT_PATH_CFG_FILTER          "@localstatedir@/cfg/filter.cfg"
-#define FT_PATH_CFG_STAT            "@localstatedir@/cfg/stat.cfg"
-#define FT_PATH_CFG_MASK            "@localstatedir@/cfg/mask.cfg"
+#define FT_PATH_CFG_MAP             "@localstatedir@/etc/flow-tools/map.cfg"
+#define FT_PATH_CFG_TAG             "@localstatedir@/etc/flow-tools/tag.cfg"
+#define FT_PATH_CFG_FILTER          "@localstatedir@/etc/flow-tools/filter.cfg"
+#define FT_PATH_CFG_STAT            "@localstatedir@/etc/flow-tools/stat.cfg"
+#define FT_PATH_CFG_MASK            "@localstatedir@/etc/flow-tools/mask.cfg"
 
-#define FT_PATH_SYM_IP_PROT         "@localstatedir@/sym/ip-prot.sym"
-#define FT_PATH_SYM_IP_TYPE         "@localstatedir@/sym/ip-type.sym"
-#define FT_PATH_SYM_TCP_PORT        "@localstatedir@/sym/tcp-port.sym"
-#define FT_PATH_SYM_ASN             "@localstatedir@/sym/asn.sym"
-#define FT_PATH_SYM_TAG             "@localstatedir@/sym/tag.sym"
+#define FT_PATH_SYM_IP_PROT         "@localstatedir@/share/flow-tools/ip-prot.sym"
+#define FT_PATH_SYM_IP_TYPE         "@localstatedir@/share/flow-tools/ip-type.sym"
+#define FT_PATH_SYM_TCP_PORT        "@localstatedir@/share/flow-tools/tcp-port.sym"
+#define FT_PATH_SYM_ASN             "@localstatedir@/share/flow-tools/asn.sym"
+#define FT_PATH_SYM_TAG             "@localstatedir@/share/flow-tools/tag.sym"
 
 #endif /* FTPATHS_H */
