--- lib/CGI/Kwiki/Template.pm.orig	Fri Aug 29 09:30:19 2003
+++ lib/CGI/Kwiki/Template.pm	Wed Oct 15 11:37:23 2003
@@ -71,7 +71,8 @@
     my ($self, $text, $v) = @_;
     my $re;
     $text = $self->loc($text);
-    $re = qr/\[((?:(?>[^\[\]]+)|(??{$re}))*)\]/;
+    #$re = qr/\[((?:(?>[^\[\]]+)|(??{$re}))*)\]/;
+    $re = qr/\[((?:(?>[^\[\]]+)|\[[^\[\]]*\])*)\]/;
     $text =~ s{$re}
               {<a href="[% script %]?$1">$1</a>}g;
     $text =~ s{\[%\s+(\w+)\s+%\]\n?}
