--- src/audiofilters/oss.c.orig	2017-04-06 09:27:56 UTC
+++ src/audiofilters/oss.c
@@ -37,95 +37,65 @@ MSFilter *ms_oss_read_new(MSSndCard *card);
 MSFilter *ms_oss_write_new(MSSndCard *card);
 
 
-static int configure_fd(int fd, int bits,int stereo, int rate, int *minsz)
+static int configure_fd(int fd, int bits,int stereo, int rate, int *minsz, int *mindly)
 {
-	int p=0,cond=0;
-	int i=0;
-	int min_size=0,blocksize=512;
+	int p=0;
+	int min_size=0, blocksize=0;
+	int smp_size = bits / 8;
 	int err;
 
-	//g_message("opening sound device");
-	/* unset nonblocking mode */
-	/* We wanted non blocking open but now put it back to normal ; thanks Xine !*/
-	fcntl(fd, F_SETFL, fcntl(fd, F_GETFL)&~O_NONBLOCK);
+	err = 1;
+	ioctl(fd, FIONBIO, &err);
 
-	/* reset is maybe not needed but takes time*/
-	/*ioctl(fd, SNDCTL_DSP_RESET, 0); */
+	switch (bits) {
+	case 16:
+		p=AFMT_S16_NE;
+		break;
+	default:
+		close(fd);
+		return (-1);
+	}
 
-	p=AFMT_S16_NE;
-
 	err=ioctl(fd,SNDCTL_DSP_SETFMT,&p);
 	if (err<0){
 		ms_warning("oss_open: can't set sample format:%s.",strerror(errno));
+		close(fd);
+		return (-1);
 	}
 
-
-	p =  bits;  /* 16 bits */
-	err=ioctl(fd, SNDCTL_DSP_SAMPLESIZE, &p);
-	if (err<0){
-		ms_warning("oss_open: can't set sample size to %i:%s.",bits,strerror(errno));
-	}
-
 	p =  rate;  /* rate in khz*/
 	err=ioctl(fd, SNDCTL_DSP_SPEED, &p);
-	if (err<0){
+	if (err<0 || p != rate){
 		ms_warning("oss_open: can't set sample rate to %i:%s.",rate,strerror(errno));
+		close(fd);
+		return (-1);
 	}
 
 	p =  stereo;  /* stereo or not */
 	err=ioctl(fd, SNDCTL_DSP_STEREO, &p);
 	if (err<0){
 		ms_warning("oss_open: can't set mono/stereo mode:%s.",strerror(errno));
+		close(fd);
+		return (-1);
 	}
 
-	if (rate==16000) blocksize=4096;	/* oss emulation is not very good at 16khz */
-	else blocksize=blocksize*(rate/8000);
-
-	ioctl(fd, SNDCTL_DSP_GETBLKSIZE, &min_size);
-
-	/**
-	 * first try SNDCTL_DSP_SETFRAGMENT
-	 */
-	if (min_size>blocksize) {
-		int size_selector=0;
-		int frag;
-		while ((blocksize >> size_selector) != 1)size_selector++; /*compute selector blocksize = 1<< size_selector*/
-		frag = (2 << 16) | (size_selector);
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
+	err=ioctl(fd, SNDCTL_DSP_GETBLKSIZE, &min_size);
+	if (err<0){
+		close(fd);
+		return (-1);
 	}
 
-	if (min_size>blocksize)
-	{
-		ms_warning("dsp block size set to %i.",min_size);
-	}else{
-		/* no need to access the card with less latency than needed*/
-		min_size=blocksize;
+	/* compute a 20ms buffer by default */
+	blocksize = (rate / 50) * smp_size;
+	if (stereo) {
+		blocksize *= 2;
+		smp_size *= 2;
 	}
+	if (blocksize > min_size)
+		blocksize = min_size;
 
 	ms_message("/dev/dsp opened: rate=%i,bits=%i,stereo=%i blocksize=%i.",
-			rate,bits,stereo,min_size);
+			rate,bits,stereo,blocksize);
 
 	/* start recording !!! Alex */
 	{
@@ -135,7 +105,8 @@ static int configure_fd(int fd, int bits,int stereo, i
 		res=ioctl(fd, SNDCTL_DSP_SETTRIGGER, &fl);
 		if (res<0) ms_warning("OSS_TRIGGER: %s",strerror(errno));
 	}
-	*minsz=min_size;
+	*minsz=blocksize;
+	*mindly = ((uint64_t)1000000 * (uint64_t)blocksize) / (uint64_t)(2 * rate * smp_size);
 	return fd;
 }
 
@@ -156,23 +127,23 @@ typedef struct OssData{
 	bool_t stereo;
 } OssData;
 
-static void oss_open(OssData* d, int *minsz){
+static void oss_open(OssData* d, int *minsz, int *mindly){
 	int fd=open(d->pcmdev,O_RDWR|O_NONBLOCK);
 	if (fd>0) {
-		d->pcmfd_read=d->pcmfd_write=configure_fd(fd, d->bits, d->stereo, d->rate, minsz);
+		d->pcmfd_read=d->pcmfd_write=configure_fd(fd, d->bits, d->stereo, d->rate, minsz, mindly);
 		return ;
 	}
 	ms_warning ("Cannot open a single fd in rw mode for [%s] trying to open two",d->pcmdev);
 
 	d->pcmfd_read=open(d->pcmdev,O_RDONLY|O_NONBLOCK);
 	if (d->pcmfd_read > 0) {
-		d->pcmfd_read=configure_fd(d->pcmfd_read, d->bits, d->stereo, d->rate, minsz);
+		d->pcmfd_read=configure_fd(d->pcmfd_read, d->bits, d->stereo, d->rate, minsz, mindly);
 	} else {
 		ms_error("Cannot open fd in ro mode for [%s]",d->pcmdev);
 	}
 	d->pcmfd_write=open(d->pcmdev,O_WRONLY|O_NONBLOCK);
 	if (d->pcmfd_write > 0) {
-		d->pcmfd_write=configure_fd(d->pcmfd_write, d->bits, d->stereo, d->rate, minsz);
+		d->pcmfd_write=configure_fd(d->pcmfd_write, d->bits, d->stereo, d->rate, minsz, mindly);
 	} else {
 		ms_error("Cannot open fd in wr mode for [%s]",d->pcmdev);
 	}
@@ -327,61 +298,78 @@ static void * oss_thread(void *p){
 	MSSndCard *card=(MSSndCard*)p;
 	OssData *d=(OssData*)card->data;
 	int bsize=0;
-	uint8_t *rtmpbuff=NULL;
-	uint8_t *wtmpbuff=NULL;
+	int mindly=1000;
+	uint8_t *tmpbuff;
 	int err;
-	mblk_t *rm=NULL;
-	bool_t did_read=FALSE;
 
-	oss_open(d,&bsize);
-	if (d->pcmfd_read>=0){
-		rtmpbuff=(uint8_t*)alloca(bsize);
-	}
-	if (d->pcmfd_write>=0){
-		wtmpbuff=(uint8_t*)alloca(bsize);
-	}
+	oss_open(d,&bsize,&mindly);
+
+	tmpbuff=(uint8_t*)alloca(bsize);
+
 	while(d->read_started || d->write_started){
-		did_read=FALSE;
-		if (d->pcmfd_read>=0){
+		while (d->pcmfd_read>=0){
 			if (d->read_started){
-				if (rm==NULL) rm=allocb(bsize,0);
-				err=read(d->pcmfd_read,rm->b_wptr,bsize);
+				err=read(d->pcmfd_read,tmpbuff,bsize);
 				if (err<0){
-					ms_warning("Fail to read %i bytes from soundcard: %s",
-					bsize,strerror(errno));
-				}else{
-					did_read=TRUE;
+					if (errno != EWOULDBLOCK) {
+						ms_warning("Fail to read %i bytes from soundcard: %s",
+						    bsize,strerror(errno));
+					}
+					break;
+				}else if (err>0) {
+					mblk_t *rm=allocb(err,0);
+					memcpy(rm->b_wptr,tmpbuff,err);
 					rm->b_wptr+=err;
 					ms_mutex_lock(&d->mutex);
 					putq(&d->rq,rm);
 					ms_mutex_unlock(&d->mutex);
-					rm=NULL;
+				} else {
+					break;
 				}
 			}else {
 				/* case where we have no reader filtern the read is performed for synchronisation */
-				int sz = read(d->pcmfd_read,rtmpbuff,bsize);
-				if( sz==-1) ms_warning("sound device read error %s ",strerror(errno));
-				else did_read=TRUE;
+				int sz = read(d->pcmfd_read,tmpbuff,bsize);
+				if(sz<0){
+					ms_warning("sound device read error %s ",strerror(errno));
+					break;
+				}
 			}
 		}
-		if (d->pcmfd_write>=0){
-			if (d->write_started){
-				err=ms_bufferizer_read(d->bufferizer,wtmpbuff,bsize);
+
+		while (d->pcmfd_write>=0){
+			struct audio_buf_info ai;
+			int bufsize;
+			if (ioctl(d->pcmfd_write, SNDCTL_DSP_GETOSPACE, &ai) < 0)
+				break;
+			bufsize = ai.fragstotal * ai.fragsize - ai.bytes;
+			if (bufsize >= (2 * bsize)){
+				/* wait for buffer to empty */
+				break;
+			}else if (d->write_started){
+				ms_mutex_lock(&d->mutex);
+				err=ms_bufferizer_read(d->bufferizer,tmpbuff,bsize);
+				ms_mutex_unlock(&d->mutex);
 				if (err==bsize){
-					err=write(d->pcmfd_write,wtmpbuff,bsize);
+					err=write(d->pcmfd_write,tmpbuff,bsize);
 					if (err<0){
 						ms_warning("Fail to write %i bytes from soundcard: %s",
-						bsize,strerror(errno));
+							   bsize,strerror(errno));
+						break;
 					}
+				} else {
+					break;
 				}
 			}else {
 				int sz;
-				memset(wtmpbuff,0,bsize);
-				sz = write(d->pcmfd_write,wtmpbuff,bsize);
-				if( sz!=bsize) ms_warning("sound device write returned %i !",sz);
+				memset(tmpbuff,0,bsize);
+				sz = write(d->pcmfd_write,tmpbuff,bsize);
+				if(sz!=bsize) {
+					ms_warning("sound device write returned %i !",sz);
+					break;
+				}
 			}
 		}
-		if (!did_read) usleep(20000); /*avoid 100%cpu loop for nothing*/
+		usleep(mindly);
 	}
 	if (d->pcmfd_read==d->pcmfd_write && d->pcmfd_read>=0 ) {
 		close(d->pcmfd_read);
@@ -509,10 +497,10 @@ static int set_nchannels(MSFilter *f, void *arg){
 }
 
 static MSFilterMethod oss_methods[]={
-	{	MS_FILTER_SET_SAMPLE_RATE	, set_rate	},
+	{	MS_FILTER_SET_SAMPLE_RATE	, set_rate },
 	{	MS_FILTER_GET_SAMPLE_RATE	, get_rate },
 	{	MS_FILTER_SET_NCHANNELS		, set_nchannels	},
-	{	0				, NULL		}
+	{	0				, NULL }
 };
 
 MSFilterDesc oss_read_desc={
