--- JIT/Base.pm	Wed Jun  9 15:31:15 2004
+++ JIT/Base.pm	Wed Jun  9 15:34:32 2004
@@ -75,7 +75,7 @@
 
   foreach my $row (@$array) {
     croak("Bad param settings - found non hash-ref for loop row in loop $loop_name!")
-      unless ref $row eq 'HASH';
+      unless ref $row && UNIVERSAL::isa($row, 'HASH');
     
     my $lc_name;
     foreach my $name (keys %$row) {
