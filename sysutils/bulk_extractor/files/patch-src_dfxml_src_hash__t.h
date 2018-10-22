--- src/dfxml/src/hash_t.h.orig	2014-09-16 18:34:02 UTC
+++ src/dfxml/src/hash_t.h
@@ -189,7 +189,8 @@ inline std::string digest_name<sha512_t>
 
 template<const EVP_MD *md(),size_t SIZE> 
 class hash_generator__ { 			/* generates the hash */
-    EVP_MD_CTX mdctx;	     /* the context for computing the value */
+ private:
+    EVP_MD_CTX* mdctx;	     /* the context for computing the value */
     bool initialized;	       /* has the context been initialized? */
     bool finalized;
     /* Static function to determine if something is zero */
@@ -199,24 +200,36 @@ class hash_generator__ { 			/* generates
 	}
 	return true;
     }
+    /* Not allowed to copy; these are prototyped but not defined, so any attempt to use them will fail, but we won't get the -Weffc++ warnings  */
+    hash_generator__ & operator=(const hash_generator__ &);
+    hash_generator__(const hash_generator__ &);
 public:
     int64_t hashed_bytes;
     /* This function takes advantage of the fact that different hash functions produce residues with different sizes */
-    hash_generator__():mdctx(),initialized(false),finalized(false),hashed_bytes(0){ }
+    hash_generator__():mdctx(NULL),initialized(false),finalized(false),hashed_bytes(0){ }
     ~hash_generator__(){
 	release();
     }
     void release(){			/* free allocated memory */
 	if(initialized){
-	    EVP_MD_CTX_cleanup(&mdctx);
+#ifdef HAVE_EVP_MD_CTX_FREE
+	    EVP_MD_CTX_free(mdctx);
+#else
+	    EVP_MD_CTX_destroy(mdctx);
+#endif
 	    initialized = false;
 	    hashed_bytes = 0;
 	}
     }
     void init(){
 	if(initialized==false){
-	    EVP_MD_CTX_init(&mdctx);
-	    EVP_DigestInit_ex(&mdctx, md(), NULL);
+#ifdef HAVE_EVP_MD_CTX_NEW
+	    mdctx = EVP_MD_CTX_new();
+#else
+	    mdctx = EVP_MD_CTX_create();
+#endif
+            if (!mdctx) throw std::bad_alloc();
+	    EVP_DigestInit_ex(mdctx, md(), NULL);
 	    initialized = true;
 	    finalized = false;
 	    hashed_bytes = 0;
@@ -228,21 +241,21 @@ public:
 	    std::cerr << "hashgen_t::update called after finalized\n";
 	    exit(1);
 	}
-	EVP_DigestUpdate(&mdctx,buf,bufsize);
+	EVP_DigestUpdate(mdctx,buf,bufsize);
 	hashed_bytes += bufsize;
     }
     hash__<md,SIZE> final() {
 	if(finalized){
 	  std::cerr << "currently friendly_geneator does not cache the final value\n";
 	  assert(0);
-	  /* code below will never be executed after assert(0) */
+          exit(1);                      // in case compiled with assertions disabled
 	}
 	if(!initialized){
 	  init();			/* do it now! */
 	}
 	hash__<md,SIZE> val;
 	unsigned int len = sizeof(val.digest);
-	EVP_DigestFinal(&mdctx,val.digest,&len);
+	EVP_DigestFinal(mdctx,val.digest,&len);
 	finalized = true;
 	return val;
     }
