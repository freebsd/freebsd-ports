--- ssl/s3_pkt.c.orig	2014-03-17 17:14:20.000000000 +0100
+++ ssl/s3_pkt.c	2014-05-03 18:07:28.000000000 +0200
@@ -657,6 +657,10 @@
 		if (i <= 0)
 			return(i);
 		/* if it went, fall through and send more stuff */
+		/* we may have released our buffer, so get it again */
+		if (wb->buf == NULL)
+			if (!ssl3_setup_write_buffer(s))
+				return -1;
 		}
 
 	if (len == 0 && !create_empty_fragment)
@@ -1055,7 +1059,7 @@
 				{
 				s->rstate=SSL_ST_READ_HEADER;
 				rr->off=0;
-				if (s->mode & SSL_MODE_RELEASE_BUFFERS)
+				if (s->mode & SSL_MODE_RELEASE_BUFFERS && s->s3->rbuf.left == 0)
 					ssl3_release_read_buffer(s);
 				}
 			}
