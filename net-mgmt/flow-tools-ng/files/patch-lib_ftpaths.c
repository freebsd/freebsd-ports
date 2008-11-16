--- lib/ftpaths.c.orig	2008-08-02 02:19:52.000000000 +0900
+++ lib/ftpaths.c	2008-08-02 02:20:47.000000000 +0900
@@ -1,18 +1,18 @@
 #include <ftlib.h>
 
 static const char* ftpaths[] = {
-  [_FT_PATH_CFG_MAP] = SYSCONFDIR "/cfg/map.cfg",
-  [_FT_PATH_CFG_TAG] = SYSCONFDIR "/cfg/tag.cfg",
-  [_FT_PATH_CFG_FILTER] = SYSCONFDIR "/cfg/filter.cfg",
-  [_FT_PATH_CFG_STAT] = SYSCONFDIR "/cfg/stat.cfg",
-  [_FT_PATH_CFG_MASK] = SYSCONFDIR "/cfg/mask.cfg",
-  [_FT_PATH_CFG_XLATE] = SYSCONFDIR "/cfg/xlate.cfg",
+  [_FT_PATH_CFG_MAP] = SYSCONFDIR "/flow-tools/map.cfg",
+  [_FT_PATH_CFG_TAG] = SYSCONFDIR "/flow-tools/tag.cfg",
+  [_FT_PATH_CFG_FILTER] = SYSCONFDIR "/flow-tools/filter.cfg",
+  [_FT_PATH_CFG_STAT] = SYSCONFDIR "/flow-tools/stat.cfg",
+  [_FT_PATH_CFG_MASK] = SYSCONFDIR "/flow-tools/mask.cfg",
+  [_FT_PATH_CFG_XLATE] = SYSCONFDIR "/flow-tools/xlate.cfg",
 
-  [_FT_PATH_SYM_IP_PROT] = SYSCONFDIR "/sym/ip-prot.sym",
-  [_FT_PATH_SYM_IP_TYPE] = SYSCONFDIR "/sym/ip-type.sym",
-  [_FT_PATH_SYM_TCP_PORT] = SYSCONFDIR "/sym/tcp-port.sym",
-  [_FT_PATH_SYM_ASN] = SYSCONFDIR "/sym/asn.sym",
-  [_FT_PATH_SYM_TAG] = SYSCONFDIR "/sym/tag.sym"
+  [_FT_PATH_SYM_IP_PROT] = SYSCONFDIR "/flow-tools/ip-prot.sym",
+  [_FT_PATH_SYM_IP_TYPE] = SYSCONFDIR "/flow-tools/ip-type.sym",
+  [_FT_PATH_SYM_TCP_PORT] = SYSCONFDIR "/flow-tools/tcp-port.sym",
+  [_FT_PATH_SYM_ASN] = SYSCONFDIR "/flow-tools/asn.sym",
+  [_FT_PATH_SYM_TAG] = SYSCONFDIR "/flow-tools/tag.sym"
 };
 
 const char *ft_get_path(enum ft_config_path pathid) {
