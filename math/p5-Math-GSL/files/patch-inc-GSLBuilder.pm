Copy the attached patch to: files/patch-inc-GSLBuilder.pm

Patch attached with submission follows:

--- inc/GSLBuilder.pm	2009-05-20 02:50:44.000000000 -0400
+++ inc/GSLBuilder.pm	2009-08-04 20:15:57.000000000 -0400
@@ -154,7 +154,7 @@
 
   $cf->{installarchlib} = $Config{archlib};
 
-  my @include_dirs = @{$p->{include_dirs}} 
+  my @include_dirs = ( @{$p->{include_dirs}} && ( ${@{$p->{include_dirs}}}[0] ne "" ) ) 
 			? map {"-I$_"} (@{$p->{include_dirs}}, catdir($cf->{installarchlib}, 'CORE'))
 			: map {"-I$_"} ( catdir($cf->{installarchlib}, 'CORE') ) ;
 


