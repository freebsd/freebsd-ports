--- configure.pl.orig	Sat Jun 26 14:32:52 2004
+++ configure.pl	Fri Jul 16 16:53:50 2004
@@ -2007,7 +2007,11 @@
    my $link_to = "-lm";
    foreach my $lib (@{ $lib_list })
    {
-       $link_to .= " -l" . $lib;
+       if ($lib =~ m/pthread/) {
+	    $link_to .= " -" . $lib;
+       } else {
+	    $link_to .= " -l" . $lib;
+       }
    }
 
    ##################################################
