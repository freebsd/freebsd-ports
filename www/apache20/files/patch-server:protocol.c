===================================================================
RCS file: /home/cvspublic/httpd-2.0/server/protocol.c,v
retrieving revision 1.121.2.18
retrieving revision 1.121.2.19
diff -u -r1.121.2.18 -r1.121.2.19
--- server/protocol.c	2004/06/11 20:46:41	1.121.2.18
+++ server/protocol.c	2004/06/28 23:57:14	1.121.2.19
@@ -719,6 +719,23 @@
                  * continuations that span many many lines.
                  */
                 apr_size_t fold_len = last_len + len + 1; /* trailing null */
+
+                if ((fold_len - 1) > r->server->limit_req_fieldsize) {
+                    r->status = HTTP_BAD_REQUEST;
+                    /* report what we have accumulated so far before the
+                     * overflow (last_field) as the field with the problem
+                     */
+                    apr_table_setn(r->notes, "error-notes",
+                                   apr_pstrcat(r->pool,
+                                               "Size of a request header field " 
+                                               "after folding "
+                                               "exceeds server limit.<br />\n"
+                                               "<pre>\n",
+                                               ap_escape_html(r->pool, last_field),
+                                               "</pre>\n", NULL));
+                    return;
+                }
+
                 if (fold_len > alloc_len) {
                     char *fold_buf;
                     alloc_len += alloc_len;

