--- ./modules/aycryption/aycryption.c.orig	2008-08-11 00:50:44.000000000 -0400
+++ ./modules/aycryption/aycryption.c	2009-07-02 04:06:35.000000000 -0400
@@ -108,6 +108,8 @@
 
 static int aycryption_init()
 {
+	gpgme_check_version (NULL);
+
 	input_list *il = g_new0(input_list, 1);
 	plugin_info.prefs = il;
 
