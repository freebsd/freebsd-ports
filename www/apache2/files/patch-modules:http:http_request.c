--- modules/http/http_request.c.orig	26 Jun 2002 19:45:06 -0000	1.150
+++ modules/http/http_request.c	27 Jun 2002 04:40:47 -0000	1.151
@@ -383,8 +383,6 @@
         f = f->next;
     }
 
-    ap_add_input_filter("HTTP_IN", NULL, new, new->connection);
-
     apr_table_setn(new->subprocess_env, "REDIRECT_STATUS",
                    apr_itoa(r->pool, r->status));
