--- ./inc/Module/Install/RTx.pm.orig	2014-07-02 03:19:37.000000000 +0100
+++ ./inc/Module/Install/RTx.pm	2014-07-03 22:52:03.274581922 +0100
@@ -77,7 +77,7 @@
     my %index = map { $_ => 1 } @INDEX_DIRS;
     $self->no_index( directory => $_ ) foreach grep !$index{$_}, @DIRS;
 
-    my $args = join ', ', map "q($_)", map { ($_, $path{$_}) }
+    my $args = join ', ', map "q($_)", map { ($_, "\${DESTDIR}$path{$_}") }
         sort keys %path;
 
     printf "%-10s => %s\n", $_, $path{$_} for sort keys %path;
