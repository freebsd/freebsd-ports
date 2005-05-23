--- lib/payload.c.orig	Mon Feb 25 00:40:01 2002
+++ lib/payload.c	Thu May 19 16:26:46 2005
@@ -16,6 +16,7 @@
 #include <missl.h>
 #include <scepldap.h>
 #include <fcntl.h>
+#include <openscep_err.h>                                                                                                                   
 
 /*
  * payload_build_original	convert the original request into a bit string
@@ -68,7 +69,7 @@
 	p->rt = -1;
 	p->od.req = NULL;
 	return p;
-	M_ASN1_New_Error(ASN1_F_X509_REQ_INFO_NEW);	/* wrong error code */
+	M_ASN1_New_Error(OPENSCEP_F_PAYLOAD_NEW);
 }
 
 void	payload_free(payload_t *a) {
@@ -171,7 +172,7 @@
 		ret->od.spki = d2i_NETSCAPE_SPKI(&r2, &u, l);
 		break;
 	}
-	M_ASN1_D2I_Finish(a, payload_free, ASN1_F_D2I_X509_REQ_INFO);
+	M_ASN1_D2I_Finish(a, payload_free, OPENSCEP_F_D2I_PAYLOAD);
 }
 
 /*
