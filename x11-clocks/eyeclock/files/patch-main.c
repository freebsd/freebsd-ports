--- main.c.orig	1999-12-25 09:18:56 UTC
+++ main.c
@@ -76,7 +76,7 @@
 /*===========================================================================*/
 
 static Widget toplevel = 0;
-static Widget clock = 0;
+static Widget myclock = 0;
 
 /*===========================================================================*/
 /* Number ���������åȤΥ��������åȤ��Ȥ�̾��                               */
@@ -616,9 +616,9 @@ static void die(Widget w)
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
@@ -650,8 +650,8 @@ static void restore(Widget w, XEvent * e
   unsigned int width;
   unsigned int height;
 
-  width  = ClockGetFaceWidth(clock);
-  height = ClockGetFaceHeight(clock);
+  width  = ClockGetFaceWidth(myclock);
+  height = ClockGetFaceHeight(myclock);
 
   if (width && height)
     XtVaSetValues(toplevel, XtNwidth, width, XtNheight, height, NULL);
@@ -730,23 +730,23 @@ int main(int argc, char * argv[])
   }
 
   /* Clock ���������åȤκ��� */
-  clock = XtCreateManagedWidget("clock", clockWidgetClass, toplevel, NULL, 0);
+  myclock = XtCreateManagedWidget("clock", clockWidgetClass, toplevel, NULL, 0);
 
   /* Hand ���������åȤκ��� */
   for (i = 0; hands_default_values[i].name; i++)
     XtVaCreateManagedWidget(hands_default_values[i].name,
-			    handWidgetClass, clock,
+			    handWidgetClass, myclock,
 			    XtNtype, hands_default_values[i].type, NULL);
 
   /* Number ���������åȤκ��� */
   for (i = 0; numbers_default_values[i].name; i++)
     XtVaCreateManagedWidget(numbers_default_values[i].name,
-			    numberWidgetClass, clock,
+			    numberWidgetClass, myclock,
 			    XtNnumber, numbers_default_values[i].number, NULL);
 
   /* Eye ���������åȤκ��� */
   for (i = 0; eyes_name[i]; i++)
-    XtCreateManagedWidget(eyes_name[i], eyeWidgetClass, clock, NULL, 0);
+    XtCreateManagedWidget(eyes_name[i], eyeWidgetClass, myclock, NULL, 0);
 
   /* �ݥ��󥿤Υե���������ͭ���ˤ��� */
   XtVaSetValues(toplevel, XtNinput, True, NULL);
@@ -788,7 +788,7 @@ int main(int argc, char * argv[])
   XSetWMProtocols(display, XtWindow(toplevel), &wm_delete_window, 1);
 
   /* ���פ򥹥����Ȥ����� */
-  ClockStart(app_context, clock);
+  ClockStart(app_context, myclock);
 
   /* Ctrl-c �Υȥ�å� */
   signal(SIGINT, interrupt_handler);
