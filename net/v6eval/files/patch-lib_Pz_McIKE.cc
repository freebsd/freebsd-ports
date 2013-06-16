--- lib/Pz/McIKE.cc.orig	2013-06-16 10:34:07.000000000 +0900
+++ lib/Pz/McIKE.cc	2013-06-16 10:34:49.000000000 +0900
@@ -380,7 +380,7 @@
 
 		if(padlen < sizeof(struct isakmp_gen)) {
 			fprintf(stderr,
-				"err: ISAKMP Pld_ISAKMP decode(%d) "
+				"err: ISAKMP Pld_ISAKMP decode(%zu) "
 				"over remain size(%d)\n",
 				sizeof(struct isakmp_gen), padlen);
 
@@ -390,7 +390,7 @@
 
 		if(plen < sizeof(struct isakmp_gen)) {
 			fprintf(stderr,
-				"err: ISAKMP Pld_ISAKMP decode(%d) "
+				"err: ISAKMP Pld_ISAKMP decode(%zu) "
 				"over ISAKMP PayloadLength(%d)\n",
 				sizeof(struct isakmp_gen), plen);
 
