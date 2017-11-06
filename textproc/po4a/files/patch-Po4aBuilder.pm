--- Po4aBuilder.pm.orig	2017-03-29 14:02:01 UTC
+++ Po4aBuilder.pm
@@ -140,8 +140,8 @@ sub ACTION_install {
     $mandir =~ s,/man3$,,;
     $self->install_path(man => $mandir);
 
-    my $localedir = $self->install_destination('libdoc');
-    $localedir =~ s,/man/man3$,/locale,;
+    my $localedir = $self->install_destination('bin');
+    $localedir =~ s,/bin$,/share/locale,;
     $self->install_path(po => $localedir);
 
     ExtUtils::Install::install($self->install_map, !$self->quiet, 0, $self->{args}{uninst}||0);
