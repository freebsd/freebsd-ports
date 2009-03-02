--- qca-ossl.cpp.orig	2007-12-11 07:34:57.000000000 +0100
+++ qca-ossl.cpp	2009-02-26 06:41:17.000000000 +0100
@@ -6597,9 +6597,11 @@
 #ifdef SHA512_DIGEST_LENGTH
 	list += "sha512";
 #endif
+#if 0
 #ifdef OBJ_whirlpool
 	list += "whirlpool";
 #endif
+#endif
 	return list;
 }
 
@@ -6810,10 +6812,12 @@
 		else if ( type == "sha512" )
 			return new opensslHashContext( EVP_sha512(), this, type);
 #endif
+#if 0
 #ifdef OBJ_whirlpool
 		else if ( type == "whirlpool" )
 			return new opensslHashContext( EVP_whirlpool(), this, type);
 #endif
+#endif
 		else if ( type == "pbkdf1(sha1)" )
 			return new opensslPbkdf1Context( EVP_sha1(), this, type );
 		else if ( type == "pbkdf1(md2)" )
