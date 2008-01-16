diff -urN -x .svn ../../branches/vendor/mhash/lib/mhash.c ./lib/mhash.c
--- ../../branches/vendor/mhash/lib/mhash.c	2008-01-16 14:26:51.000000000 +0200
+++ ./lib/mhash.c	2008-01-16 15:22:29.000000000 +0200
@@ -299,7 +299,7 @@
 	{
 		ret->hmac_key = (mutils_word8 *) mutils_malloc(ret->hmac_key_size);
 
-		if (ret == NULL)
+		if (ret->hmac_key == NULL)
 		{
 			mutils_free(ret->state);
 			mutils_free(ret);
