Index: lib/gssapi/get_mic.c
===================================================================
RCS file: /home/kth-krb/heimdal/lib/gssapi/get_mic.c,v
retrieving revision 1.18
retrieving revision 1.19
diff -u -r1.18 -r1.19
--- lib/gssapi/get_mic.c	2001/06/18 02:50:15	1.18
+++ lib/gssapi/get_mic.c	2001/10/31 13:37:39	1.19
@@ -33,7 +33,7 @@
 
 #include "gssapi_locl.h"
 
-RCSID("$Id: get_mic.c,v 1.18 2001/06/18 02:50:15 assar Exp $");
+RCSID("$Id: get_mic.c,v 1.19 2001/10/31 13:37:39 nectar Exp $");
 
 static OM_uint32
 mic_des
@@ -235,10 +235,6 @@
 
   memcpy (p, encdata.data, encdata.length);
   krb5_data_free (&encdata);
-
-  p += 8 + cksum.checksum.length;
-
-  memcpy (p, message_buffer->value, message_buffer->length);
 
   krb5_auth_con_setlocalseqnumber (gssapi_krb5_context,
 			       context_handle->auth_context,
