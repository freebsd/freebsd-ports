--- channels/sip/include/sip.h.orig	2015-07-24 22:06:05 UTC
+++ channels/sip/include/sip.h
@@ -190,7 +190,7 @@
 #define DEFAULT_MOHINTERPRET   "default"  /*!< The default music class */
 #define DEFAULT_MOHSUGGEST     ""
 #define DEFAULT_VMEXTEN        "asterisk" /*!< Default voicemail extension */
-#define DEFAULT_CALLERID       "asterisk" /*!< Default caller ID */
+#define DEFAULT_CALLERID       "Unknown" /*!< Default caller ID */
 #define DEFAULT_MWI_FROM       ""
 #define DEFAULT_NOTIFYMIME     "application/simple-message-summary"
 #define DEFAULT_ALLOWGUEST     TRUE
