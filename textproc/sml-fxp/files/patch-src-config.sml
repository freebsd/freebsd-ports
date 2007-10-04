--- src/config.sml.orig	Fri Sep  7 21:35:49 2007
+++ src/config.sml	Fri Sep  7 21:36:17 2007
@@ -15,5 +15,5 @@
       (* val retrieveCommand = "got_it -o %2 %1"                             *)
       (* val retrieveCommand = "urlget -s -o %2 %1"                          *)
       (*---------------------------------------------------------------------*)
-      val retrieveCommand = "wget -qO %2 %1"                            
+      val retrieveCommand = "fetch -qo %2 %1"                            
    end
