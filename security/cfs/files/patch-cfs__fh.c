
$FreeBSD$

--- cfs_fh.c.orig
+++ cfs_fh.c
@@ -61,7 +61,7 @@
 }
 #endif
 
-#define hash(x) ((u_long)((x)&HMASK))
+#define hash(x) ((uint32_t)((x)&HMASK))
 int inst = 0;/* starting point */
 instance *instances[NINSTANCES];
 
@@ -135,7 +135,6 @@
 	int headlen;
 	int writemore=0;
 	struct stat sb;
-	u_long mask = ~0;	/*tells us whether to expand file */
 	char buf[8216];	/* big enough, may not even need it */
 
 	/* first, normalize to the proper boundries */
@@ -763,7 +762,7 @@
 	char vect[9];
 	union{
 		u_char ch[9];
-		u_long i[2];
+		uint32_t i[2];
 	} buf;
 	char linkname[NFS_MAXPATHLEN+1];
 	
@@ -792,8 +791,8 @@
 		/*
 		sprintf((char *)buf,"%08x",(u_long)sb.st_ino+(u_long)sb.st_ctime);
 		*/
-		buf.i[0]=(u_long)sb.st_ino;
-		buf.i[1]=(u_long)sb.st_ctime;
+		buf.i[0]=(uint32_t)sb.st_ino;
+		buf.i[1]=(uint32_t)sb.st_ctime;
 		q_block_cipher("fixedkey",&buf,1);
 		/* des is just used here as a hash fn to spread the bits */
 		/* since we only use 32 bits of the result, its a nonperfect */
@@ -908,7 +907,7 @@
 			f->name=NULL;
 		}
 	} else {
-		if ((f=(cfs_fileid *)malloc(sizeof(cfs_fileid)))==NULL) {
+		if ((f=(cfs_fileid *)calloc(1, sizeof(cfs_fileid)))==NULL) {
 			fprintf(stderr,"cfsd: out of memory\n");
 			cfserrno=NFSERR_STALE;	/* bad news */
 			return -2;
@@ -1146,7 +1145,7 @@
    break anything */
 struct dirent *
 rootrd(cookie)
-     long cookie;
+     int32_t cookie;
 {
 	static struct dirent d;
 
@@ -1198,7 +1197,7 @@
 #endif /* SHORTLINKS */
 					)) == NULL) {
 				if ((f=(cfs_fileid *)
-				     malloc(sizeof(cfs_fileid)))==NULL) {
+				     calloc(1, sizeof(cfs_fileid)))==NULL) {
 					fprintf(stderr,"cfsd: no memory\n");
 					cfserrno=NFSERR_STALE;	/* bad news */
 					return -2;
