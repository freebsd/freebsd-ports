--- bsmonitor/Statusmon/DisplayCFG.pm.orig	Sat Feb 28 16:46:51 2004
+++ bsmonitor/Statusmon/DisplayCFG.pm	Sat Feb 28 16:47:15 2004
@@ -358,7 +358,7 @@
 			"name" => $table
 			} );
 		    $tab{"group"} = $table;
-		    foreach my $arg qw( refto itemref sort select select_names items ) {
+		    foreach my $arg (qw( refto itemref sort select select_names items )) {
 		        $tab{$arg} = $args{$arg} if( $args{$arg} );
 		    }
 		    $tab{"type"} = "table";
