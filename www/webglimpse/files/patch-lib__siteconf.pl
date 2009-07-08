--- ./lib/siteconf.pl.orig	1998-07-22 17:44:21.000000000 -0400
+++ ./lib/siteconf.pl	2009-07-07 22:30:26.537073803 -0400
@@ -9,6 +9,7 @@
 
 local($DirectoryIndex, $UserDir, $DocumentRoot, $Port, $Server, $ServerAddress);
 local(@AliasList,@ScriptAliasList,@ServerCache);
+local($FCacheFile);
 
 $DirectoryIndex="";
 $UserDir="";
@@ -24,21 +25,6 @@
 
 $NUM_IP_ADDR_RE = '(\d+)\.(\d+)\.(\d+)\.(\d+)';
 
-$FCacheFile = "$WEBGLIMPSE_HOME/.sitecache";
-
-# If can't write to preferred cache file, use alternate
-if (!open(F,">$FCacheFile")) {
-	$FCacheFile = "/tmp/.sitecache";
-	if (!open(F,">$FCacheFile")) {
-		print "Error, cannot find a usable cache file!\n";
-		$FCacheFile = '';
-	} else {
-		close(F);
-	}
-} else {
-	close(F);
-}
-
 ########################################################################
 # Read [vhost].wgsiteconf file settings
 sub ReadConf	{
@@ -327,10 +313,9 @@
 	return "";
 }
 
-# NO GUARANTEE THAT THE USER RUNNING confarc CAN WRITE TO $WEBGLIMPSE_HOME!!!
-# Changed fixed filename to $FCacheFile, tested at beginning of package. --GB 7/6/98
 sub SaveCache	{
-	open (FCACHE, ">$FCacheFile");
+	open (FCACHE, ">$FCacheFile") ||
+		die "Error, can't write to $FCacheFile: ";
 	foreach $host (keys %ServerCache)	{
 		my($a, $b, $c, $d) = unpack('C4', $ServerCache{$host});
 		print FCACHE "$host $a $b $c $d\n";
@@ -340,7 +325,10 @@
 }
 
 sub LoadCache	{
-	open (FCACHE, $FCacheFile);
+	$FCacheFile = shift;
+	return if (! -e $FCacheFile);
+	open (FCACHE, $FCacheFile) ||
+		die "Error, can't read from $FCacheFile: ";
 	while (<FCACHE>)	{
 		my($host, $a, $b, $c, $d) = split(' ');
 		$ServerCache{$host} = pack('C4', $a, $b, $c, $d);
