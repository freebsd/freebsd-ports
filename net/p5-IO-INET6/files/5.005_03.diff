--- INET6.pm.orig	Tue Jun 24 14:14:26 2003
+++ INET6.pm	Wed Jul  2 21:33:28 2003
@@ -10,7 +10,7 @@
 package IO::Socket::INET6;
 
 use strict;
-our(@ISA, $VERSION);
+use vars qw(@ISA $VERSION);
 use IO::Socket;
 use Socket6;
 use Carp;
@@ -20,7 +20,7 @@
 @ISA = qw(IO::Socket);
 $VERSION = "1.27";
 
-my $EINVAL = exists(&Errno::EINVAL) ? Errno::EINVAL() : 1;
+my $EINVAL = defined(&Errno::EINVAL) ? Errno::EINVAL() : 1;
 
 IO::Socket::INET6->register_domain( AF_INET6 );
 
@@ -183,7 +183,7 @@
 	}
 
 	if ($arg->{ReusePort}) {
-	    $sock->sockopt(SO_REUSEPORT,1) or
+	    $sock->sockopt(0x0200,1) or
 		    return _error($sock, $!, "$!");
 	}
 
