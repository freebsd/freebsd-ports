--- extconf.rb.orig	Thu Sep 14 11:26:19 2000
+++ extconf.rb	Thu Jun 21 21:50:09 2001
@@ -9,4 +9,5 @@
 
 have_header("linux/quota.h")       # for linux
 have_header("sys/fs/ufs_quota.h")  # for solaris
+have_header("ufs/ufs/quota.h")     # for *bsd
 create_makefile("quota")
