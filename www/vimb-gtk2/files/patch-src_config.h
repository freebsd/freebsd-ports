--- src/config.h.orig	2015-12-17 19:21:00 UTC
+++ src/config.h
@@ -27,7 +27,7 @@
 /* highlight search results */
 #define FEATURE_SEARCH_HIGHLIGHT
 /* disable scrollbars */
-#define FEATURE_NO_SCROLLBARS
+/*#define FEATURE_NO_SCROLLBARS*/
 /* show page title in url completions */
 #define FEATURE_TITLE_IN_COMPLETION
 /* enable the read it later queue */
@@ -65,7 +65,7 @@
 #define SHOWCMD_LEN                 10
 
 /* parh to crt file for the certificate validation */
-#define SETTING_CA_BUNDLE           "/etc/ssl/certs/ca-certificates.crt"
+#define SETTING_CA_BUNDLE           "/usr/local/share/certs/ca-root-nss.crt"
 #define SETTING_MAX_CONNS           25
 #define SETTING_MAX_CONNS_PER_HOST   5
 /* default font size for fonts in webview */
