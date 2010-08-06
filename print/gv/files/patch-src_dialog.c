--- src/dialog.c.orig	2010-08-05 22:59:56.000000000 -0400
+++ src/dialog.c	2010-08-05 23:02:34.000000000 -0400
@@ -292,9 +292,9 @@
     if (!s) {INFMESSAGE(no text) ENDMESSAGE(DialogPopupSetText) return;}
     if (!dialogPopupCreated) makeDialogPopup();
     response = XtNameToWidget(DIALOG_POPUP, "*dialog_text");
+    						n=0;
 #ifdef HAVE_XAW3D_INTERNATIONAL
     vw = (VlistWidget)response;
-    						n=0;
     if( vw->simple.international == True ) {
       XtSetArg(args[n], XtNfontSet, &fontset);	n++;
     } else {
