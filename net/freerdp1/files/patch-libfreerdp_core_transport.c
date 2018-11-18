--- libfreerdp/core/transport.c.orig	2014-09-11 22:46:32 UTC
+++ libfreerdp/core/transport.c
@@ -54,6 +54,7 @@
 #include "fastpath.h"
 #include "transport.h"
 #include "rdp.h"
+#include "../crypto/opensslcompat.h"
 
 #define TAG FREERDP_TAG("core")
 
@@ -122,7 +123,7 @@ static int transport_bio_tsg_write(BIO* bio, const cha
 {
 	int status;
 	rdpTsg* tsg;
-	tsg = (rdpTsg*) bio->ptr;
+	tsg = (rdpTsg*) BIO_get_data(bio);
 	BIO_clear_flags(bio, BIO_FLAGS_WRITE);
 	status = tsg_write(tsg, (BYTE*) buf, num);
 
@@ -142,9 +143,9 @@ static int transport_bio_tsg_read(BIO* bio, char* buf,
 {
 	int status;
 	rdpTsg* tsg;
-	tsg = (rdpTsg*) bio->ptr;
+	tsg = (rdpTsg*) BIO_get_data(bio);
 	BIO_clear_flags(bio, BIO_FLAGS_READ);
-	status = tsg_read(bio->ptr, (BYTE*) buf, size);
+	status = tsg_read(tsg, (BYTE*) buf, size);
 
 	if (status < 0)
 	{
@@ -180,10 +181,9 @@ static long transport_bio_tsg_ctrl(BIO* bio, int cmd, 
 
 static int transport_bio_tsg_new(BIO* bio)
 {
-	bio->init = 1;
-	bio->num = 0;
-	bio->ptr = NULL;
-	bio->flags = BIO_FLAGS_SHOULD_RETRY;
+	BIO_set_init(bio, 1);
+	BIO_set_data(bio, 0);
+	BIO_set_flags(bio, BIO_FLAGS_SHOULD_RETRY);
 	return 1;
 }
 
@@ -194,23 +194,22 @@ static int transport_bio_tsg_free(BIO* bio)
 
 #define BIO_TYPE_TSG	65
 
-static BIO_METHOD transport_bio_tsg_methods =
-{
-	BIO_TYPE_TSG,
-	"TSGateway",
-	transport_bio_tsg_write,
-	transport_bio_tsg_read,
-	transport_bio_tsg_puts,
-	transport_bio_tsg_gets,
-	transport_bio_tsg_ctrl,
-	transport_bio_tsg_new,
-	transport_bio_tsg_free,
-	NULL,
-};
-
 BIO_METHOD* BIO_s_tsg(void)
 {
-	return &transport_bio_tsg_methods;
+	static BIO_METHOD* bio_methods = NULL;
+	if (bio_methods == NULL)
+	{
+		if (!(bio_methods = BIO_meth_new(BIO_TYPE_TSG, "TSGateway")))
+			return NULL;
+		BIO_meth_set_write(bio_methods, transport_bio_tsg_write);
+		BIO_meth_set_read(bio_methods, transport_bio_tsg_read);
+		BIO_meth_set_puts(bio_methods, transport_bio_tsg_puts);
+		BIO_meth_set_gets(bio_methods, transport_bio_tsg_gets);
+		BIO_meth_set_ctrl(bio_methods, transport_bio_tsg_ctrl);
+		BIO_meth_set_create(bio_methods, transport_bio_tsg_new);
+		BIO_meth_set_destroy(bio_methods, transport_bio_tsg_free);
+	}
+	return bio_methods;
 }
 
 BOOL transport_connect_tls(rdpTransport* transport)
@@ -426,7 +425,7 @@ BOOL transport_tsg_connect(rdpTransport* transport, co
 		return FALSE;
 
 	transport->frontBio = BIO_new(BIO_s_tsg());
-	transport->frontBio->ptr = tsg;
+	BIO_set_data(transport->frontBio, tsg);
 	return TRUE;
 }
 
