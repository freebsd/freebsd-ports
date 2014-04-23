Index: crypto/openssl/ssl/s3_pkt.c
===================================================================
--- ssl/s3_pkt.c	(revision 264309)
+++ ssl/s3_pkt.c	(working copy)
@@ -1055,7 +1055,7 @@ start:
				{
				s->rstate=SSL_ST_READ_HEADER;
				rr->off=0;
-				if (s->mode & SSL_MODE_RELEASE_BUFFERS)
+				if (s->mode & SSL_MODE_RELEASE_BUFFERS && s->s3->rbuf.left == 0)
					ssl3_release_read_buffer(s);
				}
			}
