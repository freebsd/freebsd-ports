--- lib/RT/Util.pm.orig	2016-06-08 21:49:02 UTC
+++ lib/RT/Util.pm
@@ -54,6 +54,8 @@ use warnings;
 use base 'Exporter';
 our @EXPORT = qw/safe_run_child mime_recommended_filename/;
 
+use Encode qw/encode/;
+
 sub safe_run_child (&) {
     my $our_pid = $$;
 
@@ -150,6 +152,58 @@ sub assert_bytes {
 }
 
 
+=head2 C<constant_time_eq($a, $b)>
+
+Compares two strings for equality in constant-time. Replacement for the C<eq>
+operator designed to avoid timing side-channel vulnerabilities. Returns zero
+or one.
+
+This is intended for use in cryptographic subsystems for comparing well-formed
+data such as hashes - not for direct use with user input or as a general
+replacement for the C<eq> operator.
+
+The two string arguments B<MUST> be of equal length. If the lengths differ,
+this function will call C<die()>, as proceeding with execution would create
+a timing vulnerability. Length is defined by characters, not bytes.
+
+This code has been tested to do what it claims. Do not change it without
+thorough statistical timing analysis to validate the changes.
+
+Added to resolve CVE-2017-5361
+
+For more on timing attacks, see this Wikipedia article:
+B<https://en.wikipedia.org/wiki/Timing_attack>
+
+=cut
+
+sub constant_time_eq {
+    my ($a, $b) = @_;
+
+    my $result = 0;
+
+    # generic error message avoids potential information leaks
+    my $generic_error = "Cannot compare values";
+    die $generic_error unless defined $a and defined $b;
+    die $generic_error unless length $a == length $b;
+    die $generic_error if ref($a) or ref($b);
+
+    for (my $i = 0; $i < length($a); $i++) {
+        my $a_char = substr($a, $i, 1);
+        my $b_char = substr($b, $i, 1);
+
+        # encode() is set to die on malformed
+        my @a_octets = unpack("C*", encode('UTF-8', $a_char, Encode::FB_CROAK));
+        my @b_octets = unpack("C*", encode('UTF-8', $b_char, Encode::FB_CROAK));
+        die $generic_error if (scalar @a_octets) != (scalar @b_octets);
+
+        for (my $j = 0; $j < scalar @a_octets; $j++) {
+            $result |= $a_octets[$j] ^ $b_octets[$j];
+        }
+    }
+    return 0 + not $result;
+}
+
+
 RT::Base->_ImportOverlays();
 
 1;
