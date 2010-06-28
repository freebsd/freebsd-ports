--- src/signer/dialog.c.orig	2010-02-16 07:03:25.000000000 -0200
+++ src/signer/dialog.c	2010-06-26 06:42:17.000000000 -0300
@@ -15,31 +15,31 @@
   char *buffer;
 };
 
-static AssuanError
+static gpg_error_t
 getpin_cb (void *opaque, const void *buffer, size_t length)
 {
   struct entry_parm_s *parm = (struct entry_parm_s *) opaque;
 
   /* we expect the pin to fit on one line */
   if (parm->lines || length >= parm->size)
-    return ASSUAN_Too_Much_Data;
+    return gpg_error(GPG_ERR_ASS_TOO_MUCH_DATA);
 
   /* fixme: we should make sure that the assuan buffer is allocated in
      secure memory or read the response byte by byte */
   memcpy(parm->buffer, buffer, length);
   parm->buffer[length] = 0;
   parm->lines++;
-  return (AssuanError) 0;
+  return gpg_error(GPG_ERR_NO_ERROR);
 }
 
 int ask_and_verify_pin_code(struct sc_pkcs15_card *p15card,
 			    struct sc_pkcs15_object *pin)
 {
-	int r;
+	gpg_error_t r;
 	size_t len;
 	const char *argv[3];
 	const char *pgmname = PIN_ENTRY;
-	ASSUAN_CONTEXT ctx;
+	assuan_context_t ctx = NULL;
 	char buf[500];
 	char errtext[100];
 	struct entry_parm_s parm;
@@ -48,16 +48,26 @@
 	argv[0] = pgmname;
 	argv[1] = NULL;
 	
-	r = assuan_pipe_connect(&ctx, pgmname, (char **) argv, NULL);
+	assuan_set_gpg_err_source (GPG_ERR_SOURCE_DEFAULT); 
+
+	r = assuan_new(&ctx); 
+	if (r) { 
+		printf("Can't initialize assuan context: %s\n)", 
+		gpg_strerror(r)); 
+		goto err; 
+	} 
+
+	r = assuan_pipe_connect(ctx, pgmname, (const char **) argv, \ 
+		NULL, NULL, NULL, 0);
 	if (r) {
 		printf("Can't connect to the PIN entry module: %s\n",
-		       assuan_strerror((AssuanError) r));
+		       gpg_strerror(r));
 		goto err;
 	}
 	sprintf(buf, "SETDESC Enter PIN [%s] for digital signing  ", pin->label);
 	r = assuan_transact(ctx, buf, NULL, NULL, NULL, NULL, NULL, NULL);
 	if (r) {
-		printf("SETDESC: %s\n", assuan_strerror((AssuanError) r));
+		printf("SETDESC: %s\n", gpg_strerror(r));
 		goto err;
 	}
 	errtext[0] = 0;
@@ -71,12 +81,12 @@
 		parm.size = sizeof(buf);
 		parm.buffer = buf;
 		r = assuan_transact(ctx, "GETPIN", getpin_cb, &parm, NULL, NULL, NULL, NULL);
-		if (r == ASSUAN_Canceled) {
-			assuan_disconnect(ctx);
+		if (gpg_err_code(r) == GPG_ERR_ASS_CANCELED) { 
+			assuan_release(ctx);
 			return -2;
 		}
 		if (r) {
-			printf("GETPIN: %s\n", assuan_strerror((AssuanError) r));
+			printf("GETPIN: %s\n", gpg_strerror(r));
 			goto err;
 		}
 		len = strlen(buf);
@@ -104,9 +114,9 @@
 			break;
 	}
 
-	assuan_disconnect(ctx);	
+	assuan_release(ctx);
 	return 0;
 err:	
-	assuan_disconnect(ctx);
+	assuan_release(ctx);
 	return -1;
 }
