--- scribus/plugins/import/pdf/slaoutput.h.orig	2021-03-09 15:40:35 UTC
+++ scribus/plugins/import/pdf/slaoutput.h
@@ -196,7 +196,11 @@ class SlaOutputDev : public OutputDev (public)
 	void stroke(GfxState *state) override;
 	void fill(GfxState *state) override;
 	void eoFill(GfxState *state) override;
+ #if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(21, 3, 0)
+	bool tilingPatternFill(GfxState *state, Gfx *gfx, Catalog *cat, GfxTilingPattern *tPat, const double *mat, int x0, int y0, int x1, int y1, double xStep, double yStep) override;
+#else
 	GBool tilingPatternFill(GfxState *state, Gfx *gfx, Catalog *cat, Object *str, POPPLER_CONST_070 double *pmat, int paintType, int tilingType, Dict *resDict, POPPLER_CONST_070 double *mat, POPPLER_CONST_070 double *bbox, int x0, int y0, int x1, int y1, double xStep, double yStep) override;
+#endif
 	GBool functionShadedFill(GfxState * /*state*/, GfxFunctionShading * /*shading*/) override { qDebug() << "Function Shaded Fill";  return gFalse; }
 	GBool axialShadedFill(GfxState *state, GfxAxialShading *shading, double tMin, double tMax) override;
 	GBool axialShadedSupportExtend(GfxState *state, GfxAxialShading *shading)  override { return (shading->getExtend0() == shading->getExtend1()); }
