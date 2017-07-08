--- lib/RT/Authen/ExternalAuth/DBI.pm.orig	2016-07-18 20:20:17 UTC
+++ lib/RT/Authen/ExternalAuth/DBI.pm
@@ -50,6 +50,7 @@ package RT::Authen::ExternalAuth::DBI;
 
 use DBI;
 use RT::Authen::ExternalAuth::DBI::Cookie;
+use RT::Util;
 
 use warnings;
 use strict;
@@ -81,6 +82,7 @@ Provides the database implementation for
             'p_field'                   =>  'password',
 
             # Example of custom hashed password check
+            # (See below for security concerns with this implementation)
             #'p_check'                   =>  sub {
             #    my ($hash_from_db, $password) = @_;
             #    return $hash_from_db eq function($password);
@@ -170,6 +172,17 @@ An example, where C<FooBar()> is some ex
 Importantly, the C<p_check> subroutine allows for arbitrarily complex password
 checking unlike C<p_enc_pkg> and C<p_enc_sub>.
 
+Please note, the use of the C<eq> operator in the C<p_check> example above
+introduces a timing sidechannel vulnerability. (It was left there for clarity
+of the example.) There is a comparison function available in RT that is
+hardened against timing attacks. The comparison from the above example could
+be re-written with it like this:
+
+    p_check => sub {
+        my ($hash_from_db, $password) = @_;
+        return RT::Util::constant_time_eq($hash_from_db, FooBar($password));
+    },
+
 =item p_enc_pkg, p_enc_sub
 
 The Perl package and subroutine used to encrypt passwords from the
@@ -298,7 +311,7 @@ sub GetAuth {
         # Jump to the next external authentication service if they don't match
         if(defined($db_p_salt)) {
             $RT::Logger->debug("Using salt:",$db_p_salt);
-            if(${encrypt}->($password,$db_p_salt) ne $pass_from_db){
+            unless (RT::Util::constant_time_eq(${encrypt}->($password,$db_p_salt), $pass_from_db)) {
                 $RT::Logger->info(  $service,
                                     "AUTH FAILED",
                                     $username,
@@ -306,7 +319,7 @@ sub GetAuth {
                 return 0;
             }
         } else {
-            if(${encrypt}->($password) ne $pass_from_db){
+            unless (RT::Util::constant_time_eq(${encrypt}->($password), $pass_from_db)) {
                 $RT::Logger->info(  $service,
                                     "AUTH FAILED",
                                     $username,
