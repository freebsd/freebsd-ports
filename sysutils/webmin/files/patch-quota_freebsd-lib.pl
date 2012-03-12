
$FreeBSD$

--- quota/freebsd-lib.pl.orig
+++ quota/freebsd-lib.pl
@@ -152,7 +152,9 @@
 	if (/^(\S+)$/) {
 		# Bogus wrapped line
 		$filesys{$n,'filesys'} = $1;
-		<QUOTA>=~/^.{15}(.{8}).(.{7})(.{8}).{8}(.{8}).(.{7})(.{8})/;
+		local $nl = <QUOTA>;
+		$nl =~ /^\s+(\S+)\s+(\S+)\s+(\S+)(.{8}\s+)(\S+)\s+(\S+)\s+(\S+)(.*)/ ||
+		  $nl =~ /^.{15}(.{8}).(.{7})(.{8}).{8}(.{8}).(.{7})(.{8})/;
 		$filesys{$n,'ublocks'} = int($1);
 		$filesys{$n,'sblocks'} = int($2);
 		$filesys{$n,'hblocks'} = int($3);
@@ -161,7 +163,8 @@
 		$filesys{$n,'hfiles'} = int($6);
 		$n++;
 		}
-	elsif (/^(.{15})(.{8}).(.{7})(.{8}).{8}(.{8}).(.{7})(.{8})/) {
+	elsif (/^\s*(\S+)\s+(\S+)\s+(\S+)\s+(\S+)(.{8}\s+)(\S+)\s+(\S+)\s+(\S+)(.*)/ ||
+	       /^(.{15})(.{8}).(.{7})(.{8}).{8}(.{8}).(.{7})(.{8})/) {
 		$filesys{$n,'ublocks'} = int($2);
 		$filesys{$n,'sblocks'} = int($3);
 		$filesys{$n,'hblocks'} = int($4);
@@ -240,11 +243,17 @@
 @line = split(/\n/, $_[0]);
 for($i=0; $i<@line; $i++) {
 	if ($line[$i] =~ /^(\S+): (blocks|kbytes) in use: (\d+), limits \(soft = (\d+), hard = (\d+)\)$/ && $1 eq $_[1]) {
-		# found lines to change
+		# found lines to change, old style
 		$rv .= "$1: $2 in use: $3, limits (soft = $_[2], hard = $_[3])\n";
 		$line[++$i] =~ /^\s*inodes in use: (\d+), limits \(soft = (\d+), hard = (\d+)\)$/;
 		$rv .= "\tinodes in use: $1, limits (soft = $_[4], hard = $_[5])\n";
 		}
+	elsif ($line[$i] =~ /^(\S+): in use: (\d+)k, limits \(soft = (\d+)k, hard = (\d+)k\)$/ && $1 eq $_[1]) {
+		# found lines to change, new style
+		$rv .= "$1: in use: ${2}k, limits (soft = $_[2]k, hard = $_[3]k)\n";
+		$line[++$i] =~ /^\s*inodes in use: (\d+), limits \(soft = (\d+), hard = (\d+)\)$/;
+		$rv .= "\tinodes in use: $1, limits (soft = $_[4], hard = $_[5])\n";
+		}
 	else { $rv .= "$line[$i]\n"; }
 	}
 return $rv;
