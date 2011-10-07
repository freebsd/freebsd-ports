Index: plugins/gssapi.c
diff -u -p plugins/gssapi.c.orig plugins/gssapi.c
--- plugins/gssapi.c.orig	2011-05-12 04:25:55.000000000 +0900
+++ plugins/gssapi.c	2011-10-08 00:31:28.401398246 +0900
@@ -370,7 +370,7 @@ sasl_gss_encode(void *context, const str
     }
     
     if (output_token->value && output) {
-	unsigned char * p = (unsigned char *) text->encode_buf;
+	unsigned char * p;
 	
 	ret = _plug_buf_alloc(text->utils,
 			      &(text->encode_buf),
@@ -383,6 +383,8 @@ sasl_gss_encode(void *context, const str
 	    GSS_UNLOCK_MUTEX(text->utils);
 	    return ret;
 	}
+
+	p = (unsigned char *) text->encode_buf;
 	
 	p[0] = (output_token->length>>24) & 0xFF;
 	p[1] = (output_token->length>>16) & 0xFF;
