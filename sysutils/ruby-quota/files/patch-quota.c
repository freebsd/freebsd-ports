--- quota.c.orig	Sun Dec  3 22:19:44 2000
+++ quota.c	Thu Jun 21 22:06:42 2001
@@ -16,6 +16,12 @@
 #include <sys/fs/ufs_quota.h>
 #endif
 
+#ifdef HAVE_UFS_UFS_QUOTA_H    /* for *BSD */
+#include <sys/types.h>
+#include <sys/fcntl.h>
+#include <ufs/ufs/quota.h>
+#endif
+
 static VALUE rb_mQuota;
 static VALUE rb_sDiskQuota;
 static VALUE rb_eQuotaError, rb_eQuotaCtlError;
@@ -31,6 +37,17 @@
     return quotactl(QCMD(cmd,GRPQUOTA),dev,-uid,addr);
   };
 };
+#elif defined(HAVE_UFS_UFS_QUOTA_H)
+static int
+rb_quotactl(int cmd, char *dev, uid_t uid, caddr_t addr)
+{
+  if( uid >= 0 ){
+    return quotactl(dev,QCMD(cmd,USRQUOTA),uid,addr);
+  }
+  else{
+    return quotactl(dev,QCMD(cmd,GRPQUOTA),-uid,addr);
+  };
+};
 #elif defined(HAVE_SYS_FS_UFS_QUOTA_H)
 static int
 rb_quotactl(int cmd, char *dev, uid_t uid, caddr_t addr)
@@ -83,7 +100,7 @@
   if( rb_quotactl(Q_GETQUOTA,c_dev,c_uid,(caddr_t)(&c_dqb)) == -1 ){
     rb_sys_fail("quotactl");
   };
-#if defined(HAVE_LINUX_QUOTA_H)
+#if defined(HAVE_LINUX_QUOTA_H) || defined(HAVE_UFS_UFS_QUOTA_H)
   dqb = rb_struct_new(rb_sDiskQuota,
 		      UINT2NUM(c_dqb.dqb_bhardlimit),
 		      UINT2NUM(c_dqb.dqb_bsoftlimit),
@@ -149,7 +166,7 @@
 
 #define GetMember(mem) \
         ((v = rb_struct_getmember(dqb,rb_intern(mem))) == Qnil) ? 0 : (NUM2UINT(v))
-#if defined(HAVE_LINUX_QUOTA_H)
+#if defined(HAVE_LINUX_QUOTA_H) || defined(HAVE_UFS_UFS_QUOTA_H)
   c_dqb.dqb_bhardlimit = GetMember("bhardlimit");
   c_dqb.dqb_bsoftlimit = GetMember("bsoftlimit");
   c_dqb.dqb_curblocks  = GetMember("curblocks");
@@ -180,6 +197,7 @@
   return Qnil;
 };
 
+#ifdef Q_SETQLIM
 VALUE
 rb_quota_setqlim(VALUE self, VALUE dev, VALUE uid, VALUE dqb)
 {
@@ -220,6 +238,7 @@
 #endif
   return Qnil;
 };
+#endif
 
 VALUE
 rb_quota_sync(VALUE self, VALUE dev)
@@ -252,7 +271,7 @@
 				   "bhardlimit",
 				   "bsoftlimit",
 				   "curblocks",
-#if defined(HAVE_LINUX_QUOTA_H)
+#if defined(HAVE_LINUX_QUOTA_H) || defined(HAVE_UFS_UFS_QUOTA_H)
 				   "ihardlimit",
 				   "isoftlimit",
 				   "curinodes",
@@ -272,6 +291,8 @@
   rb_define_module_function(rb_mQuota,"quotaoff",rb_quota_quotaoff,1);
   rb_define_module_function(rb_mQuota,"getquota",rb_quota_getquota,2);
   rb_define_module_function(rb_mQuota,"setquota",rb_quota_setquota,3);
+#ifdef Q_SETQLIM
   rb_define_module_function(rb_mQuota,"setqlim",rb_quota_setqlim,3);
+#endif
   rb_define_module_function(rb_mQuota,"sync",rb_quota_sync,1);
 };
