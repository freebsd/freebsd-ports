--- lib/Razor2/Client/Agent.pm.orig	Sun Nov  3 21:07:21 2002
+++ lib/Razor2/Client/Agent.pm	Sun Nov  3 21:08:17 2002
@@ -753,10 +753,11 @@
     foreach my $file (@ARGV) {
         my $fh;
         my @message = ();
-        if (ref $file) { 
-            $fh = $file
+        if ($file eq '-') { 
+            $fh = \*STDIN;
         } else { 
-            open $fh, "<$file" or return $self->error("Can't open $file: $!");
+            open FH, "<$file" or return $self->error("Can't open $file: $!");
+            $fh = \*FH;
         }
         next unless defined(my $line = <$fh>);
         if ($line =~ /^From /) {
