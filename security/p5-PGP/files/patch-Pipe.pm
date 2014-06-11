--- PGP/Pipe.pm.orig	2014-06-10 19:55:03.000000000 +0200
+++ PGP/Pipe.pm	2014-06-10 19:55:17.000000000 +0200
@@ -55,7 +55,7 @@
 	$pgp = new PGP [$pgppath], [$pgpexec];
 
 Create the PGP encapsulation object. The standard location for the 
-PGP executable is /usr/local/bin/pgp.
+PGP executable is /usr/local/bin/pgpin.
 
 =cut
 
@@ -63,7 +63,7 @@
 {
   my $class = shift;
   my $pgppath = shift || "$ENV{HOME}/.pgp";
-  my $pgpexec = shift || "/usr/local/bin/pgp";
+  my $pgpexec = shift || "/usr/local/bin/pgpin";
   		 
   if (! -e "$pgppath/config.txt" &&
       ! -e "/usr/local/lib/pgp/config.txt" )
