--- adns/internal.h.orig	Thu Mar  3 16:00:32 2005
+++ adns/internal.h	Thu Mar  3 16:02:10 2005
@@ -567,7 +567,7 @@
 } parsedomain_flags;
 
 adns_status adns__parse_domain(adns_state ads, int serv, adns_query qu,
-			       vbuf *vb, parsedomain_flags flags,
+			       vbuf *vb, adns_queryflags flags,
 			       const byte *dgram, int dglen, int *cbyte_io, int max);
 /* vb must already have been initialised; it will be reset if necessary.
  * If there is truncation, vb->used will be set to 0; otherwise
