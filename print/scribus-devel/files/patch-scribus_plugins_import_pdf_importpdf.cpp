--- scribus/plugins/import/pdf/importpdf.cpp.orig	2018-12-11 12:42:54 UTC
+++ scribus/plugins/import/pdf/importpdf.cpp
@@ -87,7 +87,7 @@ QImage PdfPlug::readThumbnail(QString fName)
 #else
 		GooString *fname = new GooString(QFile::encodeName(pdfFile).data());
 #endif
-		globalParams->setErrQuiet(gTrue);
+		globalParams->setErrQuiet(true);
 		PDFDoc *pdfDoc = new PDFDoc(fname, NULL, NULL, NULL);
 		if (pdfDoc)
 		{
@@ -108,11 +108,11 @@ QImage PdfPlug::readThumbnail(QString fName)
 				bgColor[0] = 255;
 				bgColor[1] = 255;
 				bgColor[2] = 255;
-				SplashOutputDev *dev = new SplashOutputDev(splashModeXBGR8, 4, gFalse, bgColor, gTrue);
-				dev->setVectorAntialias(gTrue);
-				dev->setFreeTypeHinting(gTrue, gFalse);
+				SplashOutputDev *dev = new SplashOutputDev(splashModeXBGR8, 4, false, bgColor, true);
+				dev->setVectorAntialias(true);
+				dev->setFreeTypeHinting(true, false);
 				dev->startDoc(pdfDoc);
-				pdfDoc->displayPage(dev, 1, hDPI, vDPI, 0, gTrue, gFalse, gFalse);
+				pdfDoc->displayPage(dev, 1, hDPI, vDPI, 0, true, false, false);
 				SplashBitmap *bitmap = dev->getBitmap();
 				int bw = bitmap->getWidth();
 				int bh = bitmap->getHeight();
@@ -410,10 +410,10 @@ bool PdfPlug::convert(const QString& fn)
 #else
 		GooString *fname = new GooString(QFile::encodeName(fn).data());
 #endif
-		globalParams->setErrQuiet(gTrue);
-		GBool hasOcg = gFalse;
+		globalParams->setErrQuiet(true);
+		bool hasOcg = false;
 		QList<OptionalContentGroup*> ocgGroups;
-//		globalParams->setPrintCommands(gTrue);
+//		globalParams->setPrintCommands(true);
 		PDFDoc *pdfDoc = new PDFDoc(fname, NULL, NULL, NULL);
 		if (pdfDoc)
 		{
@@ -458,10 +458,10 @@ bool PdfPlug::convert(const QString& fn)
 				double vDPI = 72.0;
 				int firstPage = 1;
 				int lastPage = pdfDoc->getNumPages();
-				GBool useMediaBox = gTrue;
-				GBool crop = gTrue;
-				GBool printing = gFalse;
-				PDFRectangle *mediaBox = pdfDoc->getPage(1)->getMediaBox();
+				bool useMediaBox = true;
+				bool crop = true;
+				bool printing = false;
+				const PDFRectangle *mediaBox = pdfDoc->getPage(1)->getMediaBox();
 				QRectF mediaRect = QRectF(QPointF(mediaBox->x1, mediaBox->y1), QPointF(mediaBox->x2, mediaBox->y2)).normalized();
 				bool boxesAreDifferent = false;
 				if (getCBox(Crop_Box, 1) != mediaRect)
@@ -497,7 +497,7 @@ bool PdfPlug::convert(const QString& fn)
 					if (!cropped)
 						crop = cropped;
 					if (contentRect != Media_Box)
-						useMediaBox = gFalse;
+						useMediaBox = false;
 				/*	if (cb > Media_Box)
 					{
 						cropped = true;
@@ -556,12 +556,10 @@ bool PdfPlug::convert(const QString& fn)
 									}
 									else
 									{
-										GooList *ocgs;
-										int i;
-										ocgs = ocg->getOCGs ();
-										for (i = 0; i < ocgs->getLength (); ++i)
+										const auto& ocgs = ocg->getOCGs ();
+										for (const auto& ocg : ocgs)
 										{
-											OptionalContentGroup *oc = (OptionalContentGroup *)ocgs->get(i);
+											OptionalContentGroup *oc = ocg.second.get();
 											QString ocgName = UnicodeParsedString(oc->getName());
 											if (!ocgNames.contains(ocgName))
 											{
@@ -574,12 +572,10 @@ bool PdfPlug::convert(const QString& fn)
 							}
 							else
 							{
-								GooList *ocgs;
-								int i;
-								ocgs = ocg->getOCGs ();
-								for (i = 0; i < ocgs->getLength (); ++i)
+								const auto& ocgs = ocg->getOCGs ();
+								for (const auto& ocg : ocgs)
 								{
-									OptionalContentGroup *oc = (OptionalContentGroup *)ocgs->get(i);
+									OptionalContentGroup *oc = ocg.second.get();
 									QString ocgName = UnicodeParsedString(oc->getName());
 									if (!ocgNames.contains(ocgName))
 									{
@@ -1018,11 +1014,11 @@ QImage PdfPlug::readPreview(int pgNum, int width, int 
 	bgColor[0] = 255;
 	bgColor[1] = 255;
 	bgColor[2] = 255;
-	SplashOutputDev *dev = new SplashOutputDev(splashModeXBGR8, 4, gFalse, bgColor, gTrue);
-	dev->setVectorAntialias(gTrue);
-	dev->setFreeTypeHinting(gTrue, gFalse);
+	SplashOutputDev *dev = new SplashOutputDev(splashModeXBGR8, 4, false, bgColor, true);
+	dev->setVectorAntialias(true);
+	dev->setFreeTypeHinting(true, false);
 	dev->startDoc(m_pdfDoc);
-	m_pdfDoc->displayPage(dev, pgNum, hDPI, vDPI, 0, gTrue, gFalse, gFalse);
+	m_pdfDoc->displayPage(dev, pgNum, hDPI, vDPI, 0, true, false, false);
 	SplashBitmap *bitmap = dev->getBitmap();
 	int bw = bitmap->getWidth();
 	int bh = bitmap->getHeight();
@@ -1066,7 +1062,7 @@ QImage PdfPlug::readPreview(int pgNum, int width, int 
 
 QRectF PdfPlug::getCBox(int box, int pgNum)
 {
-	PDFRectangle *cBox = NULL;
+	const PDFRectangle *cBox = NULL;
 	if (box == Media_Box)
 		cBox = m_pdfDoc->getPage(pgNum)->getMediaBox();
 	else if (box == Bleed_Box)
@@ -1081,23 +1077,23 @@ QRectF PdfPlug::getCBox(int box, int pgNum)
 	return cRect;
 }
 
-QString PdfPlug::UnicodeParsedString(GooString *s1)
+QString PdfPlug::UnicodeParsedString(const GooString *s1)
 {
 	if ( !s1 || s1->getLength() == 0 )
 		return QString();
-	GBool isUnicode;
+	bool isUnicode;
 	int i;
 	Unicode u;
 	QString result;
 	if ((s1->getChar(0) & 0xff) == 0xfe && (s1->getLength() > 1 && (s1->getChar(1) & 0xff) == 0xff))
 	{
-		isUnicode = gTrue;
+		isUnicode = true;
 		i = 2;
 		result.reserve((s1->getLength() - 2) / 2);
 	}
 	else
 	{
-		isUnicode = gFalse;
+		isUnicode = false;
 		i = 0;
 		result.reserve(s1->getLength());
 	}
