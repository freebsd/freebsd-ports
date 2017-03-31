--- lib/App/Greple/daemon3.pm.orig	2017-03-30 09:05:08 UTC
+++ lib/App/Greple/daemon3.pm
@@ -241,7 +241,7 @@ END { }
 	}
     }
     sub tags {
-	keys shift;
+	keys %{$_[0]};
     }
 }
 
