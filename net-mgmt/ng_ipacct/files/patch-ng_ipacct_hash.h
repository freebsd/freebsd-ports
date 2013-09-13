--- ng_ipacct/ng_ipacct_hash.h.orig	2004-11-27 23:35:19.000000000 +0300
+++ ng_ipacct/ng_ipacct_hash.h	2013-08-13 20:50:07.000000000 +0400
@@ -26,7 +26,10 @@
  *	 $Id: ng_ipacct_hash.h,v 1.6 2004/11/27 20:35:19 romanp Exp $
  */
 
-#define	NBUCKETS	(256) /* must be power of 2 */
+#define	NBUCKETS	(512) /* must be power of 2 */
+
+#include <sys/lock.h>
+#include <sys/rmlock.h>
 
 #define	NG_IPACCT_HASH3(faddr, fport, lport)\
         ((faddr) ^ ((faddr) >> 16) ^ ntohs((lport) ^ (fport)))
@@ -34,6 +37,7 @@
         ((faddr ^ (faddr >> 23) ^ (faddr >> 17)))
 
 struct ip_acct_hash {
+	struct rmlock bl;
 	SLIST_HEAD( ,ip_acct_chunk) head;
 };
 
@@ -42,12 +46,20 @@
 static __inline int
 ip_hash_init(struct ip_acct_hash **h)
 {
+	int i;
+	struct ip_acct_hash *ph;
+
 	MALLOC(*h, struct ip_acct_hash *, 
 	    NBUCKETS * sizeof(struct ip_acct_hash), 
 	    M_NETGRAPH, M_NOWAIT | M_ZERO);
 	if (*h == NULL)
 		return (ENOMEM);
 
+	ph = *h;
+	for (i = 0; i < NBUCKETS; i ++) {
+		rm_init(&ph[i].bl, "ng_ipacct hash lock");
+	}
+
 	return (0);
 }
 
@@ -59,15 +71,18 @@
 	struct  ip_acct_chunk	*pe, *lastpe;
 	struct  ip_acct_record *pr;
     int     i;
+	struct rm_priotracker track;
 #ifdef HASH_DEBUG
     int     nchunk = 0;
 #endif
 
     pe = lastpe = NULL;
+	rm_rlock(&h[slot].bl, &track);
 	SLIST_FOREACH(pe, &(h[slot].head), next) {
 		lastpe = pe;
 		for (i = 0; i < pe->nrecs; i++) {
 			if(bcmp(s, &pe->recs[i].s, sizeof(struct ip_acct_stream)) == 0) {
+				rm_runlock(&h[slot].bl, &track);
 				return (&pe->recs[i]);
 			}
 		}
@@ -75,12 +90,29 @@
         nchunk ++;
 #endif
 	}
+	rm_runlock(&h[slot].bl, &track);
 #ifdef HASH_DEBUG
     if (nchunk)
         nchunk --;
 #endif
 	/* stream is not in hash. Add it if we allowed to do so. */
 	if (ok_to_insert) {
+		
+		rm_wlock(&h[slot].bl);
+		if (lastpe != NULL && SLIST_NEXT(lastpe, next) != NULL) {
+			/* It has been changed, need to scan again */
+			pe = lastpe;
+			while (pe != NULL) {
+				lastpe = pe;
+				for (i = 0; i < pe->nrecs; i++) {
+					if(bcmp(s, &pe->recs[i].s, sizeof(struct ip_acct_stream)) == 0) {
+						rm_wunlock(&h[slot].bl);
+						return (&pe->recs[i]);
+					}
+				}
+				pe = SLIST_NEXT(pe, next);
+			}
+		}
 		/* 
          * This is first chunk in slot or no
          * more space left in current chunk ? 
@@ -92,8 +124,10 @@
 				sizeof(*pe));
 #endif
 			/* allocate new accounting chunk */
-			if ((pe = HASH_ALLOC()) == NULL)
+			if ((pe = HASH_ALLOC()) == NULL) {
+				rm_wunlock(&h[slot].bl);
 				return (NULL);
+			}
 			if (lastpe == NULL)
 				SLIST_INSERT_HEAD(&(h[slot].head), pe, next);
 			else
@@ -109,6 +143,7 @@
         pr->when = time_second;
 		bcopy(s, &pr->s, sizeof(pr->s));
 		(*nrecs) ++;
+		rm_wunlock(&h[slot].bl);
 		return (pr);
 	} else {
 		return (NULL);
@@ -120,6 +155,7 @@
 {
     int i;
     struct ip_acct_chunk *ipe, *nxt;
+	struct ip_acct_hash *ph = *h;
 
     /* sanity check */
     if (*h == NULL)
@@ -127,10 +163,13 @@
 
     /* walk down through *next and free all memory */
     for(i = 0; i < NBUCKETS; i++) {
+		rm_wlock(&ph[i].bl);
 	    for(ipe = SLIST_FIRST(&((*h)[i].head)); ipe; ipe = nxt) {
 		    nxt = SLIST_NEXT(ipe, next);
 		    HASH_FREE(ipe);
 	    }
+		rm_wunlock(&ph[i].bl);
+		rm_destroy(&ph[i].bl);
     }
     FREE(*h, M_NETGRAPH);
     *h = NULL;
