--- PLP.pm.orig	Wed Jun 22 04:02:50 2005
+++ PLP.pm	Wed Jun 22 04:02:52 2005
@@ -131,7 +131,13 @@
 
 # This is the mod_perl handler.
 sub handler {
-    require Apache::Constants;
+    if($ENV{'mod_perl2_compat'} eq 'on') {
+	    require Apache2::Const;
+	    import Apache2::Const -compile => qw(OK);
+    }
+    else {
+	require Apache::Constants;
+    }
     clean();
     if (my $ret = mod_perl_init($_[0])) {
 	return $ret;
@@ -139,7 +145,12 @@
     #S start($_[0]);
     start();
     no strict 'subs';
-    return Apache::Constants::OK();
+    if($ENV{'mod_perl2_compat'} eq 'on') {
+	    return Apache2::Const::OK;
+    }
+    else {
+	return Apache::Constants::OK();
+    }
 }
 
 # mod_perl initializer: returns 0 on success, Apache error code on failure
@@ -151,10 +162,20 @@
     $ENV{PLP_FILENAME} = my $filename = $r->filename;
     
     unless (-f $filename) {
-	return Apache::Constants::NOT_FOUND();
+	if($ENV{'mod_perl2_compat'} eq 'on') {
+		return Apache2::Const::NOT_FOUND;
+	}
+	else {
+		return Apache::Constants::NOT_FOUND();
+	}
     }
     unless (-r _) {
-	return Apache::Constants::FORBIDDEN();
+	if($ENV{'mod_perl2_compat'} eq 'on') {
+		return Apache2::Const::FORBIDDEN;
+	}
+	else {
+		return Apache::Constants::FORBIDDEN();
+	}
     }
     
     $ENV{PLP_NAME} = $r->uri;
