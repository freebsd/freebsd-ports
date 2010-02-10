--- lib/Mail/SpamAssassin/Message.pm.orig	2010/01/29 15:48:09	904525
+++ lib/Mail/SpamAssassin/Message.pm	2010/01/29 15:48:29	904526
@@ -114,6 +114,7 @@
   $self->{pristine_body} =	'';
   $self->{mime_boundary_state} = {};
   $self->{line_ending} =	"\012";
+  $self->{master_deadline} = $opts->{'master_deadline'};
   $self->{suppl_attrib} = $opts->{'suppl_attrib'};
 
   bless($self,$class);

