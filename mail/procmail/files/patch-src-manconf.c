--- src/manconf.c.orig	Fri Aug 25 11:04:33 2000
+++ src/manconf.c	Sun Aug 27 13:12:55 2000
@@ -140,7 +140,7 @@
 sh before procmail ever sees it; it is however a necessary kludge against\1\
 overoptimising sendmail programs:\1");
 #else
-  ps("FW_content","\"|exec @BINDIR@/procmail\"");
+  ps("FW_content","\"|exec @BINDIR@/procmail || exit 75\"");
   ps("FW_comment","");
 #endif
 #else
