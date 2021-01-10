Reference:	https://github.com/grpc/grpc/commit/2b200d2313e739fa1841edf3ea86ab8532862505

--- src/ruby/ext/grpc/rb_call_credentials.c.orig	2020-04-14 03:10:13 UTC
+++ src/ruby/ext/grpc/rb_call_credentials.c
@@ -229,7 +229,7 @@ static VALUE grpc_rb_call_credentials_init(VALUE self,
   plugin.state = (void*)proc;
   plugin.type = "";
 
-  creds = grpc_metadata_credentials_create_from_plugin(plugin, NULL);
+  creds = grpc_metadata_credentials_create_from_plugin(plugin, GRPC_PRIVACY_AND_INTEGRITY, NULL);
   if (creds == NULL) {
     rb_raise(rb_eRuntimeError, "could not create a credentials, not sure why");
     return Qnil;
