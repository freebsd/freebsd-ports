--- util/parserom.pl.orig	2016-11-03 13:22:25 UTC
+++ util/parserom.pl
@@ -157,7 +157,7 @@ sub process_isa_rom {
 
 # Output Makefile rules for the specified ROM declarations
 sub print_make_rules {
-    my ( $state, my $image, my $desc, my $vendor, my $device, my $dup ) = @_;
+    my ( $state, $image, $desc, $vendor, $device, $dup ) = @_;
     unless ( $state->{'is_header_printed'} ) {
         print "# NIC\t\n";
         print "# NIC\tfamily\t$state->{family}\n";
