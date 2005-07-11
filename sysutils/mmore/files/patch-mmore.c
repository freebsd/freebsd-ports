--- mmore.c.orig	Mon Jul 11 12:03:49 2005
+++ mmore.c	Mon Jul 11 20:33:52 2005
@@ -51,6 +51,7 @@
 	XtAppContext xtAppContext;
 	Arg args[5]; Cardinal n;
 	XmString szGeneric;
+	XtTranslations transtable;
 
 	wndMMore = XtVaAppInitialize(&xtAppContext,
 				   "MMore",
@@ -68,7 +69,7 @@
               (XtEventHandler) _XEditResCheckMessages, NULL);
 
 	/* Create the universal Quit key binding */
-	XtTranslations transtable = XtParseTranslationTable(translations);
+	transtable = XtParseTranslationTable(translations);
 
 	n = 0;
 	XtSetArg(args[n], XmNmarginHeight, 7); n++;
