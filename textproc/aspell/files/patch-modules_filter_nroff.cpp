add the following as a new patch file in textproc/aspell/files:

--- modules/filter/nroff.cpp.orig	Fri Mar 31 09:52:23 2006
+++ modules/filter/nroff.cpp	Fri Mar 31 09:52:42 2006
@@ -73,7 +73,7 @@
       return false;
     }
     
-    bool NroffFilter::process_char (FilterChar::Chr c);
+    bool process_char (FilterChar::Chr c);
       
   public:
 

