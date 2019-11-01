--- scribus/plugins/import/pdf/slaoutput.cpp.orig	2019-10-27 16:14:24 UTC
+++ scribus/plugins/import/pdf/slaoutput.cpp
@@ -2784,7 +2784,7 @@ void SlaOutputDev::drawMaskedImage(GfxState *state, Ob
 	delete[] mbuffer;
 }
 
-void SlaOutputDev::drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, GBool interpolate, int *maskColors, GBool inlineImg)
+void SlaOutputDev::drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, GBool interpolate, const int *maskColors, GBool inlineImg)
 {
 	ImageStream * imgStr = new ImageStream(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
 //	qDebug() << "Image Components" << colorMap->getNumPixelComps() << "Mask" << maskColors;
@@ -3365,7 +3365,7 @@ err1:
 		fontsrc->unref();
 }
 
-void SlaOutputDev::drawChar(GfxState *state, double x, double y, double dx, double dy, double originX, double originY, CharCode code, int nBytes, Unicode *u, int uLen)
+void SlaOutputDev::drawChar(GfxState *state, double x, double y, double dx, double dy, double originX, double originY, CharCode code, int nBytes, const Unicode *u, int uLen)
 {
 	double x1, y1, x2, y2;
 	int render;
@@ -3452,7 +3452,7 @@ void SlaOutputDev::drawChar(GfxState *state, double x,
 	}
 }
 
-GBool SlaOutputDev::beginType3Char(GfxState *state, double x, double y, double dx, double dy, CharCode code, Unicode *u, int uLen)
+GBool SlaOutputDev::beginType3Char(GfxState *state, double x, double y, double dx, double dy, CharCode code, const Unicode *u, int uLen)
 {
 //	qDebug() << "beginType3Char";
 	GfxFont *gfxFont;
