--- cZone.cpp.orig	Wed May  7 20:21:34 2003
+++ cZone.cpp	Thu Aug 26 18:54:31 2004
@@ -88,7 +88,6 @@
 	}}}
 
 cZone:: cZone() {{{
-	mtrace ();
 	uint8_t zero[HASH_LEN];
 	bzero(zero, HASH_LEN);
 	init(NULL, 0, zero);
