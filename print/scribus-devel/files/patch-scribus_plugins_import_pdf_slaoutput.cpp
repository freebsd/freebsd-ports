--- scribus/plugins/import/pdf/slaoutput.cpp.orig	2018-12-11 13:04:07 UTC
+++ scribus/plugins/import/pdf/slaoutput.cpp
@@ -44,7 +44,7 @@ LinkSubmitForm::LinkSubmitForm(Object *actionObj)
 				{
 					if (obj3.isName())
 					{
-						char *name = obj3.getName();
+						const char *name = obj3.getName();
 						if (!strcmp(name, "URL"))
 						{
 							obj2 = obj1.dictLookup("F");
@@ -179,7 +179,7 @@ void AnoOutputDev::stroke(GfxState *state)
 	CurrColorStroke = getColor(state->getStrokeColorSpace(), state->getStrokeColor(), &shade);
 }
 
-void AnoOutputDev::drawString(GfxState *state, GooString *s)
+void AnoOutputDev::drawString(GfxState *state, const GooString *s)
 {
 	int shade = 100;
 	CurrColorText = getColor(state->getFillColorSpace(), state->getFillColor(), &shade);
@@ -189,7 +189,7 @@ void AnoOutputDev::drawString(GfxState *state, GooStri
 	m_itemText = s->copy();
 }
 
-QString AnoOutputDev::getColor(GfxColorSpace *color_space, GfxColor *color, int *shade)
+QString AnoOutputDev::getColor(GfxColorSpace *color_space, const GfxColor *color, int *shade)
 {
 	QString fNam;
 	QString namPrefix = "FromPDF";
@@ -229,7 +229,7 @@ QString AnoOutputDev::getColor(GfxColorSpace *color_sp
 	else if (color_space->getMode() == csSeparation)
 	{
 		GfxCMYK cmyk;
-		QString name = QString(((GfxSeparationColorSpace*)color_space)->getName()->getCString());
+		QString name = QString(((GfxSeparationColorSpace*)color_space)->getName()->c_str());
 		double Cc, Mc, Yc, Kc;
 		bool isRegistrationColor = (name == "All");
 		if (!isRegistrationColor)
@@ -410,7 +410,7 @@ LinkAction* SlaOutputDev::SC_getAdditionalAction(const
 	return linkAction;
 }
 
-GBool SlaOutputDev::annotations_callback(Annot *annota, void *user_data)
+bool SlaOutputDev::annotations_callback(Annot *annota, void *user_data)
 {
 	SlaOutputDev *dev = (SlaOutputDev*)user_data;
 	PDFRectangle *box = annota->getRect();
@@ -509,7 +509,7 @@ bool SlaOutputDev::handleLinkAnnot(Annot* annota, doub
 	if (act->getKind() == actionGoTo)
 	{
 		LinkGoTo *gto = (LinkGoTo*)act;
-		LinkDest *dst = gto->getDest();
+		const LinkDest *dst = gto->getDest();
 		if (dst)
 		{
 			if (dst->getKind() == destXYZ)
@@ -528,10 +528,10 @@ bool SlaOutputDev::handleLinkAnnot(Annot* annota, doub
 		}
 		else
 		{
-			GooString *ndst = gto->getNamedDest();
+			const GooString *ndst = gto->getNamedDest();
 			if (ndst)
 			{
-				LinkDest *dstn = pdfDoc->findDest(ndst);
+				const LinkDest *dstn = pdfDoc->findDest(ndst);
 				if (dstn)
 				{
 					if (dstn->getKind() == destXYZ)
@@ -555,7 +555,7 @@ bool SlaOutputDev::handleLinkAnnot(Annot* annota, doub
 	{
 		LinkGoToR *gto = (LinkGoToR*)act;
 		fileName = UnicodeParsedString(gto->getFileName());
-		LinkDest *dst = gto->getDest();
+		const LinkDest *dst = gto->getDest();
 		if (dst)
 		{
 			if (dst->getKind() == destXYZ)
@@ -568,10 +568,10 @@ bool SlaOutputDev::handleLinkAnnot(Annot* annota, doub
 		}
 		else
 		{
-			GooString *ndst = gto->getNamedDest();
+			const GooString *ndst = gto->getNamedDest();
 			if (ndst)
 			{
-				LinkDest *dstn = pdfDoc->findDest(ndst);
+				const LinkDest *dstn = pdfDoc->findDest(ndst);
 				if (dstn)
 				{
 					if (dstn->getKind() == destXYZ)
@@ -709,7 +709,7 @@ bool SlaOutputDev::handleWidgetAnnot(Annot* annota, do
 			bool bgFound = false;
 			if (achar)
 			{
-				AnnotColor *bgCol = achar->getBackColor();
+				const AnnotColor *bgCol = achar->getBackColor();
 				if (bgCol)
 				{
 					bgFound = true;
@@ -717,7 +717,7 @@ bool SlaOutputDev::handleWidgetAnnot(Annot* annota, do
 				}
 				else
 					CurrColorFill = CommonStrings::None;
-				AnnotColor *fgCol = achar->getBorderColor();
+				const AnnotColor *fgCol = achar->getBorderColor();
 				if (fgCol)
 				{
 					fgFound = true;
@@ -1054,7 +1054,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 			int xco = 0;
 			int yco = 0;
 			LinkGoTo *gto = (LinkGoTo*)Lact;
-			LinkDest *dst = gto->getDest();
+			const LinkDest *dst = gto->getDest();
 			if (dst)
 			{
 				if (dst->getKind() == destXYZ)
@@ -1075,10 +1075,10 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 			}
 			else
 			{
-				GooString *ndst = gto->getNamedDest();
+				const GooString *ndst = gto->getNamedDest();
 				if (ndst)
 				{
-					LinkDest *dstn = pdfDoc->findDest(ndst);
+					const LinkDest *dstn = pdfDoc->findDest(ndst);
 					if (dstn)
 					{
 						if (dstn->getKind() == destXYZ)
@@ -1107,7 +1107,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 			int yco = 0;
 			LinkGoToR *gto = (LinkGoToR*)Lact;
 			QString fileName = UnicodeParsedString(gto->getFileName());
-			LinkDest *dst = gto->getDest();
+			const LinkDest *dst = gto->getDest();
 			if (dst)
 			{
 				if (dst->getKind() == destXYZ)
@@ -1123,10 +1123,10 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotW
 			}
 			else
 			{
-				GooString *ndst = gto->getNamedDest();
+				const GooString *ndst = gto->getNamedDest();
 				if (ndst)
 				{
-					LinkDest *dstn = pdfDoc->findDest(ndst);
+					const LinkDest *dstn = pdfDoc->findDest(ndst);
 					if (dstn)
 					{
 						if (dstn->getKind() == destXYZ)
@@ -1462,7 +1462,7 @@ void SlaOutputDev::restoreState(GfxState *state)
 		m_currentClipPath = m_clipPaths.pop();
 }
 
-void SlaOutputDev::beginTransparencyGroup(GfxState *state, double *bbox, GfxColorSpace * /*blendingColorSpace*/, GBool isolated, GBool knockout, GBool forSoftMask)
+void SlaOutputDev::beginTransparencyGroup(GfxState *state, double *bbox, GfxColorSpace * /*blendingColorSpace*/, bool isolated, bool knockout, bool forSoftMask)
 {
 	pushGroup("", forSoftMask);
 	m_groupStack.top().isolated = isolated;
@@ -1562,7 +1562,7 @@ void SlaOutputDev::endTransparencyGroup(GfxState *stat
 	}
 }
 
-void SlaOutputDev::setSoftMask(GfxState * /*state*/, double * /*bbox*/, GBool alpha, Function *transferFunc, GfxColor * /*backdropColor*/)
+void SlaOutputDev::setSoftMask(GfxState * /*state*/, const double * /*bbox*/, bool alpha, Function *transferFunc, GfxColor * /*backdropColor*/)
 {
 	if (m_groupStack.count() != 0)
 	{
@@ -1604,8 +1604,7 @@ void SlaOutputDev::updateStrokeColor(GfxState *state)
 void SlaOutputDev::clip(GfxState *state)
 {
 //	qDebug() << "Clip";
-	double *ctm;
-	ctm = state->getCTM();
+	const double *ctm = state->getCTM();
 	m_ctm = QTransform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
 	QString output = convertPath(state->getPath());
 	FPointArray out;
@@ -1641,8 +1640,7 @@ void SlaOutputDev::clip(GfxState *state)
 void SlaOutputDev::eoClip(GfxState *state)
 {
 //	qDebug() << "EoClip";
-	double *ctm;
-	ctm = state->getCTM();
+	const double *ctm = state->getCTM();
 	m_ctm = QTransform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
 	QString output = convertPath(state->getPath());
 	FPointArray out;
@@ -1678,7 +1676,7 @@ void SlaOutputDev::eoClip(GfxState *state)
 void SlaOutputDev::stroke(GfxState *state)
 {
 //	qDebug() << "Stroke";
-	double *ctm;
+	const double *ctm;
 	ctm = state->getCTM();
 	double xCoor = m_doc->currentPage()->xOffset();
 	double yCoor = m_doc->currentPage()->yOffset();
@@ -1770,7 +1768,7 @@ void SlaOutputDev::stroke(GfxState *state)
 void SlaOutputDev::fill(GfxState *state)
 {
 //	qDebug() << "Fill";
-	double *ctm;
+	const double *ctm;
 	ctm = state->getCTM();
 	double xCoor = m_doc->currentPage()->xOffset();
 	double yCoor = m_doc->currentPage()->yOffset();
@@ -1815,7 +1813,7 @@ void SlaOutputDev::fill(GfxState *state)
 void SlaOutputDev::eoFill(GfxState *state)
 {
 //	qDebug() << "EoFill";
-	double *ctm;
+	const double *ctm;
 	ctm = state->getCTM();
 	double xCoor = m_doc->currentPage()->xOffset();
 	double yCoor = m_doc->currentPage()->yOffset();
@@ -1857,21 +1855,21 @@ void SlaOutputDev::eoFill(GfxState *state)
 	}
 }
 
-GBool SlaOutputDev::axialShadedFill(GfxState *state, GfxAxialShading *shading, double tMin, double tMax)
+bool SlaOutputDev::axialShadedFill(GfxState *state, GfxAxialShading *shading, double tMin, double tMax)
 {
 	double GrStartX;
 	double GrStartY;
 	double GrEndX;
 	double GrEndY;
 	int shade = 100;
-	Function *func = shading->getFunc(0);
+	const Function *func = shading->getFunc(0);
 	VGradient FillGradient = VGradient(VGradient::linear);
 	FillGradient.clearStops();
 	GfxColorSpace *color_space = shading->getColorSpace();
 	if (func->getType() == 3)
 	{
 		StitchingFunction *stitchingFunc = (StitchingFunction*)func;
-		double *bounds = stitchingFunc->getBounds();
+		const double *bounds = stitchingFunc->getBounds();
 		int num_funcs = stitchingFunc->getNumFuncs();
 		// Add stops from all the stitched functions
 		for ( int i = 0 ; i < num_funcs ; i++ )
@@ -1905,8 +1903,7 @@ GBool SlaOutputDev::axialShadedFill(GfxState *state, G
 	state->getClipBBox(&xmin, &ymin, &xmax, &ymax);
 	QRectF crect = QRectF(QPointF(xmin, ymin), QPointF(xmax, ymax));
 	crect = crect.normalized();
-	double *ctm;
-	ctm = state->getCTM();
+	const double *ctm = state->getCTM();
 	m_ctm = QTransform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
 	FPointArray gr;
 	gr.addPoint(GrStartX, GrStartY);
@@ -1965,24 +1962,24 @@ GBool SlaOutputDev::axialShadedFill(GfxState *state, G
 		m_groupStack.top().Items.append(ite);
 		applyMask(ite);
 	}
-	return gTrue;
+	return true;
 }
 
-GBool SlaOutputDev::radialShadedFill(GfxState *state, GfxRadialShading *shading, double sMin, double sMax)
+bool SlaOutputDev::radialShadedFill(GfxState *state, GfxRadialShading *shading, double sMin, double sMax)
 {
 	double GrStartX;
 	double GrStartY;
 	double GrEndX;
 	double GrEndY;
 	int shade = 100;
-	Function *func = shading->getFunc(0);
+	const Function *func = shading->getFunc(0);
 	VGradient FillGradient = VGradient(VGradient::linear);
 	FillGradient.clearStops();
 	GfxColorSpace *color_space = shading->getColorSpace();
 	if (func->getType() == 3)
 	{
 		StitchingFunction *stitchingFunc = (StitchingFunction*)func;
-		double *bounds = stitchingFunc->getBounds();
+		const double *bounds = stitchingFunc->getBounds();
 		int num_funcs = stitchingFunc->getNumFuncs();
 		// Add stops from all the stitched functions
 		for ( int i = 0 ; i < num_funcs ; i++ )
@@ -2021,8 +2018,7 @@ GBool SlaOutputDev::radialShadedFill(GfxState *state, 
 	double GrFocalY = y1;
 	GrEndX = GrFocalX + r1;
 	GrEndY = GrFocalY;
-	double *ctm;
-	ctm = state->getCTM();
+	const double *ctm = state->getCTM();
 	m_ctm = QTransform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
 	FPointArray gr;
 	gr.addPoint(GrStartX, GrStartY);
@@ -2084,10 +2080,10 @@ GBool SlaOutputDev::radialShadedFill(GfxState *state, 
 		m_groupStack.top().Items.append(ite);
 		applyMask(ite);
 	}
-	return gTrue;
+	return true;
 }
 
-GBool SlaOutputDev::gouraudTriangleShadedFill(GfxState *state, GfxGouraudTriangleShading *shading)
+bool SlaOutputDev::gouraudTriangleShadedFill(GfxState *state, GfxGouraudTriangleShading *shading)
 {
 	double xCoor = m_doc->currentPage()->xOffset();
 	double yCoor = m_doc->currentPage()->yOffset();
@@ -2104,8 +2100,7 @@ GBool SlaOutputDev::gouraudTriangleShadedFill(GfxState
 	output += QString("Z");
 	pathIsClosed = true;
 	Coords = output;
-	double *ctm;
-	ctm = state->getCTM();
+	const double *ctm = state->getCTM();
 	m_ctm = QTransform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
 	int z = m_doc->itemAdd(PageItem::Polygon, PageItem::Rectangle, xCoor + crect.x(), yCoor + crect.y(), crect.width(), crect.height(), 0, CurrColorFill, CommonStrings::None);
 	PageItem* ite = m_doc->Items->at(z);
@@ -2164,10 +2159,10 @@ GBool SlaOutputDev::gouraudTriangleShadedFill(GfxState
 		ite->meshGradientPatches.append(patchM);
 	}
 	ite->GrType = 12;
-	return gTrue;
+	return true;
 }
 
-GBool SlaOutputDev::patchMeshShadedFill(GfxState *state, GfxPatchMeshShading *shading)
+bool SlaOutputDev::patchMeshShadedFill(GfxState *state, GfxPatchMeshShading *shading)
 {
 //	qDebug() << "mesh shaded fill";
 	double xCoor = m_doc->currentPage()->xOffset();
@@ -2185,8 +2180,7 @@ GBool SlaOutputDev::patchMeshShadedFill(GfxState *stat
 	output += QString("Z");
 	pathIsClosed = true;
 	Coords = output;
-	double *ctm;
-	ctm = state->getCTM();
+	const double *ctm = state->getCTM();
 	m_ctm = QTransform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
 	int z = m_doc->itemAdd(PageItem::Polygon, PageItem::Rectangle, xCoor + crect.x(), yCoor + crect.y(), crect.width(), crect.height(), 0, CurrColorFill, CommonStrings::None);
 	PageItem* ite = m_doc->Items->at(z);
@@ -2211,7 +2205,7 @@ GBool SlaOutputDev::patchMeshShadedFill(GfxState *stat
 	for (int i = 0; i < shading->getNPatches(); i++)
 	{
 		int shade = 100;
-		GfxPatch *patch = shading->getPatch(i);
+		const GfxPatch *patch = shading->getPatch(i);
 		GfxColor color;
 		meshGradientPatch patchM;
 		int u, v;
@@ -2314,18 +2308,18 @@ GBool SlaOutputDev::patchMeshShadedFill(GfxState *stat
 		ite->meshGradientPatches.append(patchM);
 	}
 	ite->GrType = 12;
-	return gTrue;
+	return true;
 }
 
-GBool SlaOutputDev::tilingPatternFill(GfxState *state, Gfx * /*gfx*/, Catalog *cat, Object *str, double *pmat, int paintType, int tilingType, Dict *resDict, double *mat, double *bbox, int x0, int y0, int x1, int y1, double xStep, double yStep)
+bool SlaOutputDev::tilingPatternFill(GfxState *state, Gfx * /*gfx*/, Catalog *cat, Object *str, double *pmat, int paintType, int tilingType, Dict *resDict, double *mat, double *bbox, int x0, int y0, int x1, int y1, double xStep, double yStep)
 {
 	PDFRectangle box;
 	Gfx *gfx;
 	QString id;
 	PageItem *ite;
 	groupEntry gElements;
-	gElements.forSoftMask = gFalse;
-	gElements.alpha = gFalse;
+	gElements.forSoftMask = false;
+	gElements.alpha = false;
 	gElements.inverted = false;
 	gElements.maskName = "";
 	gElements.Items.clear();
@@ -2334,13 +2328,12 @@ GBool SlaOutputDev::tilingPatternFill(GfxState *state,
 	width = bbox[2] - bbox[0];
 	height = bbox[3] - bbox[1];
 	if (xStep != width || yStep != height)
-		return gFalse;
+		return false;
 	box.x1 = bbox[0];
 	box.y1 = bbox[1];
 	box.x2 = bbox[2];
 	box.y2 = bbox[3];
-	double *ctm;
-	ctm = state->getCTM();
+	const double *ctm = state->getCTM();
 	m_ctm = QTransform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
 	QTransform mm = QTransform(mat[0], mat[1], mat[2], mat[3], mat[4], mat[5]);
 	QTransform mmx = mm * m_ctm;
@@ -2437,10 +2430,10 @@ GBool SlaOutputDev::tilingPatternFill(GfxState *state,
 		applyMask(ite);
 	}
 	delete gfx;
-	return gTrue;
+	return true;
 }
 
-void SlaOutputDev::drawImageMask(GfxState *state, Object *ref, Stream *str, int width, int height, GBool invert, GBool interpolate, GBool inlineImg)
+void SlaOutputDev::drawImageMask(GfxState *state, Object *ref, Stream *str, int width, int height, bool invert, bool interpolate, bool inlineImg)
 {
 //	qDebug() << "Draw Image Mask";
 	QImage * image = 0;
@@ -2512,8 +2505,7 @@ void SlaOutputDev::drawImageMask(GfxState *state, Obje
 			t++;
 		}
 	}
-	double *ctm;
-	ctm = state->getCTM();
+	const double *ctm = state->getCTM();
 	double xCoor = m_doc->currentPage()->xOffset();
 	double yCoor = m_doc->currentPage()->yOffset();
 	QRectF crect = QRectF(0, 0, width, height);
@@ -2605,8 +2597,8 @@ void SlaOutputDev::drawImageMask(GfxState *state, Obje
 	delete image;
 }
 
-void SlaOutputDev::drawSoftMaskedImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, GBool interpolate, Stream *maskStr, int maskWidth, int maskHeight,
-				   GfxImageColorMap *maskColorMap, GBool maskInterpolate)
+void SlaOutputDev::drawSoftMaskedImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, bool interpolate, Stream *maskStr, int maskWidth, int maskHeight,
+				   GfxImageColorMap *maskColorMap, bool maskInterpolate)
 {
 //	qDebug() << "Masked Image Components" << colorMap->getNumPixelComps();
 	ImageStream * imgStr = new ImageStream(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
@@ -2658,8 +2650,7 @@ void SlaOutputDev::drawSoftMaskedImage(GfxState *state
 			t++;
 		}
 	}
-	double *ctm;
-	ctm = state->getCTM();
+	const double *ctm = state->getCTM();
 	double xCoor = m_doc->currentPage()->xOffset();
 	double yCoor = m_doc->currentPage()->yOffset();
 	QRectF crect = QRectF(0, 0, width, height);
@@ -2750,7 +2741,7 @@ void SlaOutputDev::drawSoftMaskedImage(GfxState *state
 	delete[] mbuffer;
 }
 
-void SlaOutputDev::drawMaskedImage(GfxState *state, Object *ref, Stream *str,  int width, int height, GfxImageColorMap *colorMap, GBool interpolate, Stream *maskStr, int maskWidth, int maskHeight, GBool maskInvert, GBool maskInterpolate)
+void SlaOutputDev::drawMaskedImage(GfxState *state, Object *ref, Stream *str,  int width, int height, GfxImageColorMap *colorMap, bool interpolate, Stream *maskStr, int maskWidth, int maskHeight, bool maskInvert, bool maskInterpolate)
 {
 	ImageStream * imgStr = new ImageStream(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
 	imgStr->reset();
@@ -2808,8 +2799,7 @@ void SlaOutputDev::drawMaskedImage(GfxState *state, Ob
 			t++;
 		}
 	}
-	double *ctm;
-	ctm = state->getCTM();
+	const double *ctm = state->getCTM();
 	double xCoor = m_doc->currentPage()->xOffset();
 	double yCoor = m_doc->currentPage()->yOffset();
 	QRectF crect = QRectF(0, 0, width, height);
@@ -2900,7 +2890,7 @@ void SlaOutputDev::drawMaskedImage(GfxState *state, Ob
 	delete[] mbuffer;
 }
 
-void SlaOutputDev::drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, GBool interpolate, int *maskColors, GBool inlineImg)
+void SlaOutputDev::drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, bool interpolate, int *maskColors, bool inlineImg)
 {
 	ImageStream * imgStr = new ImageStream(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
 //	qDebug() << "Image Components" << colorMap->getNumPixelComps() << "Mask" << maskColors;
@@ -2973,8 +2963,7 @@ void SlaOutputDev::drawImage(GfxState *state, Object *
 		delete image;
 		return;
 	}
-	double *ctm;
-	ctm = state->getCTM();
+	const double *ctm = state->getCTM();
 	double xCoor = m_doc->currentPage()->xOffset();
 	double yCoor = m_doc->currentPage()->yOffset();
 	QRectF crect = QRectF(0, 0, width, height);
@@ -3103,7 +3092,7 @@ void SlaOutputDev::drawImage(GfxState *state, Object *
 	delete image;
 }
 
-void SlaOutputDev::beginMarkedContent(char *name, Object *dictRef)
+void SlaOutputDev::beginMarkedContent(const char *name, Object *dictRef)
 {
 	mContent mSte;
 	mSte.name = QString(name);
@@ -3172,7 +3161,7 @@ void SlaOutputDev::beginMarkedContent(char *name, Obje
 	m_mcStack.push(mSte);
 }
 
-void SlaOutputDev::beginMarkedContent(char *name, Dict *properties)
+void SlaOutputDev::beginMarkedContent(const char *name, Dict *properties)
 {
 //	qDebug() << "Begin Marked Content with Name " << QString(name);
 	QString nam = QString(name);
@@ -3190,13 +3179,13 @@ void SlaOutputDev::beginMarkedContent(char *name, Dict
 #if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 58, 0)
 			Object obj = properties->lookup((char*) "Title");
 			if (obj.isString())
-				lName = QString(obj.getString()->getCString());
+				lName = QString(obj.getString()->c_str());
 #else
 			Object obj;
 			if (properties->lookup((char*)"Title", &obj))
 			{
 				if (obj.isString())
-					lName =  QString(obj.getString()->getCString());
+					lName =  QString(obj.getString()->c_str());
 				obj.free();
 			}
 #endif
@@ -3299,12 +3288,12 @@ void SlaOutputDev::endMarkedContent(GfxState *state)
 	}
 }
 
-void SlaOutputDev::markPoint(char *name)
+void SlaOutputDev::markPoint(const char *name)
 {
 //	qDebug() << "Begin Marked Point with Name " << QString(name);
 }
 
-void SlaOutputDev::markPoint(char *name, Dict *properties)
+void SlaOutputDev::markPoint(const char *name, Dict *properties)
 {
 //	qDebug() << "Begin Marked Point with Name " << QString(name) << "and Properties";
 	beginMarkedContent(name, properties);
@@ -3326,7 +3315,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 	char *tmpBuf;
 	int tmpBufLen = 0;
 	int *codeToGID;
-	double *textMat;
+	const double *textMat;
 	double m11, m12, m21, m22, fontSize;
 	SplashCoord mat[4];
 	int n = 0;
@@ -3355,7 +3344,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 
 		if (!(fontLoc = gfxFont->locateFont(xref, 0))) {
 			error(errSyntaxError, -1, "Couldn't find a font for '{0:s}'",
-			gfxFont->getName() ? gfxFont->getName()->getCString()
+			gfxFont->getName() ? gfxFont->getName()->c_str()
 			: "(unnamed)");
 			goto err2;
 		}
@@ -3375,9 +3364,9 @@ void SlaOutputDev::updateFont(GfxState *state)
 
 		fontsrc = new SplashFontSrc;
 		if (fileName)
-			fontsrc->setFile(fileName, gFalse);
+			fontsrc->setFile(fileName, false);
 		else
-			fontsrc->setBuf(tmpBuf, tmpBufLen, gTrue);
+			fontsrc->setBuf(tmpBuf, tmpBufLen, true);
 
 		// load the font file
 		switch (fontType) {
@@ -3388,7 +3377,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 				(const char **)((Gfx8BitFont *)gfxFont)->getEncoding())))
 			{
 				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
-				gfxFont->getName() ? gfxFont->getName()->getCString()
+				gfxFont->getName() ? gfxFont->getName()->c_str()
 				: "(unnamed)");
 				goto err2;
 			}
@@ -3400,7 +3389,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 							(const char **)((Gfx8BitFont *)gfxFont)->getEncoding())))
 			{
 				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
-				gfxFont->getName() ? gfxFont->getName()->getCString()
+				gfxFont->getName() ? gfxFont->getName()->c_str()
 				: "(unnamed)");
 				goto err2;
 			}
@@ -3412,7 +3401,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 							(const char **)((Gfx8BitFont *)gfxFont)->getEncoding())))
 			{
 				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
-				gfxFont->getName() ? gfxFont->getName()->getCString()
+				gfxFont->getName() ? gfxFont->getName()->c_str()
 				: "(unnamed)");
 				goto err2;
 			}
@@ -3420,7 +3409,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 		case fontTrueType:
 		case fontTrueTypeOT:
 			if (fileName)
-				ff = FoFiTrueType::load(fileName->getCString());
+				ff = FoFiTrueType::load(fileName->c_str());
 			else
 				ff = FoFiTrueType::make(tmpBuf, tmpBufLen);
 			if (ff) {
@@ -3437,7 +3426,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 							codeToGID, n)))
 			{
 				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
-				gfxFont->getName() ? gfxFont->getName()->getCString()
+				gfxFont->getName() ? gfxFont->getName()->c_str()
 				: "(unnamed)");
 				goto err2;
 			}
@@ -3449,7 +3438,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 							fontsrc)))
 			{
 				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
-				gfxFont->getName() ? gfxFont->getName()->getCString()
+				gfxFont->getName() ? gfxFont->getName()->c_str()
 				: "(unnamed)");
 				goto err2;
 			}
@@ -3470,7 +3459,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 							codeToGID, n)))
 			{
 				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
-				gfxFont->getName() ? gfxFont->getName()->getCString()
+				gfxFont->getName() ? gfxFont->getName()->c_str()
 				: "(unnamed)");
 				goto err2;
 			}
@@ -3488,7 +3477,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 				}
 			} else {
 				if (fileName)
-					ff = FoFiTrueType::load(fileName->getCString());
+					ff = FoFiTrueType::load(fileName->c_str());
 				else
 					ff = FoFiTrueType::make(tmpBuf, tmpBufLen);
 				if (! ff)
@@ -3502,7 +3491,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 							codeToGID, n, faceIndex)))
 			{
 				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
-				gfxFont->getName() ? gfxFont->getName()->getCString()
+				gfxFont->getName() ? gfxFont->getName()->c_str()
 				: "(unnamed)");
 				goto err2;
 			}
@@ -3604,7 +3593,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 			}
 			if (!dfp)
 			{
-		//		error(-1, "Couldn't find a font for '%s'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+		//		error(-1, "Couldn't find a font for '%s'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 				goto err2;
 			}
 			switch (dfp->kind)
@@ -3622,37 +3611,37 @@ void SlaOutputDev::updateFont(GfxState *state)
 		}
 		fontsrc = new SplashFontSrc;
 		if (fileName)
-			fontsrc->setFile(fileName, gFalse);
+			fontsrc->setFile(fileName, false);
 		else
-			fontsrc->setBuf(tmpBuf, tmpBufLen, gTrue);
+			fontsrc->setBuf(tmpBuf, tmpBufLen, true);
 		// load the font file
 		switch (fontType)
 		{
 			case fontType1:
 				if (!(fontFile = m_fontEngine->loadType1Font( id, fontsrc, ((Gfx8BitFont *)gfxFont)->getEncoding())))
 				{
-			//		error(-1, "Couldn't create a font for '%s'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+			//		error(-1, "Couldn't create a font for '%s'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 					goto err2;
 				}
 				break;
 			case fontType1C:
 				if (!(fontFile = m_fontEngine->loadType1CFont( id, fontsrc, ((Gfx8BitFont *)gfxFont)->getEncoding())))
 				{
-		//			error(-1, "Couldn't create a font for '%s'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+		//			error(-1, "Couldn't create a font for '%s'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 					goto err2;
 				}
 				break;
 			case fontType1COT:
 				if (!(fontFile = m_fontEngine->loadOpenTypeT1CFont( id, fontsrc, ((Gfx8BitFont *)gfxFont)->getEncoding())))
 				{
-		//			error(-1, "Couldn't create a font for '%s'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+		//			error(-1, "Couldn't create a font for '%s'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 					goto err2;
 				}
 				break;
 			case fontTrueType:
 			case fontTrueTypeOT:
 				if (fileName)
-					ff = FoFiTrueType::load(fileName->getCString());
+					ff = FoFiTrueType::load(fileName->c_str());
 				else
 					ff = FoFiTrueType::make(tmpBuf, tmpBufLen);
 				if (ff)
@@ -3668,7 +3657,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 				}
 				if (!(fontFile = m_fontEngine->loadTrueTypeFont( id, fontsrc, codeToGID, n)))
 				{
-	//				error(-1, "Couldn't create a font for '%s'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+	//				error(-1, "Couldn't create a font for '%s'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 					goto err2;
 				}
 			break;
@@ -3676,14 +3665,14 @@ void SlaOutputDev::updateFont(GfxState *state)
 		case fontCIDType0C:
 			if (!(fontFile = m_fontEngine->loadCIDFont( id, fontsrc)))
 			{
-	//			error(-1, "Couldn't create a font for '%s'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+	//			error(-1, "Couldn't create a font for '%s'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 				goto err2;
 			}
 			break;
 		case fontCIDType0COT:
 			if (!(fontFile = m_fontEngine->loadOpenTypeCFFFont( id, fontsrc)))
 			{
-	//			error(-1, "Couldn't create a font for '%s'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+	//			error(-1, "Couldn't create a font for '%s'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 				goto err2;
 			}
 			break;
@@ -3703,7 +3692,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 			else
 			{
 				if (fileName)
-					ff = FoFiTrueType::load(fileName->getCString());
+					ff = FoFiTrueType::load(fileName->c_str());
 				else
 					ff = FoFiTrueType::make(tmpBuf, tmpBufLen);
 				if (!ff)
@@ -3713,7 +3702,7 @@ void SlaOutputDev::updateFont(GfxState *state)
 			}
 			if (!(fontFile = m_fontEngine->loadTrueTypeFont( id, fontsrc, codeToGID, n, faceIndex)))
 			{
-	//			error(-1, "Couldn't create a font for '%s'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+	//			error(-1, "Couldn't create a font for '%s'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 				goto err2;
 			}
 			break;
@@ -3793,8 +3782,7 @@ void SlaOutputDev::drawChar(GfxState *state, double x,
 				if (f & splashPathLast)
 					qPath.closeSubpath();
 			}
-			double *ctm;
-			ctm = state->getCTM();
+			const double *ctm = state->getCTM();
 			m_ctm = QTransform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
 			double xCoor = m_doc->currentPage()->xOffset();
 			double yCoor = m_doc->currentPage()->yOffset();
@@ -3842,19 +3830,19 @@ void SlaOutputDev::drawChar(GfxState *state, double x,
 	}
 }
 
-GBool SlaOutputDev::beginType3Char(GfxState *state, double x, double y, double dx, double dy, CharCode code, Unicode *u, int uLen)
+bool SlaOutputDev::beginType3Char(GfxState *state, double x, double y, double dx, double dy, CharCode code, Unicode *u, int uLen)
 {
 //	qDebug() << "beginType3Char";
 	GfxFont *gfxFont;
 	if (!(gfxFont = state->getFont()))
-		return gTrue;
+		return true;
 	if (gfxFont->getType() != fontType3)
-		return gTrue;
+		return true;
 	F3Entry f3e;
 	f3e.colored = false;
 	m_F3Stack.push(f3e);
 	pushGroup();
-	return gFalse;
+	return false;
 }
 
 void SlaOutputDev::endType3Char(GfxState *state)
@@ -3948,7 +3936,7 @@ void SlaOutputDev::endTextObject(GfxState *state)
 	}
 }
 
-QString SlaOutputDev::getColor(GfxColorSpace *color_space, GfxColor *color, int *shade)
+QString SlaOutputDev::getColor(GfxColorSpace *color_space, const GfxColor *color, int *shade)
 {
 	QString fNam;
 	QString namPrefix = "FromPDF";
@@ -3993,7 +3981,7 @@ QString SlaOutputDev::getColor(GfxColorSpace *color_sp
 	else if (color_space->getMode() == csSeparation)
 	{
 		GfxCMYK cmyk;
-		QString name = QString(((GfxSeparationColorSpace*)color_space)->getName()->getCString());
+		QString name = QString(((GfxSeparationColorSpace*)color_space)->getName()->c_str());
 		double Cc, Mc, Yc, Kc;
 		bool isRegistrationColor = (name == "All");
 		if (!isRegistrationColor)
@@ -4032,7 +4020,7 @@ QString SlaOutputDev::getColor(GfxColorSpace *color_sp
 	return fNam;
 }
 
-QString SlaOutputDev::getAnnotationColor(AnnotColor *color)
+QString SlaOutputDev::getAnnotationColor(const AnnotColor *color)
 {
 	QString fNam;
 	QString namPrefix = "FromPDF";
@@ -4242,7 +4230,7 @@ void SlaOutputDev::applyMask(PageItem *ite)
 	}
 }
 
-void SlaOutputDev::pushGroup(QString maskName, GBool forSoftMask, GBool alpha, bool inverted)
+void SlaOutputDev::pushGroup(QString maskName, bool forSoftMask, bool alpha, bool inverted)
 {
 	groupEntry gElements;
 	gElements.forSoftMask = forSoftMask;
@@ -4252,23 +4240,23 @@ void SlaOutputDev::pushGroup(QString maskName, GBool f
 	m_groupStack.push(gElements);
 }
 
-QString SlaOutputDev::UnicodeParsedString(GooString *s1)
+QString SlaOutputDev::UnicodeParsedString(const GooString *s1)
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
