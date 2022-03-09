--- config/initializers/google_api_client_patch.rb.orig	2022-03-09 09:41:27 UTC
+++ config/initializers/google_api_client_patch.rb
@@ -2,7 +2,7 @@
 
 require 'google/apis/core/http_command'
 
-raise 'This patch is only tested with google-api-client-ruby v0.50.0' unless Google::Apis::VERSION == "0.50.0"
+#raise 'This patch is only tested with google-api-client-ruby v0.50.0' unless Google::Apis::VERSION == "0.50.0"
 
 # The google-api-ruby-client does not have a way to increase or disable
 # the maximum allowed time for a request to be retried. By default, it
