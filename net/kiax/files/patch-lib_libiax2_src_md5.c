--- lib/libiax2/src/md5.c.orig	Sat Nov 12 17:34:12 2005
+++ lib/libiax2/src/md5.c	Sat Nov 12 17:35:18 2005
@@ -1,7 +1,7 @@
 /* MD5 checksum routines used for authentication.  Not covered by GPL, but
    in the public domain as per the copyright below */
 
-#ifdef FREEBSD
+#ifdef __FreeBSD__
 # include <machine/endian.h>
 #elif defined(LINUX)  
 # include <endian.h>
