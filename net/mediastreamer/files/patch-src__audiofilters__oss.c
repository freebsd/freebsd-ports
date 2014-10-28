--- src/audiofilters/oss.c.orig
+++ src/audiofilters/oss.c
@@ -41,7 +41,7 @@
 {
 	int p=0,cond=0;
 	int i=0;
-	int min_size=0,blocksize=512;
+	int min_size=0, blocksize=0;
 	int err;
 	
 	//g_message("opening sound device");
@@ -77,54 +77,18 @@
 	if (err<0){
 		ms_warning("oss_open: can't set mono/stereo mode:%s.",strerror(errno));
 	}
-	
-	if (rate==16000) blocksize=4096;	/* oss emulation is not very good at 16khz */
-	else blocksize=blocksize*(rate/8000);
 
 	ioctl(fd, SNDCTL_DSP_GETBLKSIZE, &min_size);
 
-	/**
-	 * first try SNDCTL_DSP_SETFRAGMENT
-	 */
-	if (min_size>blocksize) {
-		int size_selector=0;
-		while ((blocksize >> size_selector) != 1)size_selector++; /*compute selector blocksize = 1<< size_selector*/
-		int frag = (2 << 16) | (size_selector);
-		if (ioctl(fd, SNDCTL_DSP_SETFRAGMENT, &frag) == -1) {
-			ms_warning("This OSS driver does not support trying SNDCTL_DSP_SETFRAGMENT");
-			ioctl(fd, SNDCTL_DSP_GETBLKSIZE, &min_size);
-
-			/* try to subdivide BLKSIZE to reach block size if necessary */
-			if (min_size>blocksize)
-			{
-				cond=1;
-				p=min_size/blocksize;
-				while(cond)
-				{
-					i=ioctl(fd, SNDCTL_DSP_SUBDIVIDE, &p);
-					ms_message("subdivide bloc min_size [%i] block_size [%i]  said error=%i,errno=%i\n",min_size,blocksize,i,errno);
-					if ((i!=0) || (p==1)) cond=0;
-					else p=p/2;
-				}
-			}
-			ioctl(fd, SNDCTL_DSP_GETBLKSIZE, &min_size);
-		} else {
-			/*it's working*/
-			min_size=1 << (frag&0x0FFFF);
-			ms_message("Max fragment=%x, size selector=%x block size=%i",frag>>16,frag&0x0FFFF,min_size);
-		}
-	}
-
-	if (min_size>blocksize)
-	{
-		ms_warning("dsp block size set to %i.",min_size);
-	}else{
-		/* no need to access the card with less latency than needed*/
-		min_size=blocksize;
-	}
+	/* compute 20ms buffer */
+	blocksize = (rate / 50) * 2;
+	if (stereo)
+		blocksize *= 2;
+	if (min_size > blocksize)
+		blocksize = min_size;
 
 	ms_message("/dev/dsp opened: rate=%i,bits=%i,stereo=%i blocksize=%i.",
-			rate,bits,stereo,min_size);
+			rate,bits,stereo,blocksize);
 	
 	/* start recording !!! Alex */
 	{
@@ -134,7 +98,7 @@
 		res=ioctl(fd, SNDCTL_DSP_SETTRIGGER, &fl);
 		if (res<0) ms_warning("OSS_TRIGGER: %s",strerror(errno));
 	} 
-	*minsz=min_size;
+	*minsz=blocksize;
 	return fd;
 }
 
@@ -364,7 +328,11 @@
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
