--- a/xine_input_vdr.c
+++ b/xine_input_vdr.c
@@ -5526,7 +5526,7 @@ static int connect_tcp_data_stream(vdr_i
     LOGERR("Data stream write error (TCP)");
   } else if( XIO_READY != io_select_rd(fd_data)) {
     LOGERR("Data stream poll failed (TCP)");
-  } else if((n=read(fd_data, tmpbuf, sizeof(tmpbuf))) <= 0) {
+  } else if((n=read(fd_data, tmpbuf, sizeof("DATA\r\n") - 1)) <= 0) {
     LOGERR("Data stream read failed (TCP)");
   } else if(n<6 || strncmp(tmpbuf, "DATA\r\n", 6)) {
     tmpbuf[n] = 0;
