--- src/io-motif.c.orig	Wed Jan 19 18:23:57 2005
+++ src/io-motif.c	Wed Jan 19 18:26:41 2005
@@ -1495,7 +1495,7 @@
 #endif
 		XmTextFieldSetEditable(tw, True);
 		break;
-	default:
+	default: {}
 #if 0
 		fprintf(stderr, "Huh ? TickTypeCB(axis %d type %d) -> sensitive \n", axis, val);
 #endif
@@ -6058,7 +6058,11 @@
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
@@ -6142,6 +6146,7 @@
 		return;
 	}
 
+#if XbaeVersion > 4007
 	if (XbaeMatrixGetCellWidget(mat, r-1, c-1) == NULL) {
 		button = XtVaCreateManagedWidget(lbl, xmPushButtonWidgetClass, mat, NULL);
 		XbaeMatrixSetCellWidget(mat, r-1, c-1, button);
@@ -6151,4 +6156,5 @@
 
 		fprintf(stderr, "MotifButton(%d,%d,%s,%s)\n", r-1, c-1, lbl, command);
 	}
+#endif
 }
