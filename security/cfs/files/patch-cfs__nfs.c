
$FreeBSD$

--- cfs_nfs.c.orig
+++ cfs_nfs.c
@@ -877,12 +877,11 @@
 	static DIR *dp=NULL;
 	static struct dirent *dent;
 	entry **prev;
-	long loc;
 	char s1[NFS_MAXNAMLEN+1];
 	char *s;
 	cfskey *key;
-	static long curcookie=0;
-	long cookie;
+	static int32_t curcookie=0;
+	int32_t cookie;
 	int eof;
 	int ne;
 	int bytes;
@@ -944,7 +943,7 @@
 		else if (strcmp(s,"..")==0)	/* parent */
 			entrytab[ne].fileid=fhpid(h);
 		else entrytab[ne].fileid=dent->d_fileno;
-		bcopy(&cookie,entrytab[ne].cookie,sizeof(long));
+		bcopy(&cookie,entrytab[ne].cookie,sizeof(int32_t));
 		*prev = &entrytab[ne];
 		prev = &entrytab[ne].nextentry;
 		entrytab[ne].nextentry=NULL;
@@ -964,12 +963,12 @@
 
 DIR *curdir;
 int curdirid=0;
-long curcookie;
+int32_t curcookie;
 
 DIR *
 cfsopendir(dir,cookie)
      cfs_fileid *dir;
-     long cookie;
+     int32_t cookie;
 {
 	DIR *ret;
 	DIR *fhopendir();
@@ -1151,7 +1150,7 @@
 	typedef char str[NFS_MAXNAMLEN+1];
 	static str names[MAXENTRIES];
 	entry **prev;
-	long cookie;
+	int32_t cookie;
 	int eof;
 	int ne;
 	int bytes;
@@ -1163,7 +1162,7 @@
 	ne=0;
 	prev= &ret.readdirres_u.reply.entries;
 	*prev=NULL;
-	bcopy(ap->cookie,&cookie,sizeof(long));
+	bcopy(ap->cookie,&cookie,sizeof(int32_t));
 	eof=1;
 	
 	ret.status=NFS_OK;
@@ -1182,7 +1181,7 @@
 		else entrytab[ne].fileid=dent->d_fileno;
 		cookie=dent->d_reclen;	/* may not work everywhere */
 		*prev = &entrytab[ne];
-		bcopy(&cookie,entrytab[ne].cookie,sizeof(long));
+		bcopy(&cookie,entrytab[ne].cookie,sizeof(int32_t));
 		prev = &entrytab[ne].nextentry;
 		entrytab[ne].nextentry=NULL;
 		ne++;
