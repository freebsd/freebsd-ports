--- src/lavinmqperf.cr.orig	2023-01-02 14:26:00 UTC
+++ src/lavinmqperf.cr
@@ -482,7 +482,7 @@ class ConnectionCount < Perf
 
   private def client : AMQP::Client
     client = @client ||= AMQP::Client.new(@uri)
-    client.host = "127.0.#{Random.rand(UInt8)}.#{Random.rand(UInt8)}" if @random_localhost
+    # client.host = "127.0.#{Random.rand(UInt8)}.#{Random.rand(UInt8)}" if @random_localhost
     client
   end
 
