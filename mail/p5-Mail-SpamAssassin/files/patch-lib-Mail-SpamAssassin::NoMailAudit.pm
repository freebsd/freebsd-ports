--- lib/Mail/SpamAssassin/NoMailAudit.pm.orig	Mon Feb 11 15:42:13 2002
+++ lib/Mail/SpamAssassin/NoMailAudit.pm	Mon Feb 11 15:42:23 2002
@@ -302,7 +302,7 @@
   my $file = shift;
 
   # some bits of code from Mail::Audit here:
-  $file ||= $ENV{'MAIL'} || "/var/spool/mail/".getpwuid($>);
+  $file ||= $ENV{'MAIL'} || "/var/mail/".getpwuid($>);
 
   if (exists $self->{accept}) {
     return $self->{accept}->();
@@ -321,7 +321,7 @@
 
     if (!defined $gotlock) {
       # dot-locking not supported here (probably due to file permissions
-      # on the /var/spool/mail dir).  just use flock().
+      # on the /var/mail dir).  just use flock().
       $nodotlocking = 1;
     } 
