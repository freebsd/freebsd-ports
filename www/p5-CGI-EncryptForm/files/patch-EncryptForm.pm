--- EncryptForm.pm.orig	2010-03-11 15:18:24.000000000 -0500
+++ EncryptForm.pm	2010-03-11 15:18:50.000000000 -0500
@@ -10,7 +10,7 @@
 package CGI::EncryptForm;
 
 use Crypt::HCE_SHA;
-use Storable qw(freeze thaw);
+use Storable qw(nfreeze thaw);
 use Digest::SHA1 qw(sha1);
 
 use strict;
@@ -70,7 +70,7 @@
 
 	my $random_key = $self->_random_key();
 
-	my $str = freeze($decrypted_hashref);
+	my $str = nfreeze($decrypted_hashref);
 	$str = sha1($str) . $str;
 
 	my $cipher = Crypt::HCE_SHA->new($secret_key, $random_key);
