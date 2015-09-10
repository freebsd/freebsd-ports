--- libvo/x11_common.c.orig	2015-05-11 20:10:01 UTC
+++ libvo/x11_common.c
@@ -430,7 +430,7 @@ int vo_init(void)
     }
 
     // Required so that XLookupString returns UTF-8
-    if (!setlocale(LC_CTYPE, "C.UTF-8") && !setlocale(LC_CTYPE, "en_US.utf8"))
+    if (!setlocale(LC_CTYPE, "en_US.UTF-8"))
         mp_msg(MSGT_VO, MSGL_WARN, MSGTR_CouldntFindUTF8Locale);
     XSetErrorHandler(x11_errorhandler);
 
