Index: src/mod_simple_vhost.c
===================================================================
--- src/mod_simple_vhost.c	(revision 2398)
+++ src/mod_simple_vhost.c	(revision 2399)
@@ -249,6 +249,8 @@
 				return HANDLER_GO_ON;
 			} else {
 				buffer_copy_string_buffer(con->server_name, p->conf.default_host);
+				buffer_copy_string_buffer(con->physical.doc_root, p->doc_root);
+
 				/* do not cache default host */
 				return HANDLER_GO_ON;
 			}
