$FreeBSD$

--- monthly.pl.orig	Thu Jul 17 14:24:55 2003
+++ monthly.pl	Thu Jul 17 14:26:02 2003
@@ -66,11 +66,13 @@
 if ($mon == 0) { $mon = 11; $year -= 1; }
 else           { $mon -= 1; }
 
+$year += 1900;
+
 $LastMonth = $MoY[$mon];
 
 $ArcName  =~ s/%M/$LastMonth$year/;
 
-$ArcStats = '/dc/ud/www/documentroot/Admin/stats-19' . $year .
+$ArcStats = '/dc/ud/www/documentroot/Admin/stats-' . $year .
             '/' . $LastMonth . '.wwwstats.html';
 
 print "Figured out that last month was $LastMonth $year\n";
