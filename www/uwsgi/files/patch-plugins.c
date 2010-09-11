--- ./plugins.c.orig	2010-08-29 06:51:52.000000000 +0200
+++ ./plugins.c	2010-09-10 16:33:35.471808130 +0200
@@ -1,6 +1,7 @@
 #include "uwsgi.h"
 
-void embed_plugins(struct uwsgi_server *uwsgi) {
+int embed_plugins(struct uwsgi_server *uwsgi) {
+	int ret = 0;
 
 #ifdef UWSGI_EMBED_PLUGIN_PSGI
 	if (uwsgi->plugin_arg_psgi)
@@ -17,6 +18,7 @@
 		ret = uwsgi_load_plugin(uwsgi, 7, "rack_plugin.so", uwsgi->plugin_arg_rack, 0);
 #endif
 
+	return ret;
 }
 
 int uwsgi_load_plugin(struct uwsgi_server *uwsgi, int modifier, char *plugin, char *pargs, int absolute) {
