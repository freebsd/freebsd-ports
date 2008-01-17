--- src/pkcs11/misc.c.orig	2008-01-17 12:22:03.000000000 +0100
+++ src/pkcs11/misc.c	2008-01-17 12:22:18.000000000 +0100
@@ -233,7 +233,7 @@
 		case CKA_PRIVATE:
 			size = sizeof(CK_BBOOL); break;
 		case CKA_CERTIFICATE_TYPE:
-			size = sizeof(CKA_CERTIFICATE_TYPE); break;
+			size = sizeof(CK_ULONG); break;
 		case CKA_MODULUS_BITS:
 			size = sizeof(CK_ULONG); break;
 		case CKA_OBJECT_ID:
