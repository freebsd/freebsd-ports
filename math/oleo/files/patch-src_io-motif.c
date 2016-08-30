--- src/io-motif.c.orig	2001-03-09 11:33:29 UTC
+++ src/io-motif.c
@@ -1495,7 +1495,7 @@ static void TickTypeCB(Widget w, XtPoint
 #endif
 		XmTextFieldSetEditable(tw, True);
 		break;
-	default:
+	default: {}
 #if 0
 		fprintf(stderr, "Huh ? TickTypeCB(axis %d type %d) -> sensitive \n", axis, val);
 #endif
@@ -6058,7 +6058,11 @@ void versionCB(Widget w, XtPointer clien
 #endif
 
 #ifdef	HAVE_LIBPLOT
+#if defined(PL_LIBPLOT_VER_STRING)
 	sprintf(xbae, "\n  GNU PlotUtils (libplot version %s)", PL_LIBPLOT_VER_STRING);
+#else
+	sprintf(xbae, "\n  GNU PlotUtils (libplot version %s)", LIBPLOT_VERSION);
+#endif
 	xms1 = xms;
 	xms2 = XmStringCreateLtoR(xbae, XmFONTLIST_DEFAULT_TAG);
 	xms = XmStringConcat(xms1, xms2);
@@ -6142,6 +6146,7 @@ MotifButton(int r, int c, char *lbl, cha
 		return;
 	}
 
+#if XbaeVersion > 4007
 	if (XbaeMatrixGetCellWidget(mat, r-1, c-1) == NULL) {
 		button = XtVaCreateManagedWidget(lbl, xmPushButtonWidgetClass, mat, NULL);
 		XbaeMatrixSetCellWidget(mat, r-1, c-1, button);
@@ -6151,4 +6156,5 @@ MotifButton(int r, int c, char *lbl, cha
 
 		fprintf(stderr, "MotifButton(%d,%d,%s,%s)\n", r-1, c-1, lbl, command);
 	}
+#endif
 }
