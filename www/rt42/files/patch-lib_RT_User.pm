--- lib/RT/User.pm.orig	2016-06-08 21:49:02 UTC
+++ lib/RT/User.pm
@@ -84,6 +84,7 @@ use RT::Principals;
 use RT::ACE;
 use RT::Interface::Email;
 use Text::Password::Pronounceable;
+use RT::Util;
 
 sub _OverlayAccessible {
     {
@@ -977,11 +978,17 @@ sub IsPassword {
         # If it's a new-style (>= RT 4.0) password, it starts with a '!'
         my (undef, $method, @rest) = split /!/, $stored;
         if ($method eq "bcrypt") {
-            return 0 unless $self->_GeneratePassword_bcrypt($value, @rest) eq $stored;
+            return 0 unless RT::Util::constant_time_eq(
+                $self->_GeneratePassword_bcrypt($value, @rest),
+                $stored
+            );
             # Upgrade to a larger number of rounds if necessary
             return 1 unless $rest[0] < RT->Config->Get('BcryptCost');
         } elsif ($method eq "sha512") {
-            return 0 unless $self->_GeneratePassword_sha512($value, @rest) eq $stored;
+            return 0 unless RT::Util::constant_time_eq(
+                $self->_GeneratePassword_sha512($value, @rest),
+                $stored
+            );
         } else {
             $RT::Logger->warn("Unknown hash method $method");
             return 0;
@@ -991,16 +998,28 @@ sub IsPassword {
         my $hash = MIME::Base64::decode_base64($stored);
         # Decoding yields 30 byes; first 4 are the salt, the rest are substr(SHA256,0,26)
         my $salt = substr($hash, 0, 4, "");
-        return 0 unless substr(Digest::SHA::sha256($salt . Digest::MD5::md5(Encode::encode( "UTF-8", $value))), 0, 26) eq $hash;
+        return 0 unless RT::Util::constant_time_eq(
+            substr(Digest::SHA::sha256($salt . Digest::MD5::md5(Encode::encode( "UTF-8", $value))), 0, 26),
+            $hash
+        );
     } elsif (length $stored == 32) {
         # Hex nonsalted-md5
-        return 0 unless Digest::MD5::md5_hex(Encode::encode( "UTF-8", $value)) eq $stored;
+        return 0 unless RT::Util::constant_time_eq(
+            Digest::MD5::md5_hex(Encode::encode( "UTF-8", $value)),
+            $stored
+        );
     } elsif (length $stored == 22) {
         # Base64 nonsalted-md5
-        return 0 unless Digest::MD5::md5_base64(Encode::encode( "UTF-8", $value)) eq $stored;
+        return 0 unless RT::Util::constant_time_eq(
+            Digest::MD5::md5_base64(Encode::encode( "UTF-8", $value)),
+            $stored
+        );
     } elsif (length $stored == 13) {
         # crypt() output
-        return 0 unless crypt(Encode::encode( "UTF-8", $value), $stored) eq $stored;
+        return 0 unless RT::Util::constant_time_eq(
+            crypt(Encode::encode( "UTF-8", $value), $stored),
+            $stored
+        );
     } else {
         $RT::Logger->warning("Unknown password form");
         return 0;
@@ -1096,19 +1115,20 @@ sub GenerateAuthString {
 
 =head3 ValidateAuthString
 
-Takes auth string and protected string. Returns true is protected string
+Takes auth string and protected string. Returns true if protected string
 has been protected by user's L</AuthToken>. See also L</GenerateAuthString>.
 
 =cut
 
 sub ValidateAuthString {
     my $self = shift;
-    my $auth_string = shift;
+    my $auth_string_to_validate = shift;
     my $protected = shift;
 
     my $str = Encode::encode( "UTF-8", $self->AuthToken . $protected );
+    my $valid_auth_string = substr(Digest::MD5::md5_hex($str),0,16);
 
-    return $auth_string eq substr(Digest::MD5::md5_hex($str),0,16);
+    return RT::Util::constant_time_eq( $auth_string_to_validate, $valid_auth_string );
 }
 
 =head2 SetDisabled
