--- Makefile.PL.orig	2011-01-04 17:59:37.000000000 +0000
+++ Makefile.PL	2011-01-04 18:00:04.000000000 +0000
@@ -11,7 +11,8 @@
 install :: all pure_install doc_install
 	$(NOECHO) $(NOOP)';
 
-	$re .= "\n\t[ ! -f run-postinst ] || $^X postinst.pl\n";
+# Disable the post install script
+#	$re .= "\n\t[ ! -f run-postinst ] || $^X postinst.pl\n";
 
     return $re;
 }
