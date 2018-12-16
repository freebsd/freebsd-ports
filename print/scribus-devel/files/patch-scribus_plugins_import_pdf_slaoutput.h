--- scribus/plugins/import/pdf/slaoutput.h.orig	2018-12-11 13:04:07 UTC
+++ scribus/plugins/import/pdf/slaoutput.h
@@ -61,9 +61,9 @@ class LinkSubmitForm: public LinkAction (public)
 	// Destructor.
 	virtual ~LinkSubmitForm();
 	// Was the LinkImportData created successfully?
-	virtual GBool isOk() { return fileName != NULL; }
+	virtual bool isOk() const { return fileName != NULL; }
 	// Accessors.
-	virtual LinkActionKind getKind() { return actionUnknown; }
+	virtual LinkActionKind getKind() const { return actionUnknown; }
 	GooString *getFileName() { return fileName; }
 	int getFlags() { return m_flags; }
 private:
@@ -83,9 +83,9 @@ class LinkImportData: public LinkAction (public)
 	// Destructor.
 	virtual ~LinkImportData();
 	// Was the LinkImportData created successfully?
-	virtual GBool isOk() { return fileName != NULL; }
+	virtual bool isOk() const { return fileName != NULL; }
 	// Accessors.
-	virtual LinkActionKind getKind() { return actionUnknown; }
+	virtual LinkActionKind getKind() const { return actionUnknown; }
 	GooString *getFileName() { return fileName; }
 private:
 	GooString *fileName;		// file name
@@ -98,9 +98,9 @@ class SplashOutFontFileID: public SplashFontFileID
 {
 public:
 
-	SplashOutFontFileID(Ref *rA) { r = *rA; }
+	SplashOutFontFileID(const Ref *rA) { r = *rA; }
 	~SplashOutFontFileID() {}
-	GBool matches(SplashFontFileID *id)
+	bool matches(SplashFontFileID *id)
 	{
 		return ((SplashOutFontFileID *)id)->r.num == r.num && ((SplashOutFontFileID *)id)->r.gen == r.gen;
 	}
@@ -115,18 +115,18 @@ class AnoOutputDev : public OutputDev
 public:
 	AnoOutputDev(ScribusDoc* doc, QStringList *importedColors);
 	virtual ~AnoOutputDev();
-	GBool isOk() { return gTrue; }
-	virtual GBool upsideDown() { return gTrue; }
-	virtual GBool useDrawChar() { return gFalse; }
-	virtual GBool interpretType3Chars() { return gFalse; }
-	virtual GBool useTilingPatternFill() { return gFalse; }
-	virtual GBool useShadedFills(int type) { return gFalse; }
-	virtual GBool useFillColorStop() { return gFalse; }
-	virtual GBool useDrawForm() { return gFalse; }
+	bool isOk() { return true; }
+	virtual bool upsideDown() { return true; }
+	virtual bool useDrawChar() { return false; }
+	virtual bool interpretType3Chars() { return false; }
+	virtual bool useTilingPatternFill() { return false; }
+	virtual bool useShadedFills(int type) { return false; }
+	virtual bool useFillColorStop() { return false; }
+	virtual bool useDrawForm() { return false; }
 	virtual void stroke(GfxState *state);
 	virtual void eoFill(GfxState *state);
 	virtual void fill(GfxState *state);
-	virtual void drawString(GfxState *state, GooString *s);
+	virtual void drawString(GfxState *state, const GooString *s);
 
 	QString CurrColorText;
 	QString CurrColorFill;
@@ -135,7 +135,7 @@ class AnoOutputDev : public OutputDev
 	GooString *m_fontName;
 	GooString *m_itemText;
 private:
-	QString getColor(GfxColorSpace *color_space, GfxColor *color, int *shade);
+	QString getColor(GfxColorSpace *color_space, const GfxColor *color, int *shade);
 	ScribusDoc* m_doc;
 	QStringList *m_importedColors;
 };
@@ -148,7 +148,7 @@ class SlaOutputDev : public OutputDev (public)
 	virtual ~SlaOutputDev();
 	LinkAction* SC_getAction(AnnotWidget *ano);
 	LinkAction* SC_getAdditionalAction(const char *key, AnnotWidget *ano);
-	static GBool annotations_callback(Annot *annota, void *user_data);
+	static bool annotations_callback(Annot *annota, void *user_data);
 	bool handleTextAnnot(Annot* annota, double xCoor, double yCoor, double width, double height);
 	bool handleLinkAnnot(Annot* annota, double xCoor, double yCoor, double width, double height);
 	bool handleWidgetAnnot(Annot* annota, double xCoor, double yCoor, double width, double height);
@@ -156,15 +156,15 @@ class SlaOutputDev : public OutputDev (public)
 	void handleActions(PageItem* ite, AnnotWidget *ano);
 	void startDoc(PDFDoc *doc, XRef *xrefA, Catalog *catA);
 
-	GBool isOk() { return gTrue; }
-	virtual GBool upsideDown() { return gTrue; }
-	virtual GBool useDrawChar() { return gTrue; }
-	virtual GBool interpretType3Chars() { return gTrue; }
-	virtual GBool useTilingPatternFill() { return gTrue; }
-	virtual GBool useShadedFills(int type) { return type <= 7; }
-	virtual GBool useFillColorStop() { return gTrue; }
-	virtual GBool useDrawForm() { return gFalse; }
-//	virtual GBool needClipToCropBox() { return gTrue; }
+	bool isOk() { return true; }
+	virtual bool upsideDown() { return true; }
+	virtual bool useDrawChar() { return true; }
+	virtual bool interpretType3Chars() { return true; }
+	virtual bool useTilingPatternFill() { return true; }
+	virtual bool useShadedFills(int type) { return type <= 7; }
+	virtual bool useFillColorStop() { return true; }
+	virtual bool useDrawForm() { return false; }
+//	virtual bool needClipToCropBox() { return true; }
 	virtual void startPage(int pageNum, GfxState *, XRef *);
 	virtual void endPage();
 	// graphics state
@@ -175,30 +175,30 @@ class SlaOutputDev : public OutputDev (public)
 	virtual void stroke(GfxState *state);
 	virtual void fill(GfxState *state);
 	virtual void eoFill(GfxState *state);
-	GBool tilingPatternFill(GfxState *state, Gfx *gfx, Catalog *cat, Object *str, double *pmat, int paintType, int tilingType, Dict *resDict, double *mat, double *bbox, int x0, int y0, int x1, int y1, double xStep, double yStep);
-	virtual GBool functionShadedFill(GfxState * /*state*/, GfxFunctionShading * /*shading*/) { qDebug() << "Function Shaded Fill";  return gFalse; }
-	virtual GBool axialShadedFill(GfxState *state, GfxAxialShading *shading, double tMin, double tMax);
-	virtual GBool axialShadedSupportExtend(GfxState *state, GfxAxialShading *shading) { return (shading->getExtend0() == shading->getExtend1()); }
-	virtual GBool radialShadedFill(GfxState *state, GfxRadialShading *shading, double sMin, double sMax);
-	virtual GBool radialShadedSupportExtend(GfxState *state, GfxRadialShading *shading) { return (shading->getExtend0() == shading->getExtend1()); }
-	virtual GBool gouraudTriangleShadedFill(GfxState *state, GfxGouraudTriangleShading *shading);
-	virtual GBool patchMeshShadedFill(GfxState *state, GfxPatchMeshShading *shading);
+	bool tilingPatternFill(GfxState *state, Gfx *gfx, Catalog *cat, Object *str, double *pmat, int paintType, int tilingType, Dict *resDict, double *mat, double *bbox, int x0, int y0, int x1, int y1, double xStep, double yStep);
+	virtual bool functionShadedFill(GfxState * /*state*/, GfxFunctionShading * /*shading*/) { qDebug() << "Function Shaded Fill";  return false; }
+	virtual bool axialShadedFill(GfxState *state, GfxAxialShading *shading, double tMin, double tMax);
+	virtual bool axialShadedSupportExtend(GfxState *state, GfxAxialShading *shading) { return (shading->getExtend0() == shading->getExtend1()); }
+	virtual bool radialShadedFill(GfxState *state, GfxRadialShading *shading, double sMin, double sMax);
+	virtual bool radialShadedSupportExtend(GfxState *state, GfxRadialShading *shading) { return (shading->getExtend0() == shading->getExtend1()); }
+	virtual bool gouraudTriangleShadedFill(GfxState *state, GfxGouraudTriangleShading *shading);
+	virtual bool patchMeshShadedFill(GfxState *state, GfxPatchMeshShading *shading);
 	//----- path clipping
 	virtual void clip(GfxState *state);
 	virtual void eoClip(GfxState *state);
 	virtual void clipToStrokePath(GfxState * /*state*/) { qDebug() << "Clip to StrokePath"; }
-	virtual GBool deviceHasTextClip(GfxState *state) { return gFalse; }
+	virtual bool deviceHasTextClip(GfxState *state) { return false; }
 
   // If current colorspace is pattern,
   // does this device support text in pattern colorspace?
-	virtual GBool supportTextCSPattern(GfxState *state)
+	virtual bool supportTextCSPattern(GfxState *state)
 	{
 		return state->getFillColorSpace()->getMode() == csPattern;
 	}
 
   // If current colorspace is pattern,
   // need this device special handling for masks in pattern colorspace?
-	virtual GBool fillMaskCSPattern(GfxState * state)
+	virtual bool fillMaskCSPattern(GfxState * state)
 	{
 		return state->getFillColorSpace()->getMode() == csPattern;
 	}
@@ -206,36 +206,36 @@ class SlaOutputDev : public OutputDev (public)
 	virtual void endMaskClip(GfxState *state) { qDebug() << "End Mask Clip"; }
 
   //----- grouping operators
-	virtual void beginMarkedContent(char *name, Dict *properties);
-	virtual void beginMarkedContent(char *name, Object *dictRef);
+	virtual void beginMarkedContent(const char *name, Dict *properties);
+	virtual void beginMarkedContent(const char *name, Object *dictRef);
 	virtual void endMarkedContent(GfxState *state);
-	virtual void markPoint(char *name);
-	virtual void markPoint(char *name, Dict *properties);
+	virtual void markPoint(const char *name);
+	virtual void markPoint(const char *name, Dict *properties);
 	//----- image drawing
-	virtual void drawImageMask(GfxState *state, Object *ref, Stream *str, int width, int height, GBool invert, GBool interpolate, GBool inlineImg);
-	virtual void drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, GBool interpolate, int *maskColors, GBool inlineImg);
+	virtual void drawImageMask(GfxState *state, Object *ref, Stream *str, int width, int height, bool invert, bool interpolate, bool inlineImg);
+	virtual void drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, bool interpolate, int *maskColors, bool inlineImg);
 	virtual void drawSoftMaskedImage(GfxState *state, Object *ref, Stream *str,
 				   int width, int height,
 				   GfxImageColorMap *colorMap,
-				   GBool interpolate,
+				   bool interpolate,
 				   Stream *maskStr,
 				   int maskWidth, int maskHeight,
 				   GfxImageColorMap *maskColorMap,
-				   GBool maskInterpolate);
+				   bool maskInterpolate);
 
 	virtual void drawMaskedImage(GfxState *state, Object *ref, Stream *str,
 				   int width, int height,
 				   GfxImageColorMap *colorMap,
-				   GBool interpolate,
+				   bool interpolate,
 				   Stream *maskStr,
 				   int maskWidth, int maskHeight,
-				   GBool maskInvert, GBool maskInterpolate); // { qDebug() << "Draw Masked Image"; }
+				   bool maskInvert, bool maskInterpolate); // { qDebug() << "Draw Masked Image"; }
 
 	//----- transparency groups and soft masks
-	virtual void beginTransparencyGroup(GfxState *state, double *bbox, GfxColorSpace * /*blendingColorSpace*/, GBool /*isolated*/, GBool /*knockout*/, GBool /*forSoftMask*/);
+	virtual void beginTransparencyGroup(GfxState *state, double *bbox, GfxColorSpace * /*blendingColorSpace*/, bool /*isolated*/, bool /*knockout*/, bool /*forSoftMask*/);
 	virtual void paintTransparencyGroup(GfxState *state, double *bbox);
 	virtual void endTransparencyGroup(GfxState *state);
-	virtual void setSoftMask(GfxState * /*state*/, double * /*bbox*/, GBool /*alpha*/, Function * /*transferFunc*/, GfxColor * /*backdropColor*/);
+	virtual void setSoftMask(GfxState * /*state*/, const double * /*bbox*/, bool /*alpha*/, Function * /*transferFunc*/, GfxColor * /*backdropColor*/);
 	virtual void clearSoftMask(GfxState * /*state*/);
 
 	virtual void updateFillColor(GfxState *state);
@@ -245,7 +245,7 @@ class SlaOutputDev : public OutputDev (public)
 	virtual void beginTextObject(GfxState *state);
 	virtual void endTextObject(GfxState *state);
 	virtual void drawChar(GfxState *state, double /*x*/, double /*y*/, double /*dx*/, double /*dy*/, double /*originX*/, double /*originY*/, CharCode /*code*/, int /*nBytes*/, Unicode * /*u*/, int /*uLen*/);
-	virtual GBool beginType3Char(GfxState * /*state*/, double /*x*/, double /*y*/, double /*dx*/, double /*dy*/, CharCode /*code*/, Unicode * /*u*/, int /*uLen*/);
+	virtual bool beginType3Char(GfxState * /*state*/, double /*x*/, double /*y*/, double /*dx*/, double /*dy*/, CharCode /*code*/, Unicode * /*u*/, int /*uLen*/);
 	virtual void endType3Char(GfxState * /*state*/);
 	virtual void type3D0(GfxState * /*state*/, double /*wx*/, double /*wy*/);
 	virtual void type3D1(GfxState * /*state*/, double /*wx*/, double /*wy*/, double /*llx*/, double /*lly*/, double /*urx*/, double /*ury*/);
@@ -260,13 +260,13 @@ class SlaOutputDev : public OutputDev (public)
 
 private:
 	void getPenState(GfxState *state);
-	QString getColor(GfxColorSpace *color_space, GfxColor *color, int *shade);
-	QString getAnnotationColor(AnnotColor *color);
+	QString getColor(GfxColorSpace *color_space, const GfxColor *color, int *shade);
+	QString getAnnotationColor(const AnnotColor *color);
 	QString convertPath(GfxPath *path);
 	int getBlendMode(GfxState *state);
 	void applyMask(PageItem *ite);
-	void pushGroup(QString maskName = "", GBool forSoftMask = gFalse, GBool alpha = gFalse, bool inverted = false);
-	QString UnicodeParsedString(GooString *s1);
+	void pushGroup(QString maskName = "", bool forSoftMask = false, bool alpha = false, bool inverted = false);
+	QString UnicodeParsedString(const GooString *s1);
 	bool checkClip();
 	bool pathIsClosed;
 	QString CurrColorFill;
@@ -283,9 +283,9 @@ class SlaOutputDev : public OutputDev (public)
 	struct groupEntry
 	{
 		QList<PageItem*> Items;
-		GBool forSoftMask;
-		GBool isolated;
-		GBool alpha;
+		bool forSoftMask;
+		bool isolated;
+		bool alpha;
 		QString maskName;
 		bool inverted;
 	};
