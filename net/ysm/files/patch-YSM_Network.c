--- src/YSM_Network.c.orig	Wed Nov 13 18:18:35 2002
+++ src/YSM_Network.c	Wed Nov 13 18:26:12 2002
@@ -3977,6 +3977,7 @@
 /* offline message variables */
 int		uin,mlen;
 char		*message,MsgType,MsgFlags,Msglen[2]; 
+char		*data_conv = 0;
 char		o_month = 0, o_day = 0, o_hour = 0, o_minutes = 0;
 YSM_SLAVE	*YSM_Query;
 
@@ -4140,13 +4141,28 @@
 						o_hour,
 						o_minutes,
 						NORMAL);
-
+#ifdef YSM_USE_ICONV
+		if( YSM_Iconv(  YSM_SETTING_CHARSET_TRANS,
+				YSM_SETTING_CHARSET_LOCAL,
+				message,
+				&data_conv,
+				YSM_ICONV_MAXLEN) < 0 )
+		data_conv = strdup (message);
+				YSM_DisplayMsg (YSM_MESSAGE_NORMAL,
+						uin,
+						0x0,
+						mlen, data_conv,
+						YSM_Query ? YSM_Query->NickName : NULL,
+						YSM_Query ? YSM_Query->LogFlag : 0x0);
+				free(data_conv);
+#else
 				YSM_DisplayMsg (YSM_MESSAGE_NORMAL,
 						uin,
 						0x0,
 						mlen, message,
 						YSM_Query ? YSM_Query->NickName : NULL,
 						YSM_Query ? YSM_Query->LogFlag : 0x0);
+#endif
 
 						break;
 
