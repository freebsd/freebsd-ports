--- Po4aBuilder.pm.orig	2014-03-25 01:47:00.000000000 -0300
+++ Po4aBuilder.pm	2014-03-25 01:47:32.000000000 -0300
@@ -138,7 +138,7 @@
     $self->install_path(manl10n => $mandir);
 
     my $localedir = $mandir;
-    $localedir =~ s,/man$,/locale,;
+    $localedir =~ s,/man$,/share/locale,;
     $self->install_path(po => $localedir);
 
     ExtUtils::Install::install($self->install_map, !$self->quiet, 0, $self->{args}{uninst}||0);
