--- Bulkmail.pm.orig	Fri Sep  7 12:28:16 2001
+++ Bulkmail.pm	Wed Nov 28 07:27:50 2001
@@ -704,16 +704,31 @@
 
 	my $self = shift or undef;
 	
-	my ($min, $hour, $isdst) = (localtime(time))[1,2,-1];
-	my ($gmin, $ghour, $gsdst) = (gmtime(time))[1,2, -1];
+	my $now = time;
+	my ($min, $hour, $isdst) = (localtime($now))[1,2,-1];
+	my ($gmin, $ghour, $gsdst) = (gmtime($now))[1,2, -1];
 	
-	my $diffhour = $hour - $ghour;
-	$diffhour = 12 - $diffhour if $diffhour > 12;
-	$diffhour = 12 + $diffhour if $diffhour < -12;
+	my $diffmin = ($hour - $ghour) * 60 + ($min - $gmin);
+	my $diffhour = int($diffmin / 60);
+	$diffmin -= $diffhour * 60;
+	if ($diffhour > 12) {
+		$diffhour -= 24;
+		if ($diffmin) {
+			$diffhour += 1;
+			$diffmin -= 60;
+		}
+	} elsif ($diffhour < -12) {
+		$diffhour += 24;
+		if ($diffmin) {
+			$diffhour -= 1;
+			$diffmin += 60;
+		}
+	}
+	$diffmin = abs($diffmin);
 	
-	($diffhour = sprintf("%03d", $hour - $ghour)) =~ s/^0/\+/;
+	($diffhour = sprintf("%03d%02d", $diffhour, $diffmin)) =~ s/^0/\+/;
 
-	return $diffhour . sprintf("%02d", $min - $gmin);
+	return $diffhour;
 
 };
