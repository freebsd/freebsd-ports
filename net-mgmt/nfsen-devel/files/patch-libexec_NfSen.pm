
$FreeBSD$

--- libexec/NfSen.pm.orig
+++ libexec/NfSen.pm
@@ -705,6 +705,25 @@
 
 } # End of LoadHints
 
+sub LoadHints_startup {
+
+	eval {
+		local $SIG{'__DIE__'} = 'DEFAULT';
+		$hints = lock_retrieve "$NfConf::PROFILESTATDIR/hints";
+	};
+
+	if ( my $err = $@ ) {
+		warn "Error reading hints: $err\n";
+		warn "Initialize hints to defaults.\n";
+		$$hints{'version'} 	 	= -1;	# unknown
+		$$hints{'installed'} 	= 0;
+		$$hints{'subdirlayout'} = $NfConf::SUBDIRLAYOUT;
+	}
+
+	return \$hints;
+
+} # End of LoadHints_startup
+
 sub StoreHints {
 
 	eval {
@@ -717,6 +736,20 @@
 		return $err;
 	}
 
-} # End of StoreAlertStatus
+} # End of StoreHints
+
+sub StoreHints_startup {
+
+	eval {
+		local $SIG{'__DIE__'} = 'DEFAULT';
+		lock_store $hints, "$NfConf::PROFILESTATDIR/hints";
+	};
+
+	if ( my $err = $@ ) {
+		warn "Error store hints: $err\n";
+		return $err;
+	}
+
+} # End of StoreHints_startup
 
 1;
