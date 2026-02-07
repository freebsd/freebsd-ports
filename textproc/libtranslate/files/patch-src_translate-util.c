--- src/translate-util.c.orig	Mon Jan 17 17:45:45 2005
+++ src/translate-util.c	Fri Dec 30 22:26:26 2005
@@ -136,7 +136,7 @@
   g_return_val_if_fail(big != NULL, NULL);
   g_return_val_if_fail(little != NULL, NULL);
 
-  lower_big = g_ascii_strdown(big, big_len);
+  lower_big = g_ascii_strdown(big, (int) big_len);
   lower_little = g_ascii_strdown(little, -1);
 
   s = strstr(lower_big, lower_little);
