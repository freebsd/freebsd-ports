--- inc/GSLBuilder.pm.orig	2011-09-18 00:40:52.000000000 +0800
+++ inc/GSLBuilder.pm	2011-09-20 10:26:22.405819397 +0800
@@ -258,7 +258,7 @@
 
   $cf->{installarchlib} = $Config{archlib};
 
-  my @include_dirs = @{$p->{include_dirs}}
+  my @include_dirs = ( @{$p->{include_dirs}} && ( ${@{$p->{include_dirs}}}[0] ne "" ) )
 			? map {"-I$_"} (@{$p->{include_dirs}}, catdir($cf->{installarchlib}, 'CORE'))
 			: map {"-I$_"} ( catdir($cf->{installarchlib}, 'CORE') ) ;
 
