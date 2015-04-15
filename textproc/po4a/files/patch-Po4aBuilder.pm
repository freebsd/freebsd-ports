--- Po4aBuilder.pm.orig	2013-08-21 15:11:04.000000000 -0500
+++ Po4aBuilder.pm	2015-04-06 11:57:21.938813000 -0500
@@ -132,13 +132,13 @@
 
     require ExtUtils::Install;
 #    $self->depends_on('build');
-    my $mandir = $self->install_sets($self->installdirs)->{'bindoc'};
+    my $mandir = $self->install_path->{'bindoc'};
     $mandir =~ s,/man1$,,;
     $self->install_path(man => $mandir);
     $self->install_path(manl10n => $mandir);
 
     my $localedir = $mandir;
-    $localedir =~ s,/man$,/locale,;
+    $localedir =~ s,/man$,/share/locale,;
     $self->install_path(po => $localedir);
 
     ExtUtils::Install::install($self->install_map, !$self->quiet, 0, $self->{args}{uninst}||0);
