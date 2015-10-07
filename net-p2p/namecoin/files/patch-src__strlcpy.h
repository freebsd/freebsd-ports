--- net-p2p/namecoin/files/patch-src__strlcpy.h	(revision 0)
+++ net-p2p/namecoin/files/patch-src__strlcpy.h	(working copy)
@@ -0,0 +1,20 @@ 
+--- src/strlcpy.h.orig	2015-08-24 00:28:33 UTC
++++ src/strlcpy.h
+@@ -15,6 +15,10 @@
+  */
+ #ifndef BITCOIN_STRLCPY_H
+ #define BITCOIN_STRLCPY_H
++
++#if defined(__FreeBSD__) && (__FreeBSD_version >= 330000)
++#include <string.h>
++#else
+ /*
+  * Copy src to string dst of size siz.  At most siz-1 characters
+  * will be copied.  Always NUL terminates (unless siz == 0).
+@@ -83,4 +87,6 @@ inline size_t strlcat(char *dst, const c
+ 
+     return(dlen + (s - src)); /* count does not include NUL */
+ }
++#endif	/* FreeBSD */
++
+ #endif
