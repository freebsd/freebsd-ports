--- lib/Senna/Index.pm.orig	Sun Aug 27 00:16:57 2006
+++ lib/Senna/Index.pm	Wed Oct 25 14:27:07 2006
@@ -126,10 +126,10 @@
 
   use Senna::Index;
 
-  my $index = Senna::Index->new(path => '/path/to/index');
-  # $index = Senna::Index->open(pth => '/path/to/index');
+  my $index = Senna::Index->create(path => '/path/to/index');
+  # $index = Senna::Index->open(path => '/path/to/index');
 
-  $rc = $index->insert(key => $key, new => $new, old => $old);
+  $rc = $index->insert(key => $key, value => $new);
   $rc = $index->delete(key => $key, value => $old_value);
   $rc = $index->update(key => $key, new => $new, old => $old, section => $s);
 
@@ -161,26 +161,47 @@
 =head1 METHODS
 
 =head2 delete
+
 =head2 file_size_keys
+
 =head2 file_size_lexicon
+
 =head2 info
+
 =head2 insert
+
 =head2 inv_chunk_size
+
 =head2 inv_seg_size
+
 =head2 nrecords_keys
+
 =head2 nrecords_lexicon
+
 =head2 path
+
 =head2 query_exec
+
 =head2 rename
+
 =head2 select
+
 =head2 update
+
 =head2 close
+
 =head2 create
+
 =head2 encoding
+
 =head2 flags
+
 =head2 initial_n_segments
+
 =head2 key_size
+
 =head2 open
+
 =head2 remove
 
 =head1 AUTHOR
@@ -197,4 +218,4 @@
 
 http://qwik.jp/senna - Senna Development Homepage
 
-=cut
\ No newline at end of file
+=cut
