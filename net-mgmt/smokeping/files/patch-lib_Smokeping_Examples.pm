--- lib/Smokeping/Examples.pm.orig	2018-02-02 21:14:55 UTC
+++ lib/Smokeping/Examples.pm
@@ -12,7 +12,7 @@ Smokeping::Examples - A module for generating the smok
 This module generates L<smokeping_examples> and the example
 configuration files distributed with Smokeping. It is supposed to be
 invoked from the smokeping distribution top directory, as it will need
-the C<etc/config.dist> template configuration file and will create files
+the C<etc/config.sample> template configuration file and will create files
 in the directories C<doc> and C<doc/examples>.
 
 =head1 DESCRIPTION
@@ -65,7 +65,7 @@ Niko Tyni <ntyni@iki.fi>
 use strict;
 
 sub read_config_template {
-	my $file = "../etc/config.dist";
+	my $file = "../etc/config.sample";
 	my $h = {
 		common => "", # everything up to the Probes section
 		probes => "",   # the Probes section, without the *** Probes *** line
@@ -107,7 +107,7 @@ specifically the L<Smokeping::Examples|Smokeping::Exam
 ${e}head1 DESCRIPTION
 
 Currently the examples differ only in the C<Probes> and C<Targets>
-sections. The other sections are taken from the C<etc/config.dist>
+sections. The other sections are taken from the C<etc/config.sample>
 configuration template in the Smokeping distribution so that the example
 files are complete.
 
