# Adjusted to work with FreeBSD r240233.
$OpenBSD: patch-cache_h,v 1.1 2008/06/13 00:38:12 canacar Exp $
--- cache.h.orig	Tue Nov  6 23:34:18 2007
+++ cache.h	Wed Jun 11 19:50:07 2008
@@ -31,14 +31,24 @@
 struct sc_ent {
         RB_ENTRY(sc_ent)    tlink;
 	TAILQ_ENTRY(sc_ent) qlink;
+#ifdef HAVE_PFSYNC_STATE
+#ifdef HAVE_FINE_GRAINED_LOCKING
+	u_int64_t	    id;
+#else
+	u_int32_t	    id[2];
+#endif
+#else
 	struct pf_addr      addr[2];
+#endif
 	double		    peak;
 	double		    rate;
 	time_t		    t;
 	u_int32_t	    bytes;
+#ifndef HAVE_PFSYNC_STATE
         u_int16_t           port[2];
         u_int8_t            af;
         u_int8_t            proto;
+#endif
 };
 
 int cache_init(int);
