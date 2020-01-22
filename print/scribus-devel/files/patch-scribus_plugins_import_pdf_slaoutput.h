--- scribus/plugins/import/pdf/slaoutput.h.orig	2020-01-18 17:22:17 UTC
+++ scribus/plugins/import/pdf/slaoutput.h
@@ -229,7 +229,7 @@ class SlaOutputDev : public OutputDev (public)
 
 	//----- image drawing
 	void drawImageMask(GfxState *state, Object *ref, Stream *str, int width, int height, GBool invert, GBool interpolate, GBool inlineImg) override;
-	void drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, GBool interpolate, int *maskColors, GBool inlineImg) override;
+	void drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, GBool interpolate, const int *maskColors, GBool inlineImg) override;
 	void drawSoftMaskedImage(GfxState *state, Object *ref, Stream *str,
 				   int width, int height,
 				   GfxImageColorMap *colorMap,
@@ -261,8 +261,8 @@ class SlaOutputDev : public OutputDev (public)
 	//----- text drawing
 	void  beginTextObject(GfxState *state) override;
 	void  endTextObject(GfxState *state) override;
-	void  drawChar(GfxState *state, double /*x*/, double /*y*/, double /*dx*/, double /*dy*/, double /*originX*/, double /*originY*/, CharCode /*code*/, int /*nBytes*/, Unicode * /*u*/, int /*uLen*/) override;
-	GBool beginType3Char(GfxState * /*state*/, double /*x*/, double /*y*/, double /*dx*/, double /*dy*/, CharCode /*code*/, Unicode * /*u*/, int /*uLen*/) override;
+	void  drawChar(GfxState *state, double /*x*/, double /*y*/, double /*dx*/, double /*dy*/, double /*originX*/, double /*originY*/, CharCode /*code*/, int /*nBytes*/, const Unicode * /*u*/, int /*uLen*/) override;
+	GBool beginType3Char(GfxState * /*state*/, double /*x*/, double /*y*/, double /*dx*/, double /*dy*/, CharCode /*code*/, const Unicode * /*u*/, int /*uLen*/) override;
 	void  endType3Char(GfxState * /*state*/) override;
 	void  type3D0(GfxState * /*state*/, double /*wx*/, double /*wy*/) override;
 	void  type3D1(GfxState * /*state*/, double /*wx*/, double /*wy*/, double /*llx*/, double /*lly*/, double /*urx*/, double /*ury*/) override;
@@ -282,7 +282,7 @@ class SlaOutputDev : public OutputDev (public)
 	void getPenState(GfxState *state);
 	QString getColor(GfxColorSpace *color_space, POPPLER_CONST_070 GfxColor *color, int *shade);
 	QString getAnnotationColor(const AnnotColor *color);
-	QString convertPath(GfxPath *path);
+	QString convertPath(const GfxPath *path);
 	int getBlendMode(GfxState *state);
 	void applyMask(PageItem *ite);
 	void pushGroup(const QString& maskName = "", GBool forSoftMask = gFalse, GBool alpha = gFalse, bool inverted = false);
