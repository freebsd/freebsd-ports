--- main.c.orig	Sun Dec 26 16:34:55 1999
+++ main.c	Sun Dec 26 16:37:01 1999
@@ -76,7 +76,7 @@
 /*===========================================================================*/
 
 static Widget toplevel = 0;
-static Widget clock = 0;
+static Widget myclock = 0;
 
 /*===========================================================================*/
 /* Number ヴィジェットのヴィジェットごとの名前                               */
@@ -616,9 +616,9 @@
   Display * display;
   int i;
 
-  if (clock)
-    if (XtIsRealized(clock))
-      ClockStop(clock);
+  if (myclock)
+    if (XtIsRealized(myclock))
+      ClockStop(myclock);
 
   if (toplevel)
     if (XtIsRealized(toplevel)) {
@@ -650,8 +650,8 @@
   unsigned int width;
   unsigned int height;
 
-  width  = ClockGetFaceWidth(clock);
-  height = ClockGetFaceHeight(clock);
+  width  = ClockGetFaceWidth(myclock);
+  height = ClockGetFaceHeight(myclock);
 
   if (width && height)
     XtVaSetValues(toplevel, XtNwidth, width, XtNheight, height, NULL);
@@ -730,23 +730,23 @@
   }
 
   /* Clock ヴィジェットの作成 */
-  clock = XtCreateManagedWidget("clock", clockWidgetClass, toplevel, NULL, 0);
+  myclock = XtCreateManagedWidget("clock", clockWidgetClass, toplevel, NULL, 0);
 
   /* Hand ヴィジェットの作成 */
   for (i = 0; hands_default_values[i].name; i++)
     XtVaCreateManagedWidget(hands_default_values[i].name,
-			    handWidgetClass, clock,
+			    handWidgetClass, myclock,
 			    XtNtype, hands_default_values[i].type, NULL);
 
   /* Number ヴィジェットの作成 */
   for (i = 0; numbers_default_values[i].name; i++)
     XtVaCreateManagedWidget(numbers_default_values[i].name,
-			    numberWidgetClass, clock,
+			    numberWidgetClass, myclock,
 			    XtNnumber, numbers_default_values[i].number, NULL);
 
   /* Eye ヴィジェットの作成 */
   for (i = 0; eyes_name[i]; i++)
-    XtCreateManagedWidget(eyes_name[i], eyeWidgetClass, clock, NULL, 0);
+    XtCreateManagedWidget(eyes_name[i], eyeWidgetClass, myclock, NULL, 0);
 
   /* ポインタのフォーカスを有効にする */
   XtVaSetValues(toplevel, XtNinput, True, NULL);
@@ -788,7 +788,7 @@
   XSetWMProtocols(display, XtWindow(toplevel), &wm_delete_window, 1);
 
   /* 時計をスタートさせる */
-  ClockStart(app_context, clock);
+  ClockStart(app_context, myclock);
 
   /* Ctrl-c のトラップ */
   signal(SIGINT, interrupt_handler);
