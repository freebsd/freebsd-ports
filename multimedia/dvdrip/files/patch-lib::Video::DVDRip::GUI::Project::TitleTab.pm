--- lib/Video/DVDRip/GUI/Project/TitleTab.pm.orig	Sun Aug 14 17:46:36 2005
+++ lib/Video/DVDRip/GUI/Project/TitleTab.pm	Sun Aug 14 17:46:53 2005
@@ -965,7 +965,7 @@
 sub eject_dvd {
         my $self = shift;
 
-        my $command = $self->config('eject_command') . " " . $self->config('dvd_device');
+        my $command = $self->config('eject_command') . " -f " . $self->config('dvd_device') . " eject";
 
         system ("$command &");
         
@@ -975,7 +975,7 @@
 sub insert_dvd {
         my $self = shift;
 
-        my $command = $self->config('eject_command') . " -t " . $self->config('dvd_device');
+        my $command = $self->config('eject_command') . " -f " . $self->config('dvd_device') . " close";
 
          system ("$command &");
         
