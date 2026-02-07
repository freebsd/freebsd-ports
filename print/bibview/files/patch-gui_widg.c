--- gui_widg.c.orig	Thu Nov 25 14:11:15 1993
+++ gui_widg.c	Thu Sep 11 13:08:30 1997
@@ -330,12 +330,12 @@
 	            XtNfromHoriz, warnIcon, NULL);
    sprintf(textLabel, "msgText%d", abs((int)errcode));
    if (errcode >= 200){
-   #ifdef GERMAN
+#ifdef GERMAN
       sprintf(warnLabel, "Karte unvollstaendig: kein %s", 
 			 glbFldToName(errcode-200));
-   #else
+#else
       sprintf(warnLabel, "Card incomplete: no %s", glbFldToName(errcode-200));
-   #endif
+#endif
       warnText     = XtVaCreateManagedWidget(textLabel,
   	               labelWidgetClass, warnForm, 
 		       XtNjustify, XtJustifyLeft,
