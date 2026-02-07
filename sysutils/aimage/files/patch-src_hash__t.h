--- src/hash_t.h.orig	2011-08-17 23:33:08 UTC
+++ src/hash_t.h
@@ -160,7 +160,7 @@ typedef hash__<sha512_> sha512_t;
 template<typename T> 
 class hash_generator__:T { 			/* generates the hash */
     const EVP_MD *md;
-    EVP_MD_CTX mdctx;	     /* the context for computing the value */
+    EVP_MD_CTX *mdctx;	     /* the context for computing the value */
     bool initialized;	       /* has the context been initialized? */
     bool finalized;
     /* Static function to determine if something is zero */
@@ -189,8 +189,8 @@ class hash_generator__:T { 			/* generates the hash */
     }
     void init(){
 	if(initialized==false){
-	    EVP_MD_CTX_init(&mdctx);
-	    EVP_DigestInit_ex(&mdctx, md, NULL);
+	    mdctx = EVP_MD_CTX_create();
+	    EVP_DigestInit_ex(mdctx, md, NULL);
 	    initialized = true;
 	    finalized = false;
 	    hashed_bytes = 0;
@@ -202,12 +202,13 @@ class hash_generator__:T { 			/* generates the hash */
 	    std::cerr << "hashgen_t::update called after finalized\n";
 	    exit(1);
 	}
-	EVP_DigestUpdate(&mdctx,buf,bufsize);
+	EVP_DigestUpdate(mdctx,buf,bufsize);
 	hashed_bytes += bufsize;
     }
     void release(){			/* free allocated memory */
 	if(initialized){
-	    EVP_MD_CTX_cleanup(&mdctx);
+	    EVP_MD_CTX_destroy(mdctx);
+	    mdctx = NULL;
 	    initialized = false;
 	    hashed_bytes = 0;
 	}
@@ -223,7 +224,7 @@ class hash_generator__:T { 			/* generates the hash */
 	}
 	hash__<T> val;
 	unsigned int len = sizeof(val.digest);
-	EVP_DigestFinal(&mdctx,val.digest,&len);
+	EVP_DigestFinal(mdctx,val.digest,&len);
 	finalized = true;
 	return val;
     }
