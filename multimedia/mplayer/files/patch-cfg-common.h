--- cfg-common.h.orig	Sat Feb  8 21:52:25 2003
+++ cfg-common.h	Fri Aug 29 11:08:51 2003
@@ -279,8 +279,8 @@
 	{"alsa", &tv_param_alsa, CONF_TYPE_FLAG, 0, 0, 1, NULL},
 #endif
 	{"adevice", &tv_param_adevice, CONF_TYPE_STRING, 0, 0, 0, NULL},
+#endif	
 	{"audioid", &tv_param_audio_id, CONF_TYPE_INT, CONF_RANGE, 0, 9, NULL},
-#endif
 	{NULL, NULL, 0, 0, 0, 0, NULL}
 };
 #endif
