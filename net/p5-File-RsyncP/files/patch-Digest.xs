--- Digest/Digest.xs.orig	Sat Jan 10 16:27:37 2004
+++ Digest/Digest.xs	Sat Jan 10 16:28:38 2004
@@ -169,8 +169,7 @@
 	}
 
 SV *
-blockDigestUpdate(context, dataV, blockSize=700, blockLastLen=0, \
-		    md4DigestLen=16, seed=0)
+blockDigestUpdate(context, dataV, blockSize=700, blockLastLen=0, md4DigestLen=16, seed=0)
     PREINIT:
 	STRLEN len;
     INPUT:
