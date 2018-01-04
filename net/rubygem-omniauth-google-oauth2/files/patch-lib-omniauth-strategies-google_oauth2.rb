--- lib/omniauth/strategies/google_oauth2.rb.orig	2017-11-18 01:23:41 UTC
+++ lib/omniauth/strategies/google_oauth2.rb
@@ -70,7 +70,8 @@ module OmniAuth
                                                   verify_not_before: true,
                                                   verify_iat: true,
                                                   verify_jti: false,
-                                                  leeway: options[:jwt_leeway]
+                                                  leeway: options[:jwt_leeway],
+                                                  algorithm: 'RS256'
           ).first
         end
         hash[:raw_info] = raw_info unless skip_info?
