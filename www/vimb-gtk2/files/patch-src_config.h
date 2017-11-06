--- src/config.h.orig	2017-04-11 19:31:27 UTC
+++ src/config.h
@@ -27,7 +27,7 @@
 /* highlight search results */
 #define FEATURE_SEARCH_HIGHLIGHT
 /* disable scrollbars */
-#define FEATURE_NO_SCROLLBARS
+/*#define FEATURE_NO_SCROLLBARS*/
 /* disable X window embedding */
 /* #define FEATURE_NO_XEMBED */
 /* show page title in url completions */
@@ -69,7 +69,7 @@
 #define SHOWCMD_LEN                 10
 
 /* parh to crt file for the certificate validation */
-#define SETTING_CA_BUNDLE           "/etc/ssl/certs/ca-certificates.crt"
+#define SETTING_CA_BUNDLE           "/usr/local/share/certs/ca-root-nss.crt"
 #define SETTING_MAX_CONNS           25
 #define SETTING_MAX_CONNS_PER_HOST   5
 /* default font size for fonts in webview */
