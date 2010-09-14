--- aoenet.c.orig	2010-09-13 12:24:34.000000000 +0700
+++ aoenet.c	2010-09-13 12:26:12.000000000 +0700
@@ -77,8 +77,11 @@
 #define NECODES (sizeof(aoe_errlist) /  sizeof(char *) - 1)
 #if (__FreeBSD_version < 600000)
 #define IFPADDR(ifp) (((struct arpcom *) (ifp))->ac_enaddr)
-#else
+#elif (__FreeBSD_version < 700000)
 #define IFPADDR(ifp) IFP2ENADDR(ifp) 
+#else
+#include <net/if_dl.h>
+#define IFPADDR(ifp) IF_LLADDR(ifp)
 #endif
 #define IFLISTSZ 1024
 
@@ -223,6 +226,9 @@
 
 		m1->m_ext.ref_cnt = NULL;
 		MEXTADD(m1, f->f_data, len, nilfn, 
+#if (__FreeBSD_version >= 800000)
+			f->f_data,
+#endif
 			NULL, 0, EXT_NET_DRV);
 		m1->m_len = len;
 		m1->m_next = NULL;
