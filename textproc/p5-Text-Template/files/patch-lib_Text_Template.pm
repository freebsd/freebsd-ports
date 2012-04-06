--- lib/Text/Template.pm.orig	2008-04-16 18:38:08.000000000 -0500
+++ lib/Text/Template.pm	2012-03-17 06:44:14.882739137 -0500
@@ -428,6 +428,8 @@
     foreach my $key (keys %$hash) {
       undef $hash->{$key};
     }
+    %$hash = ();
+    delete $Text::Template::{$s."::"};
   }
 }
