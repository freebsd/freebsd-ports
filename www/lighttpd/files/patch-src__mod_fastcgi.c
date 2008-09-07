#
# http://trac.lighttpd.net/trac/changeset/2143
#
Index: /branches/lighttpd-1.4.x/src/mod_fastcgi.c
===================================================================
--- src/mod_fastcgi.c (revision 2119)
+++ src/mod_fastcgi.c (revision 2143)
@@ -2545,5 +2545,8 @@
 
 					if (HANDLER_ERROR != stat_cache_get_entry(srv, con, ds->value, &sce)) {
-						data_string *dcls = data_string_init();
+						data_string *dcls;
+						if (NULL == (dcls = (data_string *)array_get_unused_element(con->response.headers, TYPE_STRING))) {
+							dcls = data_response_init();
+						}
 						/* found */
 						http_chunk_append_file(srv, con, ds->value, 0, sce->st.st_size);

