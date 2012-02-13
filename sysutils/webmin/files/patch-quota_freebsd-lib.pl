
$FreeBSD$

--- quota/freebsd-lib.pl.orig
+++ quota/freebsd-lib.pl
@@ -240,11 +240,17 @@
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
