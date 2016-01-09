--- lib/MSDW/SMTP/Server.pm.orig	2009-07-27 13:33:29 UTC
+++ lib/MSDW/SMTP/Server.pm
@@ -11,7 +11,7 @@
 # Written by Bennett Todd <bet@rahul.net>
 
 package MSDW::SMTP::Server;
-use IO::Socket;
+use IO::Socket::INET6;
 use IO::File;
 
 =head1 NAME
@@ -88,15 +88,14 @@ desired.
 =item new(interface => $interface, port => $port);
 
 The interface and port to listen on must be specified. The interface
-must be a valid numeric IP address (0.0.0.0 to listen on all
-interfaces, as usual); the port must be numeric. If this call
-succeeds, it returns a server structure with an open
-IO::Socket::INET in it, ready to listen on. If it fails it dies, so
-if you want anything other than an exit with an explanatory error
-message, wrap the constructor call in an eval block and pull the
-error out of $@ as usual. This is also the case for all other
-methods; they succeed or they die.
-
+must be a valid numeric IPv4 or IPv6 address (0.0.0.0 or :: to listen
+on all interfaces, as usual); the port must be numeric. If this call
+succeeds, it returns a server structure with an open IO::Socket::INET6
+in it, ready to listen on. If it fails it dies, so if you want
+anything other than an exit with an explanatory error message, wrap
+the constructor call in an eval block and pull the error out of $@ as
+usual. This is also the case for all other methods; they succeed or
+they die.
 =item accept([debug => FD]);
 
 accept takes optional args and returns nothing. If an error occurs
@@ -154,7 +153,7 @@ sub new {
     my ($this, @opts) = @_;
     my $class = ref($this) || $this;
     my $self = bless { @opts }, $class;
-    $self->{sock} = IO::Socket::INET->new(
+    $self->{sock} = IO::Socket::INET6->new(
 	LocalAddr => $self->{interface},
 	LocalPort => $self->{port},
 	Proto => 'tcp',
