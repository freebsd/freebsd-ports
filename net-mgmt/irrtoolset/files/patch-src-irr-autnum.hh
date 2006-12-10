--- src/irr/autnum.hh.orig	2005-02-26 11:41:12.000000000 +0100
+++ src/irr/autnum.hh
@@ -334,7 +334,7 @@ protected:
 	  }
 	else
 	  {
-	  cerr << "Internal Error!" << endl;
+	  std::cerr << "Internal Error!" << std::endl;
 	  abort();
 	  }
     return false;
 
