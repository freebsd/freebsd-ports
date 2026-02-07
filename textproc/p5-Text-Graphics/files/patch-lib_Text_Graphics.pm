--- lib/Text/Graphics.pm.orig	1998-06-23 01:00:27 UTC
+++ lib/Text/Graphics.pm
@@ -49,8 +49,8 @@ sub add {
   my $child = shift;
   my $offx = shift;
   my $offy = shift;
-  $child->{offx} = ($offx > 0) ? $offx : 0;
-  $child->{offy} = ($offy > 0) ? $offy : 0;
+  $child->{offx} = (defined($offx) && $offx > 0) ? $offx : 0;
+  $child->{offy} = (defined($offy) && $offy > 0) ? $offy : 0;
   $child->{parent} = $this;
   
   push @{ $this->{children} }, $child;
@@ -78,7 +78,7 @@ sub _drawBackground {
   my $this = shift;
   my $gc = shift;
   
-  if ($this->{bg} ne undef) {
+  if (defined $this->{bg}) {
     $gc->fillRect($this->{bg}, 0, 0, $this->{width}, $this->{height});
   }
 }
@@ -413,7 +413,7 @@ sub setSize {
   ## we need to re-wrap iff the width changes
   ##
   
-  if (($width ne undef) and ($this->{width} != $width)) {
+  if ((defined $width) and ($this->{width} != $width)) {
     delete $this->{text_was_wrapped};
   }
   
