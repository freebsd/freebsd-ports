--- sqwebmail/sv-make_timezonelist.pl.orig	Sat Oct 11 15:55:15 2003
+++ sqwebmail/sv-make_timezonelist.pl	Tue Mar 16 21:39:00 2004
@@ -50,8 +50,14 @@
   }
 }
 die "Could not find a zoneinfo directory\n" unless ($zoneinfo_dir);
-
-$iso3166tab = "$zoneinfo_dir/iso3166.tab";
+if ( $^O eq "freebsd" )
+{
+  $iso3166tab = "/usr/share/misc/iso3166";
+}
+else
+{
+  $iso3166tab = "$zoneinfo_dir/iso3166.tab";
+}
 $zonetab = "$zoneinfo_dir/zone.tab";
 $etc_dir = "$zoneinfo_dir/Etc";
 
@@ -59,6 +65,7 @@
 
 open(ISO3166, $iso3166tab) ||
   die "Could not open '$iso3166tab' for reading ($!)\n";
+
 @lines = <ISO3166>;
 close(ISO3166);
 
@@ -68,8 +75,15 @@
   next unless ($line =~ /\S/);
     
   chomp($line);
+if ( $^O eq "freebsd" )
+{
+  ($code, undef, undef, $country) = split(/\t/, $line, 4);
+}
+else
+{
   ($code, $country) = split(/\t/, $line, 2);
-    
+}    
+
   $countries{$code} = $country;
 }
 
