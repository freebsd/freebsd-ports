$FreeBSD$

--- FIGlet.pm.orig	Fri May 24 20:25:42 2002
+++ FIGlet.pm	Fri May 24 20:25:59 2002
@@ -174,7 +174,7 @@
 	    $opts{-A} .= "\0" x ($self->{_font}->[ord($_)]->[0]-1) . $_;
 	  }
 	}
-        $opts{-A} = Text::Wrap::wrap('', '', $opts{-A}), "\n";
+        $opts{-A} = Text::Wrap::wrap('', '', $opts{-A});
 	$opts{-A} =~ tr/\0//d;
     }
     @text = split("\n", $opts{-A});
