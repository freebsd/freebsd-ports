--- request_common.c.orig	Thu Jun 15 10:13:10 2006
+++ request_common.c	Thu Jun 15 10:13:16 2006
@@ -654,7 +654,7 @@
 
 
 int client_parse_icap_header(request_t *req,ci_headers_list_t *h){
-     int readed=0,eoh=0;;
+     int readed=0,eoh=0;
      char *buf,*end;
      if(req->pstrblock_read_len<4)/*we need 4 bytes for the end of headers "\r\n\r\n" string*/
 	  return CI_NEEDS_MORE;
