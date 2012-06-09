--- libexec/NfSenRC.pm	2010-09-09 07:56:05.000000000 +0200
+++ libexec/NfSenRC.pm.patched	2011-03-09 13:09:32.000000000 +0100
@@ -54,22 +54,21 @@
 		print "[no collector]";
 		return;
 	}
-
 	my @SourceList;
 	my $type = undef;
 	foreach my $source ( sort keys %NfConf::sources ) {
 		my $_port = $NfConf::sources{$source}{'port'};
 		if ( $_port == $port ) {
 			push @SourceList, $source;
-		}
-		my $_type = exists $NfConf::sources{$source}{'type'} ? $NfConf::sources{$source}{'type'}: 'netflow';
-		if ( defined $type ) {
-			if ( $type ne $_type ) {
-				print "Can not start different type '$type' and '$_type' on same port!\n";
-				return;
+			my $_type = exists $NfConf::sources{$source}{'type'} ? $NfConf::sources{$source}{'type'}: 'netflow';
+			if ( defined $type ) {
+				if ( $type ne $_type ) {
+					print "Can not start different type '$type' and '$_type' on same port!\n";
+					return;
+				}
+			} else {
+				$type = $_type;
 			}
-		} else {
-			$type = $_type;
 		}
 	}
