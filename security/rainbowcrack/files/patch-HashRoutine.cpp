--- HashRoutine.cpp.orig	2014-07-31 12:12:45.000000000 -0400
+++ HashRoutine.cpp	2014-07-31 12:20:45.000000000 -0400
@@ -18,8 +18,11 @@
 	// Notice: MIN_HASH_LEN <= nHashLen <= MAX_HASH_LEN
 
 	AddHashRoutine("lm",   HashLM,   8);
+	AddHashRoutine("ntlm", HashNTLM, 16);
+	AddHashRoutine("md4",  HashMD4,  16);
 	AddHashRoutine("md5",  HashMD5,  16);
 	AddHashRoutine("sha1", HashSHA1, 20);
+	AddHashRoutine("ripemd160", HashRIPEMD160, 20);
 }
 
 CHashRoutine::~CHashRoutine()
