--- ext/camellia-rb.c.orig	2009-01-26 13:53:51.000000000 +0900
+++ ext/camellia-rb.c
@@ -111,7 +111,7 @@
 /*
 # encryption method
 */
-static VALUE encrypt(VALUE self, VALUE args)
+static VALUE camellia_encrypt(VALUE self, VALUE args)
 {
 	camelliaObject *camellia;
 	unsigned char *data;
@@ -147,7 +147,7 @@
 /*
 # decryption method
 */
-static VALUE decrypt(VALUE self,VALUE args)
+static VALUE camellia_decrypt(VALUE self,VALUE args)
 {
 	camelliaObject *camellia;
 	unsigned char *data;
@@ -537,8 +537,8 @@
 	//rb_define_singleton_method(cCamellia, "new", s_new, 0);
 	rb_define_private_method(cCamellia, "initialize", set_key, 1);
 	//rb_define_method(cCamellia, "set_key", set_key, 1);
-	rb_define_method(cCamellia, "encrypt", encrypt, 1);
-	rb_define_method(cCamellia, "decrypt", decrypt, 1);
+	rb_define_method(cCamellia, "encrypt", camellia_encrypt, 1);
+	rb_define_method(cCamellia, "decrypt", camellia_decrypt, 1);
 	rb_define_method(cCamellia, "cfb_salt", cfb_salt, 1);
 	rb_define_method(cCamellia, "cfb_encrypt", cfb_encrypt, 1);
 	rb_define_method(cCamellia, "cfb_decrypt", cfb_decrypt, 1);
