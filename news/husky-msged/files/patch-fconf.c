--- fconf.c.orig	Mon Jan  6 00:37:00 2003
+++ fconf.c	Mon Jan  6 00:39:10 2003
@@ -317,8 +317,12 @@
 
     if (filename == NULL)
     {
+#if defined(FIDOCONFIG_FILE)
+	filename = FIDOCONFIG_FILE;
+#else
         printf ("\r\nError: You must set the FIDOCONFIG environment variable!\n");
         return;
+#endif
     }
 
     fc_default_address_set = 0;
