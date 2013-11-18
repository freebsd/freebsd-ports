--- aoenet.c.orig	2013-11-18 21:43:13.000000000 +0700
+++ aoenet.c	2013-11-18 21:43:21.000000000 +0700
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
 
@@ -190,10 +193,18 @@
 /* 
  * a dummy "free" function for mbuf ext buffer 
  */
+#if __FreeBSD_version >= 1000050
+static int
+nilfn(struct mbuf *m, void *a, void *b)
+{
+	return EXT_FREE_OK;
+}
+#else
 static void
 nilfn(void *a, void *b)
 {
 }
+#endif
 
 /* Create a mbuf chain and point to our data section(s). */
 static struct mbuf *
@@ -223,6 +234,9 @@
 
 		m1->m_ext.ref_cnt = NULL;
 		MEXTADD(m1, f->f_data, len, nilfn, 
+#if (__FreeBSD_version >= 800000)
+			f->f_data,
+#endif
 			NULL, 0, EXT_NET_DRV);
 		m1->m_len = len;
 		m1->m_next = NULL;
