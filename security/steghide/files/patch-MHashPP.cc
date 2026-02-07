--- src/MHashPP.cc.orig	2013-06-11 10:25:36.000000000 +0200
+++ src/MHashPP.cc	2013-06-11 10:29:34.000000000 +0200
@@ -121,7 +121,7 @@
 
 std::string MHashPP::getAlgorithmName (hashid id)
 {
-	char *name = mhash_get_hash_name (id) ;
+	char *name = reinterpret_cast<char *>(mhash_get_hash_name (id)) ;
 	std::string retval ;
 	if (name == NULL) {
 		retval = std::string ("<algorithm not found>") ;
