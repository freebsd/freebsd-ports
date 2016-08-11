--- server/access-file.c.orig	2015-11-12 02:40:40 UTC
+++ server/access-file.c
@@ -221,10 +221,10 @@ write_block_data_cb (struct bufferevent 
         bev->cbarg = data->saved_cb_arg;
 
         /* Resume reading incomming requests. */
-        evhtp_request_resume (data->req);
-
         evhtp_send_reply_end (data->req);
 
+	evhtp_request_resume (data->req);
+
         free_sendblock_data (data);
         return;
     }
@@ -306,10 +306,10 @@ next:
             bev->cbarg = data->saved_cb_arg;
 
             /* Resume reading incomming requests. */
-            evhtp_request_resume (data->req);
-
             evhtp_send_reply_end (data->req);
 
+	    evhtp_request_resume (data->req);
+
             free_sendfile_data (data);
             return;
         }
@@ -403,10 +403,10 @@ write_dir_data_cb (struct bufferevent *b
             bev->cbarg = data->saved_cb_arg;
 
             /* Resume reading incomming requests. */
-            evhtp_request_resume (data->req);
-
             evhtp_send_reply_end (data->req);
 
+	    evhtp_request_resume (data->req);
+
             free_senddir_data (data);
             return;
         }
@@ -710,10 +710,10 @@ finish_file_range_request (struct buffer
     bev->cbarg = data->saved_cb_arg;
 
     /* Resume reading incomming requests. */
-    evhtp_request_resume (data->req);
-
     evhtp_send_reply_end (data->req);
 
+    evhtp_request_resume (data->req);
+
     free_send_file_range_data (data);
 }
 
