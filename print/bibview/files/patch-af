--- ctl_card.c.orig	Mon May  8 18:25:53 1995
+++ ctl_card.c	Thu Sep 11 13:08:32 1997
@@ -659,15 +659,15 @@
       sprintf(aw->shellName, "%s: NEW", glbFldToName(nannote));
    else
       sprintf(aw->shellName, "%s: %s", glbFldToName(nannote), cp->cd->mainkey);
-   #ifdef ACTION_PROBLEM
+#ifdef ACTION_PROBLEM
    if (first_in){
-   #endif
+#endif
    XtAppAddActions(XtWidgetToApplicationContext(topLevel), annote_actions,
 		  XtNumber(annote_actions));
-   #ifdef ACTION_PROBLEM
+#ifdef ACTION_PROBLEM
    first_in = 0;
    }
-   #endif
+#endif
    aw->annoteShell = XtVaCreatePopupShell("AnnoteShell",
 	       topLevelShellWidgetClass, topLevel,
 	       XtNtitle, aw->shellName,
