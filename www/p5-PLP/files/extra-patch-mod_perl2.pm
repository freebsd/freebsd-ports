--- PLP.pm.orig	Fri Oct 18 15:47:07 2002
+++ PLP.pm	Tue Jun  1 15:49:07 2004
@@ -131,7 +131,12 @@
 
 # This is the mod_perl handler.
 sub handler {
-    require Apache::Constants;
+    if($ENV{'mod_perl2_compat'} eq 'on') {
+	    use Apache::Const -compile => qw(OK);
+    }
+    else {
+	require Apache::Constants;
+    }
     clean();
     if (my $ret = mod_perl_init($_[0])) {
 	return $ret;
@@ -139,7 +144,12 @@
     #S start($_[0]);
     start();
     no strict 'subs';
-    return Apache::Constants::OK();
+    if($ENV{'mod_perl2_compat'} eq 'on') {
+	    return Apache::Const::OK;
+    }
+    else {
+	return Apache::Constants::OK();
+    }
 }
 
 # mod_perl initializer: returns 0 on success, Apache error code on failure
@@ -151,10 +161,20 @@
     $ENV{PLP_FILENAME} = my $filename = $r->filename;
     
     unless (-f $filename) {
-	return Apache::Constants::NOT_FOUND();
+	if($ENV{'mod_perl2_compat'} eq 'on') {
+		return Apache::Const::NOT_FOUND();
+	}
+	else {
+		return Apache::Constants::NOT_FOUND();
+	}
     }
     unless (-r _) {
-	return Apache::Constants::FORBIDDEN();
+	if($ENV{'mod_perl2_compat'} eq 'on') {
+		return Apache::Const::FORBIDDEN();
+	}
+	else {
+		return Apache::Constants::FORBIDDEN();
+	}
     }
     
     $ENV{PLP_NAME} = $r->uri;
