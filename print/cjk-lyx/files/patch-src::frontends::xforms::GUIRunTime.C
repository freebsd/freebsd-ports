diff -ur c/src/frontends/xforms/GUIRunTime.C src/frontends/xforms/GUIRunTime.C
--- c/src/frontends/xforms/GUIRunTime.C	Thu Jul 11 14:20:21 2002
+++ src/frontends/xforms/GUIRunTime.C	Thu Jul 11 14:23:55 2002
@@ -26,11 +26,11 @@
 
 // I keep these here so that it will be processed as early in
 // the compilation process as possible.
-#if !defined(FL_REVISION) || FL_REVISION < 88 || FL_VERSION != 0
-#error LyX will not compile with this version of XForms.\
-       Please get version 0.89.\
-       If you want to try to compile anyway, delete this test in src/frontends/xforms/GUIRunTime.C.
-#endif
+//#if !defined(FL_REVISION) || FL_REVISION < 88 || FL_VERSION != 0
+//#error LyX will not compile with this version of XForms.\
+//       Please get version 0.89.\
+//       If you want to try to compile anyway, delete this test in src/frontends/xforms/GUIRunTime.C.
+//#endif
 
 
 using std::endl;
