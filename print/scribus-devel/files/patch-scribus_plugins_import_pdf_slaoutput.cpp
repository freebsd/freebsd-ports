Obtained from:
	https://github.com/archlinux/svntogit-community/blob/packages/scribus/trunk/scribus-1.5.8-poppler-22.09.0.patch

--- scribus/plugins/import/pdf/slaoutput.cpp.orig	2022-09-06 14:31:26 UTC
+++ scribus/plugins/import/pdf/slaoutput.cpp
@@ -3681,9 +3681,16 @@ void SlaOutputDev::getPenState(GfxState *state)
 			break;
 	}
 	double lw = state->getLineWidth();
-	double *dashPattern;
 	int dashLength;
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 9, 0)
+	const double *dashPattern;
+	const std::vector<double> &dash = state->getLineDash(&DashOffset);
+	dashPattern = dash.data();
+	dashLength = dash.size();
+#else
+	double *dashPattern;
 	state->getLineDash(&dashPattern, &dashLength, &DashOffset);
+#endif
 	QVector<double> pattern(dashLength);
 	for (int i = 0; i < dashLength; ++i)
 	{
