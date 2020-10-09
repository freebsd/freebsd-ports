--- src/ruby/ext/grpc/rb_call_credentials.c.orig	2020-08-23 16:28:28 UTC
+++ src/ruby/ext/grpc/rb_call_credentials.c
@@ -233,7 +233,7 @@ static VALUE grpc_rb_call_credentials_init(VALUE self,
   // TODO(yihuazhang): Expose min_security_level via the Ruby API so that
   // applications can decide what minimum security level their plugins require.
   creds = grpc_metadata_credentials_create_from_plugin(
-      plugin, GRPC_PRIVACY_AND_INTEGRITY, NULL);
+      plugin, NULL);
   if (creds == NULL) {
     rb_raise(rb_eRuntimeError, "could not create a credentials, not sure why");
     return Qnil;
