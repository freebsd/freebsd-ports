
$FreeBSD$

--- lfd_lzo.c.orig	Mon Jun  2 01:22:14 2003
+++ lfd_lzo.c	Mon Jun  2 01:22:29 2003
@@ -36,6 +36,7 @@
 #ifdef HAVE_LZO
 
 #include "lzo1x.h"
+#include "lzoutil.h"
 
 static lzo_byte *zbuf;
 static lzo_voidp wmem;
