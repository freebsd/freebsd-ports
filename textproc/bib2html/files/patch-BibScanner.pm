--- Bib2HTML/Parser/BibScanner.pm.orig	Fri Feb 13 09:23:42 2004
+++ Bib2HTML/Parser/BibScanner.pm	Fri Feb 13 09:23:59 2004
@@ -327,7 +327,7 @@
 
 sub transition_callback_entry_fields_main($) {
   my $self = shift ;
-  $self->addentry $self->{'BUFFER'}{'currententry'}{'key'},
+  $self->addentry( $self->{'BUFFER'}{'currententry'}{'key'},
                    $self->{'BUFFER'}{'currententry'}{'type'},
                    $self->{'BUFFER'}{'currententry'}{'fields'},
 		   $self->{'BUFFER'}{'currententry'}{'lineno'} ) ;
