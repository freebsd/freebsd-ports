
------------------------ start of patch ------------------------
--- widgets.c.orig	Fri Apr 29 16:37:58 2005
+++ widgets.c	Fri Apr 29 16:39:09 2005
@@ -18,7 +18,7 @@
 #include "LoadFace.h"
 #include "ArrangeBox.h"
 #include "MachineInfo.h"
-#include <varargs.h>
+#include <stdarg.h>
 #include "version.h"
 #include <math.h>
 #include <X11/Xresource.h>
@@ -49,7 +49,7 @@
 
 static void exitDisplay(),popdown(),showHelp(),popdownHelp();
 
-Widget mkWidget();
+Widget mkWidget(char* name, ...);
 
 static XrmOptionDescRec optionTable[] = {
 {"-interval",	"*interval",		XrmoptionSepArg,(caddr_t)NULL},
@@ -571,11 +571,9 @@
  *                 resource-name, resource, ... , NULL);
  */
 Widget
-mkWidget(va_alist)
-va_dcl
+mkWidget(char* name, ...)
 {
 	va_list arg;
-	char *name;
 	WidgetClass class;
 	Widget parent;
 	String argname;
@@ -583,8 +581,7 @@
 	int n = 0;
 	Arg args[20];
 	
-	va_start(arg);
-	name   = va_arg(arg,char*);
+	va_start(arg, name);
 	class  = va_arg(arg,WidgetClass);
 	parent = va_arg(arg,Widget);
 
------------------------ end of patch ------------------------
