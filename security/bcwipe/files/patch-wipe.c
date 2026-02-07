--- wipe.c.orig	2011-01-27 07:30:06.000000000 -0800
+++ wipe.c	2011-09-09 12:13:50.626914657 -0700
@@ -1521,9 +1521,17 @@
 /*size    on success */
 long long int find_size_by_reading(int fd)
 {
+	struct stat st;
 	off_t limit, pos, lPos, prev, b_pos = 0;
-	char buf[64];
-	int i;
+	char buf[512];
+	int i,j;
+
+	if ( OK != fstat(fd,&st) )
+	{
+		fprintf (stderr, "Skipping fd=%d, %s\n",fd,strerror(errno));
+		return ERROR;
+	}
+	j = !(S_ISBLK(st.st_mode) || S_ISCHR(st.st_mode)) ? 1 : sizeof(buf);
 
 	for ( limit=0x7f, i=sizeof(limit); --i; )
 		limit = (limit << 8) | 0xff;
@@ -1547,7 +1555,7 @@
 		
 		lPos = lseek_f( fd, pos, SEEK_SET );
 		
-		if ( ( lPos != pos ) || ( 1 != read(fd, buf, 1) ) ) {
+		if ( ( lPos != pos ) || ( 1 != read(fd, buf, j) ) ) {
 			prev = pos;
 			pos = (pos+b_pos) >> 1;
 		} else	{
