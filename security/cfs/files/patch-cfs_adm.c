
$FreeBSD$

--- cfs_adm.c.orig	Mon Dec 25 01:41:30 1995
+++ cfs_adm.c	Sat Nov 17 19:44:35 2007
@@ -36,14 +36,14 @@
 }
 
 void *
-admproc_null_2()
+admproc_null_2_svc(void *v, SR rp)
 {
 }
 
 cfsstat *
-admproc_attach_2(ap,rp)
+admproc_attach_2_svc(ap,rp)
      cfs_attachargs *ap;
-     SR *rp;
+     SR rp;
 {
 	static cfsstat ret;
 	int i;
@@ -154,9 +154,9 @@
 }
 
 cfsstat *
-admproc_detach_2(ap,rp)
+admproc_detach_2_svc(ap,rp)
      cfs_detachargs *ap;
-     SR *rp;
+     SR rp;
 {
 	static cfsstat ret;
 	int i;
