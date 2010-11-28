--- channels/chan_sip.c.orig	2008-06-10 00:46:46.000000000 -0700
+++ channels/chan_sip.c	2008-06-10 00:46:46.000000000 -0700
@@ -496,7 +496,7 @@
 #define DEFAULT_MOHINTERPRET    "default"
 #define DEFAULT_MOHSUGGEST      ""
 #define DEFAULT_VMEXTEN 	"asterisk"
-#define DEFAULT_CALLERID 	"asterisk"
+#define DEFAULT_CALLERID 	"Unknown"
 #define DEFAULT_NOTIFYMIME 	"application/simple-message-summary"
 #define DEFAULT_MWITIME 	10
 #define DEFAULT_ALLOWGUEST	TRUE
