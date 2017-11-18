--- pjsip/src/pjsip/sip_parser.c.orig	2017-11-08 02:58:18 UTC
+++ pjsip/src/pjsip/sip_parser.c
@@ -834,13 +834,13 @@ PJ_DEF(pj_status_t) pjsip_find_msg( const char *buf, p
 				  pj_bool_t is_datagram, pj_size_t *msg_size)
 {
 #if PJ_HAS_TCP
-    const char *hdr_end;
-    const char *body_start;
+    const char *volatile hdr_end;
+    const char *volatile body_start;
     const char *pos;
-    const char *line;
+    const char *volatile line;
     int content_length = -1;
     pj_str_t cur_msg;
-    pj_status_t status = PJ_SUCCESS;
+    volatile pj_status_t status = PJSIP_EMISSINGHDR;
     const pj_str_t end_hdr = { "\n\r\n", 3};
 
     *msg_size = size;
