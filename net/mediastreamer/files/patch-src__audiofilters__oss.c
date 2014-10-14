--- src/audiofilters/oss.c.orig
+++ src/audiofilters/oss.c
@@ -364,7 +364,11 @@
 			}
 		}
 		if (d->pcmfd_write>=0){
-			if (d->write_started){
+			int bufsize = 0;
+			ioctl(d->pcmfd_write, SNDCTL_DSP_GETODELAY, &bufsize);
+			if (bufsize >= bsize){
+				/* wait for buffer to empty */
+			}else if (d->write_started){
 				err=ms_bufferizer_read(d->bufferizer,wtmpbuff,bsize);
 				if (err==bsize){
 					err=write(d->pcmfd_write,wtmpbuff,bsize);
