--- lib/Senna/Index.pm.orig	Sat Mar 17 01:45:57 2007
+++ lib/Senna/Index.pm	Tue May  1 20:38:32 2007
@@ -126,8 +126,8 @@
 
   use Senna::Index;
 
-  my $index = Senna::Index->new(path => '/path/to/index');
-  # $index = Senna::Index->open(pth => '/path/to/index');
+  my $index = Senna::Index->create(path => '/path/to/index');
+  # $index = Senna::Index->open(path => '/path/to/index');
 
   $rc = $index->insert(key => $key, value => $new);
   $rc = $index->delete(key => $key, value => $old_value);
@@ -218,4 +218,4 @@
 
 http://qwik.jp/senna - Senna Development Homepage
 
-=cut
\ No newline at end of file
+=cut
