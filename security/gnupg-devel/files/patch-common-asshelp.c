--- common/asshelp.c.orig	Wed Mar 23 09:28:16 2005
+++ common/asshelp.c	Wed Mar 23 09:29:10 2005
@@ -150,7 +150,7 @@
 #endif
   if (opt_lc_messages || (dft_ttyname && dft_lc))
     {
-      err = send_one_option (ctx, errsource, "display", 
+      err = send_one_option (ctx, errsource, "lc-messages", 
                              opt_lc_messages ? opt_lc_messages : dft_lc);
     }
 #if defined(HAVE_SETLOCALE) && defined(LC_MESSAGES)
