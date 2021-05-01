--- lib/Video/DVDRip/GUI/Project/Title.pm.orig	Fri Sep 22 15:53:09 2006
+++ lib/Video/DVDRip/GUI/Project/Title.pm	Fri Sep 22 15:56:35 2006
@@ -433,8 +433,10 @@
     my $title = $self->selected_title;
 
     my $command
-        = $self->config('eject_command') . " " .
-            $title->project->dvd_device;
+        = $self->config('eject_command') . " -f " .
+            $title->project->dvd_device .
+	    " eject";
+
 
     system("$command &");
 
@@ -446,8 +448,9 @@
 
     my $title = $self->selected_title;
 
-    my $command = $self->config('eject_command') . " -t "
-        . $title->project->dvd_device;
+    my $command = $self->config('eject_command') . " -f " .
+        $title->project->dvd_device .
+	" close";
 
     system("$command &");
 
