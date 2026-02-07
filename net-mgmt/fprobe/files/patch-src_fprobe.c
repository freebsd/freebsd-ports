--- src/fprobe.c.orig	2017-12-23 18:54:12 UTC
+++ src/fprobe.c
@@ -393,7 +393,7 @@ void gettime(struct Time *now)
 	now->usec = t.tv_usec;
 }
 
-inline time_t cmpmtime(struct Time *t1, struct Time *t2)
+static inline time_t cmpmtime(struct Time *t1, struct Time *t2)
 {
 	return (t1->sec - t2->sec) * 1000 + (t1->usec - t2->usec) / 1000;
 }
@@ -411,7 +411,7 @@ hash_t hash_flow(struct Flow *flow)
 	else return hash(flow, sizeof(struct Flow_TL));
 }
 
-inline void copy_flow(struct Flow *src, struct Flow *dst)
+static inline void copy_flow(struct Flow *src, struct Flow *dst)
 {
 	dst->sip = src->sip;
 	dst->dip = src->dip;
