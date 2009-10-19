--- lib/softoken/legacydb/lgfind.c.orig	2009-10-19 16:07:48.000000000 +0200
+++ lib/softoken/legacydb/lgfind.c	2009-10-19 16:08:04.000000000 +0200
@@ -778,7 +778,7 @@
 	    classFlags &= LG_TRUST;
 	    copy = &cert_md5_hash; break;
 	case CKA_CERTIFICATE_TYPE:
-	    crv = lg_GetULongAttribute(CKA_CLASS,&pTemplate[i],1,&certType);
+	    crv = lg_GetULongAttribute(CKA_CERTIFICATE_TYPE,&pTemplate[i],1,&certType);
 	    if (crv != CKR_OK) {
 		classFlags = 0;
 	    }
