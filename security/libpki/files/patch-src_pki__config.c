--- src/pki_config.c.orig	2024-08-12 07:36:06.493686000 +0200
+++ src/pki_config.c	2024-08-12 07:40:19.265530000 +0200
@@ -17,6 +17,7 @@
 
 #define PKI_DEF_CONF_DIRS_SIZE	2
 #define LIBXML_MIN_VERSION 20600
+#define LIBXML_212_VERSION 21200
 
 #if LIBXML_VERSION < LIBXML_MIN_VERSION
 #define xmlErrorPtr void *
@@ -30,7 +31,11 @@
 #endif
 */
 
+#if LIBXML_VERSION >= LIBXML_212_VERSION
+void logXmlMessages( void *userData, const xmlError *error ) {
+#else
 void logXmlMessages( void *userData, xmlErrorPtr error ) {
+#endif
 #if LIBXML_VERSION >= LIBXML_MIN_VERSION
 	PKI_log_err( "XML I/O Error: %s", error->message);
 #else
