--- ./lib/replace/system/config.m4.orig	2010-10-07 18:41:16.000000000 +0200
+++ ./lib/replace/system/config.m4	2010-10-26 01:52:57.000000000 +0200
@@ -1,7 +1,7 @@
 # filesys
 AC_HEADER_DIRENT 
 AC_CHECK_HEADERS(fcntl.h sys/fcntl.h sys/resource.h sys/ioctl.h sys/mode.h sys/filio.h sys/fs/s5param.h sys/filsys.h)
-AC_CHECK_HEADERS(sys/acl.h acl/libacl.h)
+AC_CHECK_HEADERS(sys/acl.h acl/libacl.h sunacl.h)
 
 # select
 AC_CHECK_HEADERS(sys/select.h)
