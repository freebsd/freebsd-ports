--- lib/Mail/SpamAssassin/EvalTests.pm.orig	Fri Jan 25 07:36:02 2002
+++ lib/Mail/SpamAssassin/EvalTests.pm	Sun Mar  3 13:02:37 2002
@@ -688,10 +688,17 @@
 
 sub check_for_faraway_charset_in_headers {
   my ($self) = @_;
+  my $hdr;
 
   my @locales = $self->get_my_locales();
   for my $h (qw(From Subject)) {
-    my $hdr = $self->get($h);
+# Can't use just get() because it un-mime header and strip charset part
+    my @hdrs = $self->{msg}->get_header ($h);
+    if ($#hdrs >= 0) {
+      $hdr = join (" ", @hdrs);
+    } else {
+      $hdr = '';
+    }
     while ($hdr =~ /=\?(.+?)\?.\?.*?\?=/g) {
       Mail::SpamAssassin::Locales::is_charset_ok_for_locales($1, @locales)
 	  or return 1;
