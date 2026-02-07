--- lib/RRD/Format.pm.orig	2010-06-30 09:34:19.000000000 +0200
+++ lib/RRD/Format.pm	2010-06-30 09:36:16.000000000 +0200
@@ -120,6 +120,7 @@
         $self->{'dsDef'} = "a20 a20 L x4 d d x56";
         $self->{'rraDef'} = "a20 L L d x72";
         $self->{'pdpDef'} = "a30 x2 L x4 d x64";
+	$self->{"liveHead3"} = "L L";
         $self->{'cdpDef'} = "d L x4 x64";
 
         $self->{'liveHead'} = "L";
@@ -127,6 +128,19 @@
         $self->{'element'} = "d";
 
         return 1;
+    } elsif ($archname eq 'amd64-freebsd') {
+
+	$self->{'statHead'} = "a4 a5 x7 d Q Q Q x80";
+	$self->{'dsDef'} = "a20 a20 Q d d x56";
+	$self->{'rraDef'} = "a20 x4 Q Q d x72";
+	$self->{'pdpDef'} = "a30 x2 Q d x64";
+	$self->{'cdpDef'} = "d Q x64";
+	$self->{'liveHead'} = "Q";
+	$self->{'rraPtr'} = "Q";
+	$self->{'element'} = "d";
+	$self->{'liveHead3'} = "Q Q";
+
+        return 1;
     } elsif ( $archname eq 'alpha-dec_osf') {
         # Thanks to Melissa D. Binde <binde@amazon.com> for
         # finding this (and a major foobar in getFormat.c)
