--- Saryer.pm.orig	Mon Dec 18 14:10:08 2000
+++ Saryer.pm	Tue Oct  8 23:04:36 2002
@@ -13,10 +13,10 @@
 
 =head1 SYNOPSIS
 
-  my $saryer = Search::Saryer::new(filename->'search.txt');
+  my $saryer = Search::Saryer::new(filename=>'search.txt');
 
   if (defined $saryer->search($pattern)) {
-    while (defined ($line = saryer->get_next_line())) {
+    while (defined ($line = $saryer->get_next_line())) {
       print $line;
     }
   }
@@ -27,7 +27,7 @@
 
 =head2 new
 
-  $saryer->new('filename'->'file.txt')
+  $saryer->new('filename'=>'file.txt')
 
 Create saryer object.
 If creation process was failed, it returns undef.
