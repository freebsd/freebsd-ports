--- Build.PL.orig	2010-01-14 01:33:31.000000000 +0800
+++ Build.PL	2013-11-07 22:04:58.000000000 +0800
@@ -107,27 +107,6 @@ if (! $template_path) {
 
 $build->notes( install_web_directory => $template_path );
 
-if ( not -d $template_path ) {
-    my $make_path = $ENV{'GANTRY_TEMPLATE_PATH'} || $build->y_n(
-        "$template_path does not exist, should I make it?",
-        'y'
-    );
-
-    if ( $make_path ) {
-        eval {  
-            File::Path::mkpath( $template_path );
-        };
-        if ( $@ ) {
-            $@ =~ s/ at .+?$//;
-            print "Error: unable to create directory $template_path @_\n";
-            $build->notes( install_web_directory => '__skip__' );
-        }
-    }
-    else {
-        $build->notes( install_web_directory => '__skip__' );
-    }
-}
-
 $build->create_build_script;
 
 sub _custom_code {
@@ -151,14 +130,13 @@ sub _custom_code {
 
         my $install_base = $self->install_destination('lib') 
             || $p->{install_sets}{site}{lib};
-        
-        my $initf = "$install_base/$p->{dist_name}/Init.pm";
+        my $destdir = $self->destdir;
+        my $initf = "$destdir$install_base/$p->{dist_name}/Init.pm";
                 
         $self->SUPER::ACTION_install();
 
         my $tmpl_dir = $self->notes( 'install_web_directory' );
             
-        if( $tmpl_dir && $tmpl_dir ne '__skip__' ) {
 
             # write Init.pm file with install options
 
@@ -207,14 +185,15 @@ EO_INIT
                 chmod $orig_mode, $dst or die "Can't chmod $orig_mode $dst: $!";
             } 
 
+            my $www_dir = $destdir . $tmpl_dir;
             eval {  
                 # this should have been done during perl Build.PL
-                if ( not -d $tmpl_dir ) {
-                    File::Path::mkpath( $tmpl_dir );
+                if ( not -d $www_dir ) {
+                    File::Path::mkpath( $www_dir );
                 }
             };
             if ( $@ ) {
-                print "Error: unable to create directory $tmpl_dir\n";
+                print "Error: unable to create directory $www_dir\n";
                 $@ =~ s/ at .+?$//;
                 die( "$@\n" );
             }
@@ -227,19 +206,15 @@ EO_INIT
                 require File::Copy::Recursive;
                 import File::Copy::Recursive 'dircopy';
 
-                $num = dircopy($blib_tmpl_dir, $tmpl_dir) || 0;
+                $num = dircopy($blib_tmpl_dir, $www_dir) || 0;
             };
             if ( $@ ) {
                 print "\nError coping templates:\n";
                 print $@ . "\n";
             }
             else {
-                print "\n$num Gantry templates copied to $tmpl_dir\n";
+                print "\n$num Gantry templates copied to $www_dir\n";
             }
-        }
-        else {
-            print "SKIPPING WEB CONTENT INSTALL\n";
-        }
         
         print "\n";
 
