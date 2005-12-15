--- lib/RRD/Format.pm.orig	Wed Jan 21 05:11:09 2004
+++ lib/RRD/Format.pm	Thu Dec 15 13:44:36 2005
@@ -120,6 +120,7 @@
         $self->{'dsDef'} = "a20 a20 L x4 d d x56";
         $self->{'rraDef'} = "a20 L L d x72";
         $self->{'pdpDef'} = "a30 x2 L x4 d x64";
+	$self->{"liveHead3"} = "L L";
         $self->{'cdpDef'} = "d L x4 x64";
 
         $self->{'liveHead'} = "L";
