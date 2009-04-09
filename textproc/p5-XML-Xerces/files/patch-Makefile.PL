--- Makefile.PL.orig	2006-03-10 06:50:23.000000000 -0500
+++ Makefile.PL	2009-03-17 14:46:12.000000000 -0500
@@ -290,16 +290,16 @@
     my $CC_DEF;
     if ($^O eq 'linux') {
       $OS_DEF = '-DXML_LINUX';
-    } elsif($^O eq 'darwin') {
-      $OS_DEF = '-DXML_MACOSX';
+    } elsif($^O eq 'freebsd') {
+      $OS_DEF = '-DXML_FREEBSD';
     } else {
       die 'unsupported operating system';
     }
-    if ($CXX =~ /g\+\+/) {
+    #if ($CXX =~ /g\+\+/) {
       $CC_DEF = '-DXML_GCC';
-    } else {
-      die 'unsupported compiler';
-    }
+      #} else {
+      #die 'unsupported compiler';
+      #}
     my $SWIG_ARGS = qq[-Wall $OS_DEF $CC_DEF -DXERCES_OLD -DXERCES_VERSION="$XERCES_PERL_VERSION" \$(INC) -perl5 -c++ -shadow];
 
     my $MAKE = '	\$(MAKE) -C Handler static';
