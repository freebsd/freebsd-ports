--- gui_card.c.orig	Mon May  8 18:24:55 1995
+++ gui_card.c	Thu Sep 11 13:08:31 1997
@@ -370,15 +370,15 @@
 CardWidgetsPtr cwp;
 Dimension height;
   
-   #ifdef ACTION_PROBLEM
+#ifdef ACTION_PROBLEM
    if (first_in){
-   #endif
+#endif
    XtAppAddActions(XtWidgetToApplicationContext(topLevel), actions,
 		  XtNumber(actions));
-   #ifdef ACTION_PROBLEM
+#ifdef ACTION_PROBLEM
    first_in = 0;
    }
-   #endif
+#endif
    reqback = options.reqColor;
    auth_ed_back = options.authedColor;
 
