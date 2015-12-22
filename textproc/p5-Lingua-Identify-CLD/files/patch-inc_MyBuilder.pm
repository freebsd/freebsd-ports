--- inc/MyBuilder.pm.orig	2014-09-07 20:44:12 UTC
+++ inc/MyBuilder.pm
@@ -46,7 +46,6 @@ sub ACTION_code {
     $self->notes(CFLAGS  => '-fPIC -I. -O2 -DCLD_WINDOWS'); # XXX fixme for windows
     $self->notes(LDFLAGS => '-L.');
 
-    $self->dispatch("create_objects");
     $self->dispatch("compile_xscode");
 
     $self->SUPER::ACTION_code;
@@ -80,7 +79,7 @@ sub ACTION_compile_xscode {
 
     if (!$self->up_to_date($cfile, $ofile)) {
         $cbuilder->compile( source               => $cfile,
-                            include_dirs         => [ catdir("cld-src") ],
+                            include_dirs         => [ catdir("/usr/local/include/cld") ],
                             'C++'                => 1,
                             extra_compiler_flags => $extra_compiler_flags,
                             object_file          => $ofile);
@@ -97,12 +96,11 @@ sub ACTION_compile_xscode {
         utime( (time) x 2, $bs_file );    # touch
     }
 
-    my $extra_linker_flags = "-lstdc++";
+    my $extra_linker_flags = "-lcld -lstdc++";
     $extra_linker_flags .= " -lgcc_s" if $^O eq 'netbsd';
 
     my $objects = [
-      $ofile,
-      @{ $self->rscan_dir('cld-src', qr/\.o$/) },
+      $ofile
     ];
 
     # .o => .(a|bundle)
