--- xpdf/XRef.cc.orig	Wed Jun 25 00:41:27 2003
+++ xpdf/XRef.cc	Fri Jan 28 14:25:54 2005
@@ -486,6 +486,9 @@
 	} else {
 	  keyLength = 5;
 	}
+	if (keyLength > 16) {
+	  keyLength = 16;
+	}
 	permFlags = permissions.getInt();
 	if (encVersion >= 1 && encVersion <= 2 &&
 	    encRevision >= 2 && encRevision <= 3) {
