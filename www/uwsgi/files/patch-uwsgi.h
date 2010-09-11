--- ./uwsgi.h.orig	2010-09-10 16:34:33.959880773 +0200
+++ ./uwsgi.h	2010-09-10 16:34:41.542504418 +0200
@@ -1018,7 +1018,7 @@
 #endif
 
 int uwsgi_load_plugin(struct uwsgi_server *, int, char *, char *, int);
-void embed_plugins(struct uwsgi_server *);
+int embed_plugins(struct uwsgi_server *);
 
 
 // PLUGINS
