--- Po4aBuilder.pm.orig	2013-08-21 20:11:04 UTC
+++ Po4aBuilder.pm
@@ -132,13 +132,13 @@ sub ACTION_install {
 
     require ExtUtils::Install;
 #    $self->depends_on('build');
-    my $mandir = $self->install_sets($self->installdirs)->{'bindoc'};
+    my $mandir = $self->install_path->{'bindoc'};
     $mandir =~ s,/man1$,,;
     $self->install_path(man => $mandir);
     $self->install_path(manl10n => $mandir);
 
-    my $localedir = $mandir;
-    $localedir =~ s,/man$,/locale,;
+    my $localedir = $self->install_path->{'bin'};
+    $localedir =~ s,/bin$,/share/locale,;
     $self->install_path(po => $localedir);
 
     ExtUtils::Install::install($self->install_map, !$self->quiet, 0, $self->{args}{uninst}||0);
