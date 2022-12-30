--- psutil/arch/freebsd/sys_socks.c.orig	2022-09-02 10:06:38 UTC
+++ psutil/arch/freebsd/sys_socks.c
@@ -62,7 +62,7 @@ struct xfile *
 
 
 struct xfile *
-psutil_get_file_from_sock(void *sock) {
+psutil_get_file_from_sock(kvaddr_t sock) {
     struct xfile *xf;
     int n;
 
