--- scribus/plugins/import/pdf/slaoutput.cpp.orig	2020-01-18 17:22:17 UTC
+++ scribus/plugins/import/pdf/slaoutput.cpp
@@ -1224,16 +1224,7 @@ void SlaOutputDev::startDoc(PDFDoc *doc, XRef *xrefA, 
 	catalog = catA;
 	pdfDoc = doc;
 	updateGUICounter = 0;
-	m_fontEngine = new SplashFontEngine(
-#if HAVE_T1LIB_H
-	globalParams->getEnableT1lib(),
-#endif
-#if HAVE_FREETYPE_H
-	globalParams->getEnableFreeType(),
-	true,
-	true,
-#endif
-	true);
+	m_fontEngine = new SplashFontEngine(true, true, true, true);
 }
 
 void SlaOutputDev::startPage(int pageNum, GfxState *, XRef *)
@@ -2784,7 +2775,7 @@ void SlaOutputDev::drawMaskedImage(GfxState *state, Ob
 	delete[] mbuffer;
 }
 
-void SlaOutputDev::drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, GBool interpolate, int *maskColors, GBool inlineImg)
+void SlaOutputDev::drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, GBool interpolate, const int *maskColors, GBool inlineImg)
 {
 	ImageStream * imgStr = new ImageStream(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
 //	qDebug() << "Image Components" << colorMap->getNumPixelComps() << "Mask" << maskColors;
@@ -3365,7 +3356,7 @@ err1:
 		fontsrc->unref();
 }
 
-void SlaOutputDev::drawChar(GfxState *state, double x, double y, double dx, double dy, double originX, double originY, CharCode code, int nBytes, Unicode *u, int uLen)
+void SlaOutputDev::drawChar(GfxState *state, double x, double y, double dx, double dy, double originX, double originY, CharCode code, int nBytes, const Unicode *u, int uLen)
 {
 	double x1, y1, x2, y2;
 	int render;
@@ -3452,7 +3443,7 @@ void SlaOutputDev::drawChar(GfxState *state, double x,
 	}
 }
 
-GBool SlaOutputDev::beginType3Char(GfxState *state, double x, double y, double dx, double dy, CharCode code, Unicode *u, int uLen)
+GBool SlaOutputDev::beginType3Char(GfxState *state, double x, double y, double dx, double dy, CharCode code, const Unicode *u, int uLen)
 {
 //	qDebug() << "beginType3Char";
 	GfxFont *gfxFont;
@@ -3705,7 +3696,7 @@ QString SlaOutputDev::getAnnotationColor(const AnnotCo
 	return fNam;
 }
 
-QString SlaOutputDev::convertPath(GfxPath *path)
+QString SlaOutputDev::convertPath(const GfxPath *path)
 {
 	if (! path)
 		return QString();
@@ -3715,7 +3706,7 @@ QString SlaOutputDev::convertPath(GfxPath *path)
 
 	for (int i = 0; i < path->getNumSubpaths(); ++i)
 	{
-		GfxSubpath * subpath = path->getSubpath(i);
+		const GfxSubpath * subpath = path->getSubpath(i);
 		if (subpath->getNumPoints() > 0)
 		{
 			output += QString("M %1 %2").arg(subpath->getX(0)).arg(subpath->getY(0));
