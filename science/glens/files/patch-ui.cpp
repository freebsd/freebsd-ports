--- src/ui.cpp.orig	Tue Aug 17 15:50:17 2004
+++ src/ui.cpp	Tue Aug 17 15:56:34 2004
@@ -320,7 +320,7 @@
 
   GLUI_RadioGroup *group = win_control->add_radiogroup_to_panel(panel, &d,1,ctrl_callback);
 
-  radio = new (GLUI_RadioButton*)[ndefl];
+  radio = new GLUI_RadioButton*[ndefl];
 
   for(i=0;i<ndefl;i++)
   {
@@ -406,12 +406,12 @@
 
   int i;
 
-  st = new (GLUI_StaticText*)[n];
-  cb = new (GLUI_Checkbox*)[n];
-  ex = new (GLUI_EditText*)[n];
-  ey = new (GLUI_EditText*)[n];
-  ez = new (GLUI_EditText*)[n];
-  em = new (GLUI_EditText*)[n];
+  st = new GLUI_StaticText*[n];
+  cb = new GLUI_Checkbox*[n];
+  ex = new GLUI_EditText*[n];
+  ey = new GLUI_EditText*[n];
+  ez = new GLUI_EditText*[n];
+  em = new GLUI_EditText*[n];
 
   char text[10];
 
