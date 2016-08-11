--- app/helpers/single_auth_helper.rb.orig	2016-06-29 17:45:04 UTC
+++ app/helpers/single_auth_helper.rb
@@ -12,8 +12,15 @@ module SingleAuthHelper
       port = auth_source.port
     end
 
+    if auth_source.tls?
+      encryption = :simple_tls
+    else
+      encryption = nil
+    end
+
     Net::LDAP.new host: auth_source.host,
                   port: port,
+                  encryption: encryption,
                   auth: { method: :simple,
                           username: auth_source.account,
                           password: auth_source.account_password }
