--- lib/Net/SNPP/Server.pm.orig	Fri Oct  3 15:46:55 2003
+++ lib/Net/SNPP/Server.pm	Sun Oct  5 12:29:05 2003
@@ -1,6 +1,5 @@
 package Net::SNPP::Server;
 use strict;
-use warnings;
 use Socket;
 use IO::Handle;
 use Net::Cmd;
@@ -415,7 +414,6 @@
         # 4.3.6 HELP (optional) ---------------------------------------------- #
         elsif ( $user_cmd eq 'HELP' ) {
             {
-                no warnings; # so we can use <DATA>
                 while (<DATA>) { $client->command( $_ ) }
                 $client->command( "250 End of Help Information" );
             }
@@ -573,7 +571,9 @@
     my @pids = (); # pids to merge before exit
 
 	# create a pipe for communication from child back to this process
-	our( $rp, $wp ) = ( IO::Handle->new(), IO::Handle->new() );
+	use vars qw($rp $wp);
+	$rp = IO::Handle->new();
+	$wp = IO::Handle->new();
 	pipe( $rp, $wp )
 	    || die "could not create READ/WRITE pipes";
     $wp->autoflush(1);
