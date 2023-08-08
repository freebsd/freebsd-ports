--- lib/orchestrator_client.rb.orig	2023-03-24 18:18:51 UTC
+++ lib/orchestrator_client.rb
@@ -3,6 +3,7 @@ require 'uri'
 require 'json'
 require 'openssl'
 require 'faraday'
+require 'faraday/net_http_persistent'
 
 class OrchestratorClient
   require 'orchestrator_client/error'
