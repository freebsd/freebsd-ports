--- ./routing.c.orig	2010-08-29 06:51:52.000000000 +0200
+++ ./routing.c	2010-09-10 16:34:10.586680517 +0200
@@ -63,7 +63,7 @@
 void uwsgi_route_action_wsgi(struct uwsgi_server *uwsgi, struct wsgi_request *wsgi_req, struct uwsgi_route *ur) {
 
 	int i;
-	PyObject *route_py_callbase, *route_py_dict;
+	PyObject *route_py_callbase = NULL, *route_py_dict = NULL;
 
 	uwsgi_log("managing WSGI route...\n");
         if (ur->callable == NULL) {
@@ -106,7 +106,7 @@
 
 void uwsgi_route_action_uwsgi(struct uwsgi_server *uwsgi, struct wsgi_request *wsgi_req, struct uwsgi_route *ur) {
 
-	PyObject *route_py_callbase, *route_py_dict;
+	PyObject *route_py_callbase = NULL, *route_py_dict = NULL;
 	int i;
 
 	uwsgi_log("managing uwsgi route...\n");
