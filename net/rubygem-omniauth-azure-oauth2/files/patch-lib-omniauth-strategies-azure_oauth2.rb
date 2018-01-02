--- lib/omniauth/strategies/azure_oauth2.rb.orig	2017-12-06 18:00:39 UTC
+++ lib/omniauth/strategies/azure_oauth2.rb
@@ -61,7 +61,7 @@ module OmniAuth
 
       def raw_info
         # it's all here in JWT http://msdn.microsoft.com/en-us/library/azure/dn195587.aspx
-        @raw_info ||= ::JWT.decode(access_token.token, nil, false).first
+        @raw_info ||= ::JWT.decode(access_token.token, nil, false, algorithm: 'RS256').first
       end
 
     end
