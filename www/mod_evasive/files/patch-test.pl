--- test.pl.orig	2017-02-22 02:33:36 UTC
+++ test.pl
@@ -10,7 +10,7 @@ for(0..100) {
   my($SOCKET) = new IO::Socket::INET( Proto   => "tcp",
                                       PeerAddr=> "127.0.0.1:80");
   if (! defined $SOCKET) { die $!; }
-  print $SOCKET "GET /?$_ HTTP/1.0\n\n";
+  print $SOCKET "GET /?$_ HTTP/1.0\r\n\r\n";
   $response = <$SOCKET>;
   print $response;
   close($SOCKET);
