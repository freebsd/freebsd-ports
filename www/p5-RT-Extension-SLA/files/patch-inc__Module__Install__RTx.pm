--- ./inc/Module/Install/RTx.pm.orig	2014-07-01 20:40:45.000000000 +0100
+++ ./inc/Module/Install/RTx.pm	2014-07-03 23:02:03.735533399 +0100
@@ -77,7 +77,7 @@
     my %index = map { $_ => 1 } @INDEX_DIRS;
     $self->no_index( directory => $_ ) foreach grep !$index{$_}, @DIRS;
 
-    my $args = join ', ', map "q($_)", map { ($_, $path{$_}) }
+    my $args = join ', ', map "q($_)", map { ($_, "\${DESTDIR}$path{$_}") }
         sort keys %path;
 
     printf "%-10s => %s\n", $_, $path{$_} for sort keys %path;
