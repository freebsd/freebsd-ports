--- inc/GSLBuilder.pm.orig	2020-06-12 22:07:37 UTC
+++ inc/GSLBuilder.pm
@@ -279,7 +279,7 @@ sub link_c {
       }
     }
 
-    my @lddlflags = $self->split_like_shell($cf->{lddlflags});
+    my @lddlflags = $self->split_like_shell($Config{lddlflags});
     my @shrp      = $self->split_like_shell($cf->{shrpenv});
     my @ld        = $self->split_like_shell($cf->{ld} || $Config{cc});
 
@@ -311,7 +311,7 @@ sub compile_c {
 
   $cf->{installarchlib} = $Config{archlib};
 
-  my @include_dirs = @{$p->{include_dirs}}
+  my @include_dirs = ( @{$p->{include_dirs}} && ( ${@{$p->{include_dirs}}}[0] ne "" ) )
 			? map {"-I$_"} (@{$p->{include_dirs}}, catdir($cf->{installarchlib}, 'CORE'))
 			: map {"-I$_"} ( catdir($cf->{installarchlib}, 'CORE') ) ;
 
