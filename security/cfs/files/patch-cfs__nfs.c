
$FreeBSD$

--- cfs_nfs.c.orig	Sun Dec 24 22:24:31 1995
+++ cfs_nfs.c	Sat Nov 17 19:43:00 2007
@@ -33,6 +33,7 @@
 #else
 #include <dirent.h>
 #endif
+#include <string.h>
 #include "nfsproto.h"
 #include "admproto.h"
 #include "cfs.h"
@@ -58,7 +59,7 @@
 }
 
 void *
-nfsproc_null_2(ap,rp)
+nfsproc_null_2_svc(ap,rp)
      void *ap;
      SR rp;
 {
@@ -72,7 +73,7 @@
 readdirres *rootreaddir();
 
 attrstat *
-nfsproc_getattr_2(ap,rp)
+nfsproc_getattr_2_svc(ap,rp)
      nfs_fh *ap;
      SR rp;
 {
@@ -118,7 +119,7 @@
 }
 
 attrstat *
-nfsproc_setattr_2(ap,rp)
+nfsproc_setattr_2_svc(ap,rp)
      sattrargs *ap;
      SR rp;
 {
@@ -168,7 +169,7 @@
 }
 
 void *
-nfsproc_root_2(ap,rp)
+nfsproc_root_2_svc(ap,rp)
      void *ap;
      SR rp;
 {
@@ -179,7 +180,7 @@
 
 /* fix this to deal w/ fs root (instance root should be ok) */
 diropres *
-nfsproc_lookup_2(ap,rp)
+nfsproc_lookup_2_svc(ap,rp)
      diropargs *ap;
      SR rp;
 {
@@ -258,7 +259,7 @@
 }
 
 readlinkres *
-nfsproc_readlink_2(ap,rp)
+nfsproc_readlink_2_svc(ap,rp)
      nfs_fh *ap;
      SR rp;
 {
@@ -309,7 +310,7 @@
 
 
 readres *
-nfsproc_read_2(ap,rp)
+nfsproc_read_2_svc(ap,rp)
      readargs *ap;
      SR rp;
 {
@@ -370,7 +371,7 @@
 
 
 void *
-nfsproc_writecache_2(ap,rp)
+nfsproc_writecache_2_svc(ap,rp)
      void *ap;
      SR rp;
 {
@@ -381,7 +382,7 @@
 
 
 attrstat *
-nfsproc_write_2(ap,rp)
+nfsproc_write_2_svc(ap,rp)
      writeargs *ap;
      SR rp;
 {
@@ -442,7 +443,7 @@
 
 
 diropres *
-nfsproc_create_2(ap,rp)
+nfsproc_create_2_svc(ap,rp)
      createargs *ap;
      SR rp;
 {
@@ -545,7 +546,7 @@
 
 
 nfsstat *
-nfsproc_remove_2(ap,rp)
+nfsproc_remove_2_svc(ap,rp)
      diropargs *ap;
      SR rp;
 {
@@ -587,7 +588,7 @@
 
 
 nfsstat *
-nfsproc_rename_2(ap,rp)
+nfsproc_rename_2_svc(ap,rp)
      renameargs *ap;
      SR rp;
 {
@@ -643,7 +644,7 @@
 
 
 nfsstat *
-nfsproc_link_2(ap,rp)
+nfsproc_link_2_svc(ap,rp)
      linkargs *ap;
      SR rp;
 {
@@ -694,7 +695,7 @@
 
 
 nfsstat *
-nfsproc_symlink_2(ap,rp)
+nfsproc_symlink_2_svc(ap,rp)
      symlinkargs *ap;
      SR rp;
 {
@@ -743,7 +744,7 @@
 }
 
 diropres *
-nfsproc_mkdir_2(ap,rp)
+nfsproc_mkdir_2_svc(ap,rp)
      createargs *ap;
      SR rp;
 {
@@ -817,7 +818,7 @@
 
 
 nfsstat *
-nfsproc_rmdir_2(ap,rp)
+nfsproc_rmdir_2_svc(ap,rp)
      diropargs *ap;
      SR rp;
 {
@@ -864,7 +865,7 @@
 /* #define cfsclosedir(x) fhclosedir(x) */
 
 readdirres *
-nfsproc_readdir_2(ap,rp)
+nfsproc_readdir_2_svc(ap,rp)
      readdirargs *ap;
      SR rp;
 {
@@ -877,12 +878,11 @@
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
@@ -944,7 +944,7 @@
 		else if (strcmp(s,"..")==0)	/* parent */
 			entrytab[ne].fileid=fhpid(h);
 		else entrytab[ne].fileid=dent->d_fileno;
-		bcopy(&cookie,entrytab[ne].cookie,sizeof(long));
+		bcopy(&cookie,entrytab[ne].cookie,sizeof(int32_t));
 		*prev = &entrytab[ne];
 		prev = &entrytab[ne].nextentry;
 		entrytab[ne].nextentry=NULL;
@@ -964,12 +964,12 @@
 
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
@@ -991,7 +991,7 @@
 }
 
 statfsres *
-nfsproc_statfs_2(ap,rp)
+nfsproc_statfs_2_svc(ap,rp)
      nfs_fh *ap;
      SR rp;
 {
@@ -1151,7 +1151,7 @@
 	typedef char str[NFS_MAXNAMLEN+1];
 	static str names[MAXENTRIES];
 	entry **prev;
-	long cookie;
+	int32_t cookie;
 	int eof;
 	int ne;
 	int bytes;
@@ -1163,7 +1163,7 @@
 	ne=0;
 	prev= &ret.readdirres_u.reply.entries;
 	*prev=NULL;
-	bcopy(ap->cookie,&cookie,sizeof(long));
+	bcopy(ap->cookie,&cookie,sizeof(int32_t));
 	eof=1;
 	
 	ret.status=NFS_OK;
@@ -1182,7 +1182,7 @@
 		else entrytab[ne].fileid=dent->d_fileno;
 		cookie=dent->d_reclen;	/* may not work everywhere */
 		*prev = &entrytab[ne];
-		bcopy(&cookie,entrytab[ne].cookie,sizeof(long));
+		bcopy(&cookie,entrytab[ne].cookie,sizeof(int32_t));
 		prev = &entrytab[ne].nextentry;
 		entrytab[ne].nextentry=NULL;
 		ne++;
