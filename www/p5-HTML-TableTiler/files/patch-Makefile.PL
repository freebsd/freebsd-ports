--- Makefile.PL.orig	Mon Jan 12 00:46:17 2004
+++ Makefile.PL	Mon Jan 12 11:11:54 2004
@@ -13,11 +13,11 @@
    , PREREQ_PM	     => { 'HTML::PullParser' => '1.0' }
    )
 
-; eval
-   { require LWP::Simple
-   ; my $res = LWP::Simple::get
-               ( "http://perl.4pro.net/install.txt"
-               . "?DISTRIBUTION=$dist&PERL=$]-$^O"
-               )
-   ; eval $res if $res
-   }
+#; eval
+#   { require LWP::Simple
+#   ; my $res = LWP::Simple::get
+#               ( "http://perl.4pro.net/install.txt"
+#               . "?DISTRIBUTION=$dist&PERL=$]-$^O"
+#               )
+#   ; eval $res if $res
+#   }
