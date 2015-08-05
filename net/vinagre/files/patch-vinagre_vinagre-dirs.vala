--- vinagre/vinagre-dirs.vala.orig	2015-01-06 15:14:33.089376522 +0100
+++ vinagre/vinagre-dirs.vala	2015-01-06 15:22:22.849343759 +0100
@@ -46,5 +46,6 @@
         // Filename could not be found!
         error ("Data file ‘%s’ could not be found in system data directories.",
             filename);
+	return "";
     }
 }
