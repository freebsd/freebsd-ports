--- ../inst/des_init.m.old	2026-11-26 19:34:21.781658000 -0600
+++ ../inst/des_init.m	2026-11-26 19:33:17.736954000 -0600
@@ -21,7 +21,7 @@
     return;
   endif
 
-  here = fileparts (which ('des_init'));
+  here = fileparts (which ('des_core.oct'));
   core = fullfile (here, 'des_core.oct');
   if (isempty (dir (core)))
     parent = fileparts (here);
