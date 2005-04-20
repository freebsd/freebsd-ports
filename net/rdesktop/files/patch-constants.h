--- constants.h.orig	2004-11-03 16:56:44.000000000 +0300
+++ constants.h	2004-12-15 11:47:49.583973715 +0300
@@ -21,6 +21,9 @@
 /* TCP port for Remote Desktop Protocol */
 #define TCP_PORT_RDP 3389
 
+#define DEFAULT_CODEPAGE	"UTF-8"
+#define WINDOWS_CODEPAGE	"UTF-16"
+
 /* ISO PDU codes */
 enum ISO_PDU_CODE
 {
diff -uNr licence.c.orig licence.c
