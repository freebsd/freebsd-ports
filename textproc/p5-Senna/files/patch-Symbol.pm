--- lib/Senna/Symbol.pm.orig	Wed Oct 18 14:04:47 2006
+++ lib/Senna/Symbol.pm	Wed Oct 18 14:05:03 2006
@@ -59,7 +59,7 @@
             sub %s 
             {
                 my $self = shift;
-                my %args = @_;
+                my %%args = @_;
                 $self->xs_%s(@args{qw(key)});
             }
         EOSUB
@@ -117,4 +117,4 @@
 
 Development funded by Brazil Ltd. E<lt>http://dev.razil.jp/project/senna/E<gt>
 
-=cut
\ No newline at end of file
+=cut
