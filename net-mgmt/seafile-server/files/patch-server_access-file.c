--- server/access-file.c.orig	2016-10-09 09:30:49 UTC
+++ server/access-file.c
@@ -224,10 +224,10 @@ write_block_data_cb (struct bufferevent 
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
@@ -309,10 +309,10 @@ next:
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
@@ -406,10 +406,10 @@ write_dir_data_cb (struct bufferevent *b
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
@@ -697,10 +697,10 @@ finish_file_range_request (struct buffer
     bev->cbarg = data->saved_cb_arg;
 
     /* Resume reading incomming requests. */
-    evhtp_request_resume (data->req);
-
     evhtp_send_reply_end (data->req);
 
+    evhtp_request_resume (data->req);
+
     free_send_file_range_data (data);
 }
 
