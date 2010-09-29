--- channels/chan_sip.c.orig	2010-05-28 23:57:40.000000000 +0600
+++ channels/chan_sip.c	2010-08-11 10:47:07.000000000 +0600
@@ -980,7 +980,7 @@
 #define DEFAULT_MOHINTERPRET    "default"	/*!< The default music class */
 #define DEFAULT_MOHSUGGEST      ""
 #define DEFAULT_VMEXTEN 	"asterisk"	/*!< Default voicemail extension */
-#define DEFAULT_CALLERID 	"asterisk"	/*!< Default caller ID */
+#define DEFAULT_CALLERID 	"Unknown"	/*!< Default caller ID */
 #define DEFAULT_NOTIFYMIME 	"application/simple-message-summary"
 #define DEFAULT_ALLOWGUEST	TRUE
 #define DEFAULT_RTPKEEPALIVE	0		/*!< Default RTPkeepalive setting */
