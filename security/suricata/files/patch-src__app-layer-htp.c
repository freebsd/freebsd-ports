--- ./src/app-layer-htp.c.orig	2012-10-03 09:44:25.000000000 -0400
+++ ./src/app-layer-htp.c	2012-10-09 18:57:24.000000000 -0400
@@ -657,14 +657,15 @@
     if (!(hstate->flags & HTP_FLAG_STATE_OPEN)) {
         SCLogDebug("opening htp handle at %p", hstate->connp);
 
-        htp_connp_open(hstate->connp, NULL, f->sp, NULL, f->dp, 0);
+        htp_connp_open(hstate->connp, NULL, f->sp, NULL, f->dp, &f->startts);
         hstate->flags |= HTP_FLAG_STATE_OPEN;
     } else {
         SCLogDebug("using existing htp handle at %p", hstate->connp);
     }
 
+    htp_time_t ts = { f->lastts_sec, 0 };
     /* pass the new data to the htp parser */
-    r = htp_connp_req_data(hstate->connp, 0, input, input_len);
+    r = htp_connp_req_data(hstate->connp, &ts, input, input_len);
 
     switch(r) {
         case STREAM_STATE_ERROR:
@@ -693,7 +694,8 @@
         hstate->connp->in_status = STREAM_STATE_CLOSED;
         // Call the parsers one last time, which will allow them
         // to process the events that depend on stream closure
-        htp_connp_req_data(hstate->connp, 0, NULL, 0);
+        htp_time_t ts = { f->lastts_sec, 0 };
+        htp_connp_req_data(hstate->connp, &ts, NULL, 0);
         hstate->flags |= HTP_FLAG_STATE_CLOSED_TS;
         SCLogDebug("stream eof encountered, closing htp handle for ts");
     }
@@ -747,7 +749,8 @@
      * reactivate it if necessary) */
     hstate->flags &=~ HTP_FLAG_NEW_BODY_SET;
 
-    r = htp_connp_res_data(hstate->connp, 0, input, input_len);
+    htp_time_t ts = { f->lastts_sec, 0 };
+    r = htp_connp_res_data(hstate->connp, &ts, input, input_len);
     switch(r) {
         case STREAM_STATE_ERROR:
             HTPHandleError(hstate);
@@ -774,7 +777,8 @@
         hstate->connp->out_status = STREAM_STATE_CLOSED;
         // Call the parsers one last time, which will allow them
         // to process the events that depend on stream closure
-        htp_connp_res_data(hstate->connp, 0, NULL, 0);
+        htp_time_t ts = { f->lastts_sec, 0 };
+        htp_connp_res_data(hstate->connp, &ts, NULL, 0);
         hstate->flags |= HTP_FLAG_STATE_CLOSED_TC;
     }
 
