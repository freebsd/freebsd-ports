--- ssl/libnalssl/bss_nal.c.orig	2004-05-27 20:54:48 UTC
+++ ssl/libnalssl/bss_nal.c
@@ -41,26 +41,30 @@ static long NAL_bio_ctrl(BIO *, int, long, void *);
 static int NAL_bio_new(BIO *);
 static int NAL_bio_free(BIO *);
 
-static BIO_METHOD NAL_bio_meth = {
-	BIO_TYPE_BIO,
-	"NAL_CONNECTION",
-	NAL_bio_write,
-	NAL_bio_read,
-	NAL_bio_puts,
-	NULL, /* bgets */
-	NAL_bio_ctrl,
-	NAL_bio_new,
-	NAL_bio_free,
-	NULL /* callback_ctrl */
-};
+static BIO_METHOD *NAL_bio_meth = NULL;
 
+static BIO_METHOD *create_NAL_bio_meth(void)
+{
+	BIO_METHOD *bm = BIO_meth_new(BIO_get_new_index(), "NAL_CONNECTION");
+	BIO_meth_set_write(bm, NAL_bio_write);
+	BIO_meth_set_read(bm, NAL_bio_read);
+	BIO_meth_set_puts(bm, NAL_bio_puts);
+	BIO_meth_set_ctrl(bm, NAL_bio_ctrl);
+	BIO_meth_set_create(bm, NAL_bio_new);
+	BIO_meth_set_destroy(bm, NAL_bio_free);
+	return bm;
+}
+
 BIO *BIO_new_NAL_CONNECTION(NAL_CONNECTION *c)
 {
-	BIO *b = BIO_new(&NAL_bio_meth);
+	if (NAL_bio_meth == NULL)
+		NAL_bio_meth = create_NAL_bio_meth();
+
+	BIO *b = BIO_new(NAL_bio_meth);
 	if(!b) return NULL;
-	b->ptr = c;
-	b->init = 1;
-	b->shutdown = 1;
+	BIO_set_data(b, c);
+	BIO_set_init(b, 1);
+	BIO_set_shutdown(b, 1);
 	return b;
 }
 
@@ -69,10 +73,10 @@ static int NAL_bio_new(BIO *b)
 #ifdef NAL_BIO_DEBUG
 	SYS_fprintf(SYS_stdout, "NAL_BIO_DEBUG: NAL_bio_new()\n");
 #endif
-	b->init = 0;
-	b->num = -1;
-	b->ptr = NULL;
-	b->flags = 0;
+	BIO_set_init(b, 0);
+	// XXX: b->num = -1;
+	BIO_set_data(b, NULL);
+	BIO_set_flags(b, 0);
 	return 1;
 }
 
@@ -81,8 +85,8 @@ static int NAL_bio_free(BIO *b)
 #ifdef NAL_BIO_DEBUG
 	SYS_fprintf(SYS_stdout, "NAL_BIO_DEBUG: NAL_bio_free()\n");
 #endif
-	if(b->shutdown && b->init && b->ptr) {
-		NAL_CONNECTION *c = b->ptr;
+	if(BIO_get_shutdown(b) && BIO_get_init(b) && BIO_get_data(b)) {
+		NAL_CONNECTION *c = BIO_get_data(b);
 		NAL_CONNECTION_free(c);
 	}
 	return 1;
@@ -91,7 +95,7 @@ static int NAL_bio_free(BIO *b)
 static int NAL_bio_write(BIO *b, const char *ptr, int len)
 {
 	unsigned int res;
-	NAL_CONNECTION *c = (NAL_CONNECTION *)b->ptr;
+	NAL_CONNECTION *c = (NAL_CONNECTION *)BIO_get_data(b);
 	NAL_BUFFER *buf = NAL_CONNECTION_get_send(c);
 #ifdef NAL_BIO_DEBUG
 	SYS_fprintf(SYS_stdout, "NAL_BIO_DEBUG: NAL_bio_write(%d)\n", len);
@@ -109,7 +113,7 @@ static int NAL_bio_write(BIO *b, const char *ptr, int 
 static int NAL_bio_read(BIO *b, char *ptr, int len)
 {
 	unsigned int res;
-	NAL_CONNECTION *c = (NAL_CONNECTION *)b->ptr;
+	NAL_CONNECTION *c = (NAL_CONNECTION *)BIO_get_data(b);
 	NAL_BUFFER *buf = NAL_CONNECTION_get_read(c);
 #ifdef NAL_BIO_DEBUG
 	SYS_fprintf(SYS_stdout, "NAL_BIO_DEBUG: NAL_bio_read(%d)\n", len);
@@ -150,9 +154,9 @@ static long NAL_bio_ctrl(BIO *b, int cmd, long num, vo
 		return 1;
 	/* Commands */
 	case BIO_CTRL_GET_CLOSE:
-		return b->shutdown;
+		return BIO_get_shutdown(b);
 	case BIO_CTRL_SET_CLOSE:
-		b->shutdown = (int)num;
+		BIO_set_shutdown(b, (int)num);
 		return 1;
 	default:
 #ifdef NAL_BIO_DEBUG
