--- lib/rabbiter.rb.orig	2013-07-21 22:07:28.000000000 +0900
+++ lib/rabbiter.rb	2013-07-21 22:08:26.000000000 +0900
@@ -149,9 +149,9 @@
         @client = Gio::SocketClient.new
         @client.tls = @options[:ssl]
         @client.tls_validation_flags = :validate_all
-        if Rabbit::Utils.windows?
+#        if Rabbit::Utils.windows?
           @client.tls_validation_flags -= :unknown_ca
-        end
+#        end
         @connection = @client.connect_to_host(@options[:host], @options[:port])
         @socket = @connection.socket
         @socket.blocking = false
