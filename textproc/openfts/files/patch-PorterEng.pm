--- OpenFTS/Dict/PorterEng.pm.orig	Sat Apr  6 00:37:18 2002
+++ OpenFTS/Dict/PorterEng.pm	Tue Aug 19 20:54:05 2003
@@ -186,7 +186,7 @@
     my $constname;
     ($constname = $AUTOLOAD) =~ s/.*:://;
     croak "& not defined" if $constname eq 'constant';
-    my $val = constant($constname, @_ ? $_[0] : 0);
+    my $val = constant($constname, (@_ and $_[0] =~ /^\d+$/) ? $_[0] : 0);
     if ($! != 0) {
         if ($! =~ /Invalid/) {
             $AutoLoader::AUTOLOAD = $AUTOLOAD;
