--- texi2html.pl.orig	Fri Feb  4 02:16:52 2005
+++ texi2html.pl	Sun Feb 13 00:18:09 2005
@@ -2445,20 +2445,24 @@
 
 if ($Texi2HTML::Config::SPLIT and ($Texi2HTML::Config::OUT ne ''))
 {
-    $Texi2HTML::Config::OUT =~ s|/*$||;
-    $docu_rdir = "$Texi2HTML::Config::OUT/"; 
-    unless (-d $Texi2HTML::Config::OUT)
-    {
-        if ( mkdir($Texi2HTML::Config::OUT, oct(755)))
-        {
-            print STDERR "# created directory $Texi2HTML::Config::OUT\n" if ($T2H_VERBOSE);
-        }
-        else
-        {
-            die "$ERROR can't create directory $Texi2HTML::Config::OUT\n";
-        }
-    }
-    print STDERR "# putting result files into directory $docu_rdir\n" if ($T2H_VERBOSE);
+#    $Texi2HTML::Config::OUT =~ s|/*$||;
+#    $docu_rdir = "$Texi2HTML::Config::OUT/"; 
+#    unless (-d $Texi2HTML::Config::OUT)
+#    {
+#        if ( mkdir($Texi2HTML::Config::OUT, oct(755)))
+#        {
+#            print STDERR "# created directory $Texi2HTML::Config::OUT\n" if ($T2H_VERBOSE);
+#        }
+#        else
+#        {
+#            die "$ERROR can't create directory $Texi2HTML::Config::OUT\n";
+#        }
+#    }
+#    print STDERR "# putting result files into directory $docu_rdir\n" if ($T2H_VERBOSE);
+    # FIXME: handle the case when ::OUT includes a basedir
+    $Texi2HTML::Config::PREFIX = $Texi2HTML::Config::OUT;
+    $docu_rdir = '';
+    $Texi2HTML::Config::OUT = '';
 }
 elsif (! $Texi2HTML::Config::SPLIT and ($Texi2HTML::Config::OUT ne ''))
 {
