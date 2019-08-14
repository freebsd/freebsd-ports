--- lib/Mail/SPF/Record.pm.orig	2013-07-22 03:52:32 UTC
+++ lib/Mail/SPF/Record.pm
@@ -206,6 +206,7 @@ sub parse_version_tag {
 
 sub parse_term {
     my ($self) = @_;
+    require Mail::SPF::Mech;
     if (
         $self->{parse_text} =~ s/
             ^
