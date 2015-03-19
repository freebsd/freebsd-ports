--- crypto/asn1/a_type.c.orig	2015-02-10 14:54:46 UTC
+++ crypto/asn1/a_type.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: a_type.c,v 1.14 2014/07/11 08:44:47 jsing Exp $ */
+/* $OpenBSD: a_type.c,v 1.15 2015/02/10 08:33:10 jsing Exp $ */
 /* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
  * All rights reserved.
  *
@@ -119,7 +119,9 @@ ASN1_TYPE_cmp(ASN1_TYPE *a, ASN1_TYPE *b
 	case V_ASN1_OBJECT:
 		result = OBJ_cmp(a->value.object, b->value.object);
 		break;
-
+	case V_ASN1_BOOLEAN:
+		result = a->value.boolean - b->value.boolean;
+		break;
 	case V_ASN1_NULL:
 		result = 0;	/* They do not have content. */
 		break;
