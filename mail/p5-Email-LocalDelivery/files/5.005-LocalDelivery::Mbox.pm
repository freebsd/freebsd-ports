--- LocalDelivery/Mbox.pm.orig	Fri Nov 14 10:04:24 2003
+++ LocalDelivery/Mbox.pm	Tue Jun  1 20:03:37 2004
@@ -4,7 +4,7 @@
 use Email::Simple;
 use Fcntl ':flock';
 
-our $VERSION = "1.07";
+use vars qw($VERSION); $VERSION = "1.07";
 
 sub deliver {
     my ($class, $mail, @files) = @_;
@@ -13,15 +13,15 @@
         my $dir = dirname($file);
         next if ! -d $dir and not mkpath($dir);
 
-        open my $fh, ">> $file"               or next;
-        $class->getlock($fh)                  || next;
-        seek $fh, 0, 2;
-        print $fh "\n" if tell($fh) > 0;
-        print $fh $class->_from_line(\$mail); # Avoid passing $mail where poss.
-        print $fh $class->_escape_from_body(\$mail);
-        print $fh "\n" unless $mail =~ /\n$/;
-        $class->unlock($fh)                   || next;
-        close $fh                             or next;
+        open FH, ">> $file"               or next;
+        $class->getlock(FH)                  || next;
+        seek FH, 0, 2;
+        print FH "\n" if tell(FH) > 0;
+        print FH $class->_from_line(\$mail); # Avoid passing $mail where poss.
+        print FH $class->_escape_from_body(\$mail);
+        print FH "\n" unless $mail =~ /\n$/;
+        $class->unlock(FH)                   || next;
+        close FH                             or next;
         push @rv, $file
     }
     return @rv;
