--- scribus/plugins/import/pdf/slaoutput.cpp.orig	2020-03-15 14:15:45 UTC
+++ scribus/plugins/import/pdf/slaoutput.cpp
@@ -324,7 +324,7 @@ LinkAction* SlaOutputDev::SC_getAdditionalAction(const
 		{
 			Object actionObject = additionalActionsObject.dictLookup(key);
 			if (actionObject.isDict())
-				linkAction = LinkAction::parseAction(&actionObject, pdfDoc->getCatalog()->getBaseURI());
+				linkAction = LinkAction::parseAction(&actionObject, pdfDoc->getCatalog()->getBaseURI()).get();
 		}
 	}
 	return linkAction;
@@ -455,7 +455,7 @@ bool SlaOutputDev::handleLinkAnnot(Annot* annota, doub
 			POPPLER_CONST GooString *ndst = gto->getNamedDest();
 			if (ndst)
 			{
-				LinkDest *dstn = pdfDoc->findDest(ndst);
+				LinkDest *dstn = pdfDoc->findDest(ndst).get();
 				if (dstn)
 				{
 					if (dstn->getKind() == destXYZ)
@@ -499,7 +499,7 @@ bool SlaOutputDev::handleLinkAnnot(Annot* annota, doub
 			POPPLER_CONST GooString *ndst = gto->getNamedDest();
 			if (ndst)
 			{
-				LinkDest *dstn = pdfDoc->findDest(ndst);
+				LinkDest *dstn = pdfDoc->findDest(ndst).get();
 				if (dstn)
 				{
 					if (dstn->getKind() == destXYZ)
@@ -517,7 +517,7 @@ bool SlaOutputDev::handleLinkAnnot(Annot* annota, doub
 	{
 		LinkURI *gto = (LinkURI*)act;
 		validLink = true;
-		fileName = UnicodeParsedString(gto->getURI());
+		fileName = QString::fromStdString(gto->getURI());
 	}
 	if (validLink)
 	{
@@ -930,7 +930,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 			if (jsa->isOk())
 			{
 				ite->annotation().setActionType(1);
-				ite->annotation().setAction(UnicodeParsedString(jsa->getScript()));
+				ite->annotation().setAction(QString::fromStdString(jsa->getScript()));
 			}
 		}
 		else if (Lact->getKind() == actionGoTo)
@@ -967,7 +967,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 				POPPLER_CONST GooString *ndst = gto->getNamedDest();
 				if (ndst)
 				{
-					LinkDest *dstn = pdfDoc->findDest(ndst);
+					LinkDest *dstn = pdfDoc->findDest(ndst).get();
 					if (dstn)
 					{
 						if (dstn->getKind() == destXYZ)
@@ -1019,7 +1019,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 				POPPLER_CONST GooString *ndst = gto->getNamedDest();
 				if (ndst)
 				{
-					LinkDest *dstn = pdfDoc->findDest(ndst);
+					LinkDest *dstn = pdfDoc->findDest(ndst).get();
 					if (dstn)
 					{
 						if (dstn->getKind() == destXYZ)
@@ -1039,7 +1039,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 		else if (Lact->getKind() == actionUnknown)
 		{
 			LinkUnknown *uno = (LinkUnknown*)Lact;
-			QString actString = UnicodeParsedString(uno->getAction());
+			QString actString = QString::fromStdString(uno->getAction());
 			if (actString == "ResetForm")
 			{
 				ite->annotation().setActionType(4);
@@ -1083,7 +1083,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 		{
 			LinkNamed *uno = (LinkNamed*)Lact;
 			ite->annotation().setActionType(10);
-			ite->annotation().setAction(UnicodeParsedString(uno->getName()));
+			ite->annotation().setAction(QString::fromStdString(uno->getName()));
 		}
 		else
 			qDebug() << "Found unsupported Action of type" << Lact->getKind();
@@ -1096,7 +1096,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 			LinkJavaScript *jsa = (LinkJavaScript*)Aact;
 			if (jsa->isOk())
 			{
-				ite->annotation().setD_act(UnicodeParsedString(jsa->getScript()));
+				ite->annotation().setD_act(QString::fromStdString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 			}
 		}
@@ -1110,7 +1110,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 			LinkJavaScript *jsa = (LinkJavaScript*)Aact;
 			if (jsa->isOk())
 			{
-				ite->annotation().setE_act(UnicodeParsedString(jsa->getScript()));
+				ite->annotation().setE_act(QString::fromStdString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 			}
 		}
@@ -1124,7 +1124,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 			LinkJavaScript *jsa = (LinkJavaScript*)Aact;
 			if (jsa->isOk())
 			{
-				ite->annotation().setX_act(UnicodeParsedString(jsa->getScript()));
+				ite->annotation().setX_act(QString::fromStdString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 			}
 		}
@@ -1138,7 +1138,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 			LinkJavaScript *jsa = (LinkJavaScript*)Aact;
 			if (jsa->isOk())
 			{
-				ite->annotation().setFo_act(UnicodeParsedString(jsa->getScript()));
+				ite->annotation().setFo_act(QString::fromStdString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 			}
 		}
@@ -1152,7 +1152,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 			LinkJavaScript *jsa = (LinkJavaScript*)Aact;
 			if (jsa->isOk())
 			{
-				ite->annotation().setBl_act(UnicodeParsedString(jsa->getScript()));
+				ite->annotation().setBl_act(QString::fromStdString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 			}
 		}
@@ -1166,7 +1166,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 			LinkJavaScript *jsa = (LinkJavaScript*)Aact;
 			if (jsa->isOk())
 			{
-				ite->annotation().setC_act(UnicodeParsedString(jsa->getScript()));
+				ite->annotation().setC_act(QString::fromStdString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 			}
 		}
@@ -1180,7 +1180,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 			LinkJavaScript *jsa = (LinkJavaScript*)Aact;
 			if (jsa->isOk())
 			{
-				ite->annotation().setF_act(UnicodeParsedString(jsa->getScript()));
+				ite->annotation().setF_act(QString::fromStdString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 				ite->annotation().setFormat(5);
 			}
@@ -1195,7 +1195,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 			LinkJavaScript *jsa = (LinkJavaScript*)Aact;
 			if (jsa->isOk())
 			{
-				ite->annotation().setK_act(UnicodeParsedString(jsa->getScript()));
+				ite->annotation().setK_act(QString::fromStdString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 				ite->annotation().setFormat(5);
 			}
@@ -1210,7 +1210,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 			LinkJavaScript *jsa = (LinkJavaScript*)Aact;
 			if (jsa->isOk())
 			{
-				ite->annotation().setV_act(UnicodeParsedString(jsa->getScript()));
+				ite->annotation().setV_act(QString::fromStdString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 			}
 		}
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
