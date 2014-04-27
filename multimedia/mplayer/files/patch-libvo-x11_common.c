--- libvo/x11_common.c.orig	2014-02-08 21:39:02.000000000 +0100
+++ libvo/x11_common.c	2014-04-19 14:43:53.715749607 +0200
@@ -430,7 +430,7 @@
     }
 
     // Required so that XLookupString returns UTF-8
-    if (!setlocale(LC_CTYPE, "C.UTF-8") && !setlocale(LC_CTYPE, "en_US.utf8"))
+    if (!setlocale(LC_CTYPE, "en_US.UTF-8"))
         mp_msg(MSGT_VO, MSGL_WARN, MSGTR_CouldntFindUTF8Locale);
     XSetErrorHandler(x11_errorhandler);
 
