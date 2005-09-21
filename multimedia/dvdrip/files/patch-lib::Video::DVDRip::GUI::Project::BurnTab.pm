--- lib/Video/DVDRip/GUI/Project/BurnTab.pm.orig	Sun Aug 14 17:42:57 2005
+++ lib/Video/DVDRip/GUI/Project/BurnTab.pm	Sun Aug 14 17:44:50 2005
@@ -839,7 +839,7 @@
 sub eject_media {
         my $self = shift;
 
-        my $command = $self->config('eject_command') . " " . $self->config('writer_device');
+        my $command = $self->config('eject_command') . " -f " . $self->config('writer_device') . " eject";
 
         system ("$command &");
 
@@ -849,7 +849,7 @@
 sub insert_media {
         my $self = shift;
 
-        my $command = $self->config('eject_command') . " -t " . $self->config('writer_device');
+        my $command = $self->config('eject_command') . " -f " . $self->config('writer_device') . " close";
 
         system ("$command &");
 
