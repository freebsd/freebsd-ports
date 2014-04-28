--- pkcs11/pkcs11-request.c.orig	2014-03-22 11:48:55.000000000 +0100
+++ pkcs11/pkcs11-request.c	2014-03-22 11:49:53.000000000 +0100
@@ -1051,7 +1051,7 @@
 #line 61 "/data/src/seahorse/pkcs11/pkcs11-request.vala"
 	_tmp18_ = self->priv->_private_key;
 #line 61 "/data/src/seahorse/pkcs11/pkcs11-request.vala"
-	g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (_tmp18_, gck_object_get_type ()));
+	g_return_val_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (_tmp18_, gck_object_get_type ()), NULL);
 #line 35 "/data/src/seahorse/pkcs11/pkcs11-request.vala"
 	_g_object_unref0 (widget);
 #line 35 "/data/src/seahorse/pkcs11/pkcs11-request.vala"
