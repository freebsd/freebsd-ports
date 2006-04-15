--- configure.pl.orig	Mon Jan 16 12:13:55 2006
+++ configure.pl	Sat Apr 15 15:48:03 2006
@@ -74,7 +74,6 @@
    'deprecated.txt' => $DOC_DIR,
    'license.txt' => $DOC_DIR,
    'log.txt' => $DOC_DIR,
-   'rngs.txt' => $DOC_DIR,
    'thanks.txt' => $DOC_DIR,
    'todo.txt' => $DOC_DIR
    );
@@ -2040,7 +2039,11 @@
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
