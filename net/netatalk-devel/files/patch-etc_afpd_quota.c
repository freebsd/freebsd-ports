--- etc/afpd/quota.c.orig	Sat Jun  5 22:03:39 2004
+++ etc/afpd/quota.c	Sat Jun  5 22:05:20 2004
@@ -57,6 +57,8 @@
 }
 #endif /* NEED_QUOTACTL_WRAPPER */
 
+static int overquota( struct dqblk *);
+
 #ifdef linux
 
 #ifdef HAVE_LINUX_XQM_H
@@ -74,7 +76,6 @@
 
 static int get_linux_xfs_quota(int, char*, uid_t, struct dqblk *);
 static int get_linux_fs_quota(int, char*, uid_t, struct dqblk *);
-static int overquota( struct dqblk *);
 
 /* format supported by current kernel */
 static int kernel_iface = IFACE_UNSET;
@@ -524,12 +525,12 @@
     if( 
         /* if overquota, free space is 0 otherwise hard-current */
         ( overquota( dq ) ? 0 : ( dq->dqb_bhardlimit ? dq->dqb_bhardlimit - 
-                                  dq->dqb_curblocks : ~((qsize_t) 0) ) )
+				   dq->dqb_curblocks : ~((u_int64_t) 0) ) )
 
       >
         
         ( overquota( &dqg ) ? 0 : ( dqg.dqb_bhardlimit ? dqg.dqb_bhardlimit - 
-                                    dqg.dqb_curblocks : ~((qsize_t) 0) ) )
+				    dqg.dqb_curblocks : ~((u_int64_t) 0) ) )
 
       ) /* if */
     {
