--- lib/ftpaths.h.in	Tue Jul 17 09:51:05 2001
+++ lib/ftpaths.h.in	Sat Jan 12 06:28:15 2002
@@ -29,11 +29,11 @@
 #ifndef FTPATHS_H
 #define FTPATHS_H
 
-#define FT_FILE_MAP             "@localstatedir@/cfg/map"
+#define FT_FILE_MAP             "@localstatedir@/etc/flow-tools/map"
 
-#define FT_FILE_IP_PROT         "@localstatedir@/sym/ip-prot"
-#define FT_FILE_IP_CLASS        "@localstatedir@/sym/ip-class"
-#define FT_FILE_TCP_PORT        "@localstatedir@/sym/tcp-port"
-#define FT_FILE_ASN             "@localstatedir@/sym/asn"
+#define FT_FILE_IP_PROT         "@localstatedir@/share/flow-tools/ip-prot"
+#define FT_FILE_IP_CLASS        "@localstatedir@/share/flow-tools/ip-class"
+#define FT_FILE_TCP_PORT        "@localstatedir@/share/flow-tools/tcp-port"
+#define FT_FILE_ASN             "@localstatedir@/share/flow-tools/asn"
 
 #endif /* FTPATHS_H */
