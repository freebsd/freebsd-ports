diff -Naurp ModPerl-Registry/lib/ModPerl/RegistryCooker.pm.orig ModPerl-Registry/lib/ModPerl/RegistryCooker.pm
--- ModPerl-Registry/lib/ModPerl/RegistryCooker.pm.orig	2006-11-19 18:31:41.000000000 -0500
+++ ModPerl-Registry/lib/ModPerl/RegistryCooker.pm	2007-03-30 19:08:05.000000000 -0400
@@ -337,7 +337,7 @@ sub namespace_from_uri {
     my $self = shift;
 
     my $path_info = $self->{REQ}->path_info;
-    my $script_name = $path_info && $self->{URI} =~ /$path_info$/
+    my $script_name = $path_info && $self->{URI} =~ /\Q$path_info\E$/
         ? substr($self->{URI}, 0, length($self->{URI}) - length($path_info))
         : $self->{URI};
 
