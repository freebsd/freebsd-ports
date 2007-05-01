--- wipe.c.orig	Tue Mar  6 10:24:24 2007
+++ wipe.c	Fri Mar  9 09:43:00 2007
@@ -17,6 +17,9 @@
 
 char wipe_c[]="$Id: wipe.c,v 1.96 2006/10/31 11:03:31 pav Rev 1.6-5 $";
 
+#ifndef SOLARIS
+#define SOLARIS (defined(sun) && (defined(__svr4__) || defined(__SVR4)))
+#endif
 
 #include <stdio.h>
 #include <limits.h>
@@ -909,9 +912,17 @@
 /*size    on success */
 long long int find_size_by_reading(int fd)
 {
+	struct stat st;
 	off_t limit,pos,prev,b_pos=0;
-	char buf[64];
-	int i;
+	char buf[512];
+	int i, j;
+
+	if ( OK != fstat(fd,&st) )
+	{
+		fprintf (stderr, "Skipping fd=%d, %s\n",fd,strerror(errno));
+		return ERROR;
+	}
+	j = !(S_ISBLK(st.st_mode) || S_ISCHR(st.st_mode)) ? 1 : sizeof(buf);
 
 	for ( limit=0x7f,i=sizeof(limit);--i; )
 		limit = (limit <<8)|0xff;
@@ -925,7 +936,7 @@
 			fprintf(stderr,"lseek error: %s\n",strerror(errno));
 			return 0;
 		}
-		if ( 1 != read(fd,buf,1) )
+		if ( j != read(fd,buf,j) )
 		{
 			prev=pos;
 			pos=(pos+b_pos)>>1;
@@ -1172,6 +1183,9 @@
 
 	if ( S_ISBLK(st.st_mode) || S_ISCHR(st.st_mode) )
 	{
+#if defined(__FreeBSD__) || defined(SOLARIS)
+		size = ~((long long int)1 << (sizeof(size)*8-1));
+#else
 		size = 0;
 
 #ifdef BLKGETSIZE
@@ -1191,6 +1205,7 @@
 		if ( 0 == size || ERROR == size )
 			for ( size=0x7f,i=sizeof(size);--i; )
 				size = (size <<8)|0xff;
+#endif
 	}
 
 	for ( i=0, op=0 ; i < o_pas_num; i++ )
@@ -1202,7 +1217,7 @@
 		lseek64(fd,0,SEEK_SET);
 		while ( s < size )
 		{
-			j = size - s < BUFFSIZE ? size - s : BUFFSIZE;
+			j = size - s < BUFFSIZE && !(S_ISBLK(st.st_mode) || S_ISCHR(st.st_mode)) ? size - s : BUFFSIZE;
 			fill_buff(buff, j, i,s);
 
 			if ( ERROR == (j=write(fd,(const void *)buff,j)) )
