--- import/af6_decore.cpp.orig	Sun Jul  3 17:03:28 2005
+++ import/af6_decore.cpp	Sun Jul  3 17:03:48 2005
@@ -213,7 +213,7 @@
 
       /* send sync token */
       fflush(stdout);
-      p_write(decode->fd_out, sync_str, sizeof(sync_str));
+      p_write(decode->fd_out, (uint8_t*)sync_str, sizeof(sync_str));
 
       /* frame serve loop */
       /* by default decode->frame_limit[0]=0 and ipipe->frame_limit[1]=LONG_MAX so all frames are decoded */
@@ -268,13 +268,13 @@
 		    }
 		  }
 		  /* write unpacked frame */
-		  if(p_write(decode->fd_out, pack_buffer, pack_size)!= pack_size) {
+		  if(p_write(decode->fd_out, (uint8_t*)pack_buffer, pack_size)!= pack_size) {
 		    fprintf(stderr,"(%s) ERROR: Pipe write error!\n",__FILE__);
 		    break;
 		  }
 		} else {
 		  /* directly write raw frame */
-		  if(p_write(decode->fd_out, buf, buffer_size)!= buffer_size) {
+		  if(p_write(decode->fd_out, (uint8_t*)buf, buffer_size)!= buffer_size) {
 		    fprintf(stderr,"(%s) ERROR: Pipe write error!\n",__FILE__);
 		    break;
 		  }
@@ -368,7 +368,7 @@
 
       /* send sync token */
       fflush(stdout);
-      p_write(decode->fd_out, sync_str, sizeof(sync_str));
+      p_write(decode->fd_out, (uint8_t*)sync_str, sizeof(sync_str));
       
       /* sample server loop */
       while(!ars->Eof()) { 
@@ -393,18 +393,18 @@
 	{
 		if ( s_byte_read - ret_size <(unsigned int)decode->frame_limit[0])
 		{
-			if((unsigned int)p_write(decode->fd_out,buffer+(ret_size-(s_byte_read-decode->frame_limit[0])),(s_byte_read-decode->frame_limit[0]))!=(unsigned int)(s_byte_read-decode->frame_limit[0])) 
+			if((unsigned int)p_write(decode->fd_out,(uint8_t*)(buffer+(ret_size-(s_byte_read-decode->frame_limit[0]))),(s_byte_read-decode->frame_limit[0]))!=(unsigned int)(s_byte_read-decode->frame_limit[0])) 
 			  	break;
 		}
 		else
 		{
-			if((unsigned int)p_write(decode->fd_out,buffer,ret_size)!=ret_size) 
+			if((unsigned int)p_write(decode->fd_out,(uint8_t*)buffer,ret_size)!=ret_size) 
 			  break;
 		}
 	}
 	else if ((s_byte_read> decode->frame_limit[0]) && (s_byte_read - ret_size <=(unsigned int)decode->frame_limit[1]))
 	{
-		if((unsigned int)p_write(decode->fd_out,buffer,(s_byte_read-decode->frame_limit[1]))!=(unsigned int)(s_byte_read-decode->frame_limit[1])) 
+		if((unsigned int)p_write(decode->fd_out,(uint8_t*)buffer,(s_byte_read-decode->frame_limit[1]))!=(unsigned int)(s_byte_read-decode->frame_limit[1])) 
 		 	break;
 	}
 	else if (s_byte_read - ret_size >(unsigned int)decode->frame_limit[1])
