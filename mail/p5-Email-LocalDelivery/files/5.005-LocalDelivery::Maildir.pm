--- LocalDelivery/Maildir.pm.orig	Tue Jun  1 20:04:43 2004
+++ LocalDelivery/Maildir.pm	Tue Jun  1 20:06:01 2004
@@ -3,7 +3,7 @@
 use Email::Simple;
 use File::Path;
 
-our $VERSION = "1.06";
+use vars qw($VERSION); $VERSION = "1.06";
 my $maildir_time    = 0;
 my $maildir_counter = 0;
 use Sys::Hostname; (my $HOSTNAME = hostname) =~ s/\..*//;
