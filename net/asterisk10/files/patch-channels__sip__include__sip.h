--- ./channels/sip/include/sip.h.orig	2010-11-08 04:46:46.000000000 +0100
+++ ./channels/sip/include/sip.h	2010-11-08 04:47:07.000000000 +0100
@@ -180,7 +180,7 @@
 #define DEFAULT_MOHINTERPRET   "default"  /*!< The default music class */
 #define DEFAULT_MOHSUGGEST     ""
 #define DEFAULT_VMEXTEN        "asterisk" /*!< Default voicemail extension */
-#define DEFAULT_CALLERID       "asterisk" /*!< Default caller ID */
+#define DEFAULT_CALLERID       "Unknown" /*!< Default caller ID */
 #define DEFAULT_MWI_FROM       ""
 #define DEFAULT_NOTIFYMIME     "application/simple-message-summary"
 #define DEFAULT_ALLOWGUEST     TRUE
