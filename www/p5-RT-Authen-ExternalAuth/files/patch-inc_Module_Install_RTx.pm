
$FreeBSD$

--- inc/Module/Install/RTx.pm.orig
+++ inc/Module/Install/RTx.pm
@@ -101,7 +101,7 @@
     my %index = map { $_ => 1 } @INDEX_DIRS;
     $self->no_index( directory => $_ ) foreach grep !$index{$_}, @DIRS;
 
-    my $args = join ', ', map "q($_)", map { ($_, $path{$_}) }
+    my $args = join ', ', map "q($_)", map { ($_, "\${DESTDIR}$path{$_}") }
         grep $subdirs{$_}, keys %path;
 
     print "./$_\t=> $path{$_}\n" for sort keys %subdirs;
