--- lib/Text/Graphics.pm.orig	Sat Dec 30 20:01:06 2000
+++ lib/Text/Graphics.pm	Sat Dec 30 20:02:21 2000
@@ -49,8 +49,8 @@
   my $child = shift;
   my $offx = shift;
   my $offy = shift;
-  $child->{offx} = ($offx > 0) ? $offx : 0;
-  $child->{offy} = ($offy > 0) ? $offy : 0;
+  $child->{offx} = (defined($offx) && $offx > 0) ? $offx : 0;
+  $child->{offy} = (defined($offy) && $offy > 0) ? $offy : 0;
   $child->{parent} = $this;
   
   push @{ $this->{children} }, $child;
@@ -78,7 +78,7 @@
   my $this = shift;
   my $gc = shift;
   
-  if ($this->{bg} ne undef) {
+  if (defined $this->{bg}) {
     $gc->fillRect($this->{bg}, 0, 0, $this->{width}, $this->{height});
   }
 }
@@ -413,7 +413,7 @@
   ## we need to re-wrap iff the width changes
   ##
   
-  if (($width ne undef) and ($this->{width} != $width)) {
+  if ((defined $width) and ($this->{width} != $width)) {
     delete $this->{text_was_wrapped};
   }
