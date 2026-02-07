--- aoe.h.orig	2023-09-05 13:45:55 UTC
+++ aoe.h
@@ -167,6 +167,7 @@ struct ifnet;
 struct mbuf;
 struct mtx;
 
+#define frame aoeframe
 struct frame {
 	int f_tag;
 	int f_mlen;
