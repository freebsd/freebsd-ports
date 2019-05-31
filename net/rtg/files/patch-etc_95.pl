--- etc/95.pl.orig	2018-04-02 20:14:41 UTC
+++ etc/95.pl
@@ -31,7 +31,7 @@ $pass="rtgdefault";
 $onedaysec=60*60*24;
 
 # Default locations to find RTG configuration file
-@configs = ("rtg.conf", "/usr/local/rtg/etc/rtg.conf", "/etc/rtg.conf");
+@configs = ("rtg.conf", "%%PREFIX%%/etc/rtg/rtg.conf", "/usr/local/rtg/etc/rtg.conf", "/etc/rtg.conf");
 foreach $conf (@configs) {
   if (open CONF, "<$conf") {
     print "Reading [$conf].\n" if $DEBUG;
@@ -207,13 +207,13 @@ print "Period: [", format_dt($startdate)
 write;
 ($name,$router, $ratein, $rateout, $maxratein, $maxrateout, $nfratein, $nfrateout) = ("Connection", "", "Mbps", "Mbps", "Mbps", "Mbps", "Mbps", "Mbps");
 write;
-print "--------------------------------------------------------------------------------\n";
+print "----------------------------------------------------------------------------------------------------\n";
 
 $dbh= DBI->connect("DBI:mysql:$db:host=$host", $user, $pass);
 $dbh2= DBI->connect("DBI:mysql:$db:host=$host", $user, $pass);
-$range="dtime>$startdate and dtime<=$enddate";
+$range="`dtime`>$startdate AND `dtime`<=$enddate";
 
-$statement="SELECT id FROM interface WHERE description LIKE \"%$cust%\"";
+$statement="SELECT `id` FROM `interface` WHERE `description` LIKE \"%$cust%\"";
 $sth = $dbh->prepare($statement)
   or die "Can't prepare $statement: $dbh->errstr\n";
 $rv = $sth->execute
@@ -223,19 +223,19 @@ while (@row = $sth->fetchrow_array ()) {
 }
 
 foreach $interface (@interfaces) {
-  $statement="SELECT rid, name, speed FROM interface WHERE id=$interface";
+  $statement="SELECT `rid`, `name`, `speed` FROM `interface` WHERE `id`=$interface";
   &run_query($statement);
   ($rid, $name, $speed) = @row;
 
-  $statement="SELECT rid, name FROM router WHERE rid=$rid";
+  $statement="SELECT `rid`, `name` FROM `router` WHERE `rid`=$rid";
   &run_query($statement);
   ($rid, $router) = @row;
 
-  $statement="SELECT counter, UNIX_TIMESTAMP(dtime), dtime FROM ifInOctets_".$rid." WHERE $range AND id=$interface ORDER BY dtime"; 
+  $statement="SELECT `counter`, UNIX_TIMESTAMP(`dtime`), `dtime` FROM `ifInOctets_".$rid."` WHERE $range AND `id`=$interface ORDER BY `dtime`"; 
   ($intbytes_in, $maxin, $avgin, $nfin) = &interface_stats($statement);
   $bytesin = int($intbytes_in/1000000 + .5);
 
-  $statement="SELECT counter, UNIX_TIMESTAMP(dtime), dtime FROM ifOutOctets_".$rid." WHERE $range AND id=$interface ORDER BY dtime"; 
+  $statement="SELECT `counter`, UNIX_TIMESTAMP(`dtime`), `dtime` FROM `ifOutOctets_".$rid."` WHERE $range AND `id`=$interface ORDER BY `dtime`"; 
   ($intbytes_out, $maxout, $avgout, $nfout) = &interface_stats($statement);
   $bytesout = int($intbytes_out/1000000 + .5);
 
@@ -279,6 +279,6 @@ $rc = $dbh->disconnect;
 exit;
 
 format STDOUT = 
-@<<<<<<<<<<< @<<<<<<<<<<< @>>>>>>>  @>>>>>>>  @>>>>>>  @>>>>>>  @>>>>>>  @>>>>>>
+@<<<<<<<<<<<<<<<<<<<<< @<<<<<<<<<<<<<<<<<<<<< @>>>>>>>  @>>>>>>>  @>>>>>>  @>>>>>>  @>>>>>>  @>>>>>>
 $name,$router, $ratein, $rateout, $maxratein, $maxrateout, $nfratein, $nfrateout  
 .
