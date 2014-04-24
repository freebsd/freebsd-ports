--- libvo/x11_common.c	2013-10-16 17:07:12.000000000 -0700
+++ libvo/x11_common.c	2014-04-16 09:15:27.888658589 -0700
@@ -430,7 +430,7 @@
     }
 
     // Required so that XLookupString returns UTF-8
-    if (!setlocale(LC_CTYPE, "C.UTF-8") && !setlocale(LC_CTYPE, "en_US.utf8"))
+    if (!setlocale(LC_CTYPE, "en_US.UTF-8"))
         mp_msg(MSGT_VO, MSGL_WARN, "Could not find a UTF-8 locale, some keys will not be handled.\n");
     XSetErrorHandler(x11_errorhandler);
