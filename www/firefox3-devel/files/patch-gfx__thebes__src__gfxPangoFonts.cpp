--- ./gfx/thebes/src/gfxPangoFonts.cpp.orig	2009-12-09 10:17:48.872850998 +0100
+++ ./gfx/thebes/src/gfxPangoFonts.cpp	2009-12-09 10:22:14.745686512 +0100
@@ -56,8 +56,6 @@
 #include "gfxContext.h"
 #include "gfxPlatformGtk.h"
 #include "gfxPangoFonts.h"
-#include "gfxFT2FontBase.h"
-#include "gfxFT2Utils.h"
 #include "gfxFontconfigUtils.h"
 #include "gfxUserFontSet.h"
 
@@ -128,6 +126,21 @@
 #define FC_FULLNAME "fullname"
 #endif
 
+// Rounding and truncation functions for a FreeType fixed point number 
+// (FT26Dot6) stored in a 32bit integer with high 26 bits for the integer
+// part and low 6 bits for the fractional part. 
+#define FLOAT_FROM_26_6(x) ((x) / 64.0)
+#define FLOAT_FROM_16_16(x) ((x) / 65536.0)
+#define ROUND_26_6_TO_INT(x) ((x) >= 0 ?  ((32 + (x)) >> 6) \
+                                       : -((32 - (x)) >> 6))
+// aScale is intended for a 16.16 x/y_scale of an FT_Size_Metrics
+static inline FT_Long
+ScaleRoundDesignUnits(FT_Short aDesignMetric, FT_Fixed aScale)
+{
+    FT_Long fixed26dot6 = FT_MulFix(aDesignMetric, aScale);
+    return ROUND_26_6_TO_INT(fixed26dot6);
+}
+
 static PRFuncPtr
 FindFunctionSymbol(const char *name)
 {
@@ -506,19 +519,84 @@
  * cairo_scaled_font created from an FcPattern.
  */
 
-class gfxFcFont : public gfxFT2FontBase {
+class gfxFcFont : public gfxFont {
 public:
     virtual ~gfxFcFont ();
     static already_AddRefed<gfxFcFont> GetOrMakeFont(FcPattern *aPattern);
 
+    virtual const gfxFont::Metrics& GetMetrics();
+
+    virtual nsString GetUniqueName();
+
+    // Get the glyphID of a space
+    virtual PRUint32 GetSpaceGlyph() {
+        NS_ASSERTION(GetStyle()->size != 0,
+                     "forgot to short-circuit a text run with zero-sized font?");
+        GetMetrics();
+        return mSpaceGlyph;
+    }
+
+    cairo_scaled_font_t *CairoScaledFont() { return mCairoFont; }
+    PRUint32 GetGlyph(PRUint32 aCharCode);
+    void GetGlyphExtents(PRUint32 aGlyph, cairo_text_extents_t* aExtents);
+
 protected:
+    cairo_scaled_font_t *mCairoFont;
+
+    PRUint32 mSpaceGlyph;
+    Metrics mMetrics;
+    PRPackedBool mHasMetrics;
+
     gfxFcFont(cairo_scaled_font_t *aCairoFont,
               gfxFontEntry *aFontEntry, const gfxFontStyle *aFontStyle);
 
+    virtual PRBool SetupCairoFont(gfxContext *aContext);
+
     // key for locating a gfxFcFont corresponding to a cairo_scaled_font
     static cairo_user_data_key_t sGfxFontKey;
 };
 
+class LockedFTFace {
+public:
+    LockedFTFace(gfxFcFont *aFont)
+        : mGfxFont(aFont),
+          mFace(cairo_ft_scaled_font_lock_face(aFont->CairoScaledFont()))
+    {
+    }
+
+    ~LockedFTFace()
+    {
+        if (mFace) {
+            cairo_ft_scaled_font_unlock_face(mGfxFont->CairoScaledFont());
+        }
+    }
+
+    FT_Face get()
+    {
+        return mFace;
+    }
+
+    /**
+     * Get the glyph id for a Unicode character representable by a single
+     * glyph, or return zero if there is no such glyph.  This does no caching,
+     * so you probably want gfxFcFont::GetGlyph.
+     */
+    PRUint32 GetGlyph(PRUint32 aCharCode);
+
+    void GetMetrics(gfxFont::Metrics* aMetrics, PRUint32* aSpaceGlyph);
+
+private:
+    /**
+     * Get extents for a simple character representable by a single glyph.
+     * The return value is the glyph id of that glyph or zero if no such glyph
+     * exists.  aExtents is only set when this returns a non-zero glyph id.
+     */
+    PRUint32 GetCharExtents(char aChar, cairo_text_extents_t* aExtents);
+
+    nsRefPtr<gfxFcFont> mGfxFont;
+    FT_Face mFace;
+};
+
 /**
  * gfxPangoFcFont:
  *
@@ -2029,14 +2107,18 @@
 gfxFcFont::gfxFcFont(cairo_scaled_font_t *aCairoFont,
                      gfxFontEntry *aFontEntry,
                      const gfxFontStyle *aFontStyle)
-    : gfxFT2FontBase(aCairoFont, aFontEntry, aFontStyle)
+    : gfxFont(aFontEntry, aFontStyle),
+      mCairoFont(aCairoFont),
+      mHasMetrics(PR_FALSE)
 {
-    cairo_scaled_font_set_user_data(mScaledFont, &sGfxFontKey, this, NULL);
+    cairo_scaled_font_reference(mCairoFont);
+    cairo_scaled_font_set_user_data(mCairoFont, &sGfxFontKey, this, NULL);
 }
 
 gfxFcFont::~gfxFcFont()
 {
-    cairo_scaled_font_set_user_data(mScaledFont, &sGfxFontKey, NULL, NULL);
+    cairo_scaled_font_set_user_data(mCairoFont, &sGfxFontKey, NULL, NULL);
+    cairo_scaled_font_destroy(mCairoFont);
 }
 
 /* static */ void
@@ -2129,7 +2211,7 @@
         if (!font)
             return NULL;
 
-        gfxFT2LockedFace face(font);
+        LockedFTFace face(font);
         if (!face.get())
             return NULL;
 
@@ -2320,6 +2402,400 @@
     return fontSet;
 }
 
+PRUint32
+gfxFcFont::GetGlyph(PRUint32 aCharCode)
+{
+    // FcFreeTypeCharIndex needs to lock the FT_Face and can end up searching
+    // through all the postscript glyph names in the font.  Therefore use a
+    // lightweight cache, which is stored on the cairo_font_face_t.
+
+    cairo_font_face_t *face =
+        cairo_scaled_font_get_font_face(CairoScaledFont());
+
+    if (cairo_font_face_status(face) != CAIRO_STATUS_SUCCESS)
+        return 0;
+
+    // This cache algorithm and size is based on what is done in
+    // cairo_scaled_font_text_to_glyphs and pango_fc_font_real_get_glyph.  I
+    // think the concept is that adjacent characters probably come mostly from
+    // one Unicode block.  This assumption is probably not so valid with
+    // scripts with large character sets as used for East Asian languages.
+
+    struct CmapCacheSlot {
+        PRUint32 mCharCode;
+        PRUint32 mGlyphIndex;
+    };
+    const PRUint32 kNumSlots = 256;
+    static cairo_user_data_key_t sCmapCacheKey;
+
+    CmapCacheSlot *slots = static_cast<CmapCacheSlot*>
+        (cairo_font_face_get_user_data(face, &sCmapCacheKey));
+
+    if (!slots) {
+        // cairo's caches can keep some cairo_font_faces alive past our last
+        // destroy, so the destroy function (free) for the cache must be
+        // callable from cairo without any assumptions about what other
+        // modules have not been shutdown.
+        slots = static_cast<CmapCacheSlot*>
+            (calloc(kNumSlots, sizeof(CmapCacheSlot)));
+        if (!slots)
+            return 0;
+
+        cairo_status_t status =
+            cairo_font_face_set_user_data(face, &sCmapCacheKey, slots, free);
+        if (status != CAIRO_STATUS_SUCCESS) { // OOM
+            free(slots);
+            return 0;
+        }
+
+        // Invalidate slot 0 by setting its char code to something that would
+        // never end up in slot 0.  All other slots are already invalid
+        // because they have mCharCode = 0 and a glyph for char code 0 will
+        // always be in the slot 0.
+        slots[0].mCharCode = 1;
+    }
+
+    CmapCacheSlot *slot = &slots[aCharCode % kNumSlots];
+    if (slot->mCharCode != aCharCode) {
+        slot->mCharCode = aCharCode;
+        slot->mGlyphIndex = LockedFTFace(this).GetGlyph(aCharCode);
+    }
+
+    return slot->mGlyphIndex;
+}
+
+void
+gfxFcFont::GetGlyphExtents(PRUint32 aGlyph, cairo_text_extents_t* aExtents)
+{
+    NS_PRECONDITION(aExtents != NULL, "aExtents must not be NULL");
+
+    cairo_glyph_t glyphs[1];
+    glyphs[0].index = aGlyph;
+    glyphs[0].x = 0.0;
+    glyphs[0].y = 0.0;
+    // cairo does some caching for us here but perhaps a small gain could be
+    // made by caching more.  It is usually only the advance that is needed,
+    // so caching only the advance could allow many requests to be cached with
+    // little memory use.  Ideally this cache would be merged with
+    // gfxGlyphExtents.
+    cairo_scaled_font_glyph_extents(CairoScaledFont(), glyphs, 1, aExtents);
+}
+
+PRUint32
+LockedFTFace::GetGlyph(PRUint32 aCharCode)
+{
+    if (NS_UNLIKELY(!mFace))
+        return 0;
+
+    // FcFreeTypeCharIndex will search starting from the most recently
+    // selected charmap.  This can cause non-determistic behavior when more
+    // than one charmap supports a character but with different glyphs, as
+    // with older versions of MS Gothic, for example.  Always prefer a Unicode
+    // charmap, if there is one.  (FcFreeTypeCharIndex usually does the
+    // appropriate Unicode conversion, but some fonts have non-Roman glyphs
+    // for FT_ENCODING_APPLE_ROMAN characters.)
+    if (!mFace->charmap || mFace->charmap->encoding != FT_ENCODING_UNICODE) {
+        FT_Select_Charmap(mFace, FT_ENCODING_UNICODE);
+    }
+
+    return FcFreeTypeCharIndex(mFace, aCharCode);
+}
+
+PRUint32
+LockedFTFace::GetCharExtents(char aChar,
+                             cairo_text_extents_t* aExtents)
+{
+    NS_PRECONDITION(aExtents != NULL, "aExtents must not be NULL");
+
+    if (!mFace)
+        return 0;
+
+    FT_UInt gid = mGfxFont->GetGlyph(aChar);
+    if (gid) {
+        mGfxFont->GetGlyphExtents(gid, aExtents);
+    }
+
+    return gid;
+}
+
+// Snap a line to pixels while keeping the center and size of the line as
+// close to the original position as possible.
+//
+// Pango does similar snapping for underline and strikethrough when fonts are
+// hinted, but nsCSSRendering::GetTextDecorationRectInternal always snaps the
+// top and size of lines.  Optimizing the distance between the line and
+// baseline is probably good for the gap between text and underline, but
+// optimizing the center of the line is better for positioning strikethough.
+static void
+SnapLineToPixels(gfxFloat& aOffset, gfxFloat& aSize)
+{
+    gfxFloat snappedSize = PR_MAX(NS_floor(aSize + 0.5), 1.0);
+    // Correct offset for change in size
+    gfxFloat offset = aOffset - 0.5 * (aSize - snappedSize);
+    // Snap offset
+    aOffset = NS_floor(offset + 0.5);
+    aSize = snappedSize;
+}
+
+void
+LockedFTFace::GetMetrics(gfxFont::Metrics* aMetrics, PRUint32* aSpaceGlyph)
+{
+    NS_PRECONDITION(aMetrics != NULL, "aMetrics must not be NULL");
+    NS_PRECONDITION(aSpaceGlyph != NULL, "aSpaceGlyph must not be NULL");
+
+    if (NS_UNLIKELY(!mFace)) {
+        // No face.  This unfortunate situation might happen if the font
+        // file is (re)moved at the wrong time.
+        aMetrics->emHeight = mGfxFont->GetStyle()->size;
+        aMetrics->emAscent = 0.8 * aMetrics->emHeight;
+        aMetrics->emDescent = 0.2 * aMetrics->emHeight;
+        aMetrics->maxAscent = aMetrics->emAscent;
+        aMetrics->maxDescent = aMetrics->maxDescent;
+        aMetrics->maxHeight = aMetrics->emHeight;
+        aMetrics->internalLeading = 0.0;
+        aMetrics->externalLeading = 0.2 * aMetrics->emHeight;
+        aSpaceGlyph = 0;
+        aMetrics->spaceWidth = 0.5 * aMetrics->emHeight;
+        aMetrics->maxAdvance = aMetrics->spaceWidth;
+        aMetrics->aveCharWidth = aMetrics->spaceWidth;
+        aMetrics->zeroOrAveCharWidth = aMetrics->spaceWidth;
+        aMetrics->xHeight = 0.5 * aMetrics->emHeight;
+        aMetrics->underlineSize = aMetrics->emHeight / 14.0;
+        aMetrics->underlineOffset = -aMetrics->underlineSize;
+        aMetrics->strikeoutOffset = 0.25 * aMetrics->emHeight;
+        aMetrics->strikeoutSize = aMetrics->underlineSize;
+        aMetrics->superscriptOffset = aMetrics->xHeight;
+        aMetrics->subscriptOffset = aMetrics->xHeight;
+
+        return;
+    }
+
+    const FT_Size_Metrics& ftMetrics = mFace->size->metrics;
+
+    gfxFloat emHeight;
+    // Scale for vertical design metric conversion: pixels per design unit.
+    gfxFloat yScale;
+    if (FT_IS_SCALABLE(mFace)) {
+        // Prefer FT_Size_Metrics::x_scale to x_ppem as x_ppem does not
+        // have subpixel accuracy.
+        //
+        // FT_Size_Metrics::y_scale is in 16.16 fixed point format.  Its
+        // (fractional) value is a factor that converts vertical metrics from
+        // design units to units of 1/64 pixels, so that the result may be
+        // interpreted as pixels in 26.6 fixed point format.
+        yScale = FLOAT_FROM_26_6(FLOAT_FROM_16_16(ftMetrics.y_scale));
+        emHeight = mFace->units_per_EM * yScale;
+    } else { // Not scalable.
+        // FT_Size_Metrics doc says x_scale is "only relevant for scalable
+        // font formats".
+        gfxFloat emUnit = mFace->units_per_EM;
+        emHeight = ftMetrics.y_ppem;
+        yScale = emHeight / emUnit;
+    }
+
+    TT_OS2 *os2 =
+        static_cast<TT_OS2*>(FT_Get_Sfnt_Table(mFace, ft_sfnt_os2));
+
+    aMetrics->maxAscent = FLOAT_FROM_26_6(ftMetrics.ascender);
+    aMetrics->maxDescent = -FLOAT_FROM_26_6(ftMetrics.descender);
+    aMetrics->maxAdvance = FLOAT_FROM_26_6(ftMetrics.max_advance);
+
+    gfxFloat lineHeight;
+    if (os2 && os2->sTypoAscender) {
+        aMetrics->emAscent = os2->sTypoAscender * yScale;
+        aMetrics->emDescent = -os2->sTypoDescender * yScale;
+        FT_Short typoHeight =
+            os2->sTypoAscender - os2->sTypoDescender + os2->sTypoLineGap;
+        lineHeight = typoHeight * yScale;
+
+        // maxAscent/maxDescent get used for frame heights, and some fonts
+        // don't have the HHEA table ascent/descent set (bug 279032).
+        if (aMetrics->emAscent > aMetrics->maxAscent)
+            aMetrics->maxAscent = aMetrics->emAscent;
+        if (aMetrics->emDescent > aMetrics->maxDescent)
+            aMetrics->maxDescent = aMetrics->emDescent;
+    } else {
+        aMetrics->emAscent = aMetrics->maxAscent;
+        aMetrics->emDescent = aMetrics->maxDescent;
+        lineHeight = FLOAT_FROM_26_6(ftMetrics.height);
+    }
+
+    cairo_text_extents_t extents;
+    *aSpaceGlyph = GetCharExtents(' ', &extents);
+    if (*aSpaceGlyph) {
+        aMetrics->spaceWidth = extents.x_advance;
+    } else {
+        aMetrics->spaceWidth = aMetrics->maxAdvance; // guess
+    }
+
+    aMetrics->zeroOrAveCharWidth = 0.0;
+    if (GetCharExtents('0', &extents)) {
+        aMetrics->zeroOrAveCharWidth = extents.x_advance;
+    }
+
+    // Prefering a measured x over sxHeight because sxHeight doesn't consider
+    // hinting, but maybe the x extents are not quite right in some fancy
+    // script fonts.  CSS 2.1 suggests possibly using the height of an "o",
+    // which would have a more consistent glyph across fonts.
+    if (GetCharExtents('x', &extents) && extents.y_bearing < 0.0) {
+        aMetrics->xHeight = -extents.y_bearing;
+        aMetrics->aveCharWidth = extents.x_advance;
+    } else {
+        if (os2 && os2->sxHeight) {
+            aMetrics->xHeight = os2->sxHeight * yScale;
+        } else {
+            // CSS 2.1, section 4.3.2 Lengths: "In the cases where it is
+            // impossible or impractical to determine the x-height, a value of
+            // 0.5em should be used."
+            aMetrics->xHeight = 0.5 * emHeight;
+        }
+        aMetrics->aveCharWidth = 0.0; // updated below
+    }
+    // aveCharWidth is used for the width of text input elements so be
+    // liberal rather than conservative in the estimate.
+    if (os2 && os2->xAvgCharWidth) {
+        // Round to pixels as this is compared with maxAdvance to guess
+        // whether this is a fixed width font.
+        gfxFloat avgCharWidth =
+            ScaleRoundDesignUnits(os2->xAvgCharWidth, ftMetrics.x_scale);
+        aMetrics->aveCharWidth =
+            PR_MAX(aMetrics->aveCharWidth, avgCharWidth);
+    }
+    aMetrics->aveCharWidth =
+        PR_MAX(aMetrics->aveCharWidth, aMetrics->zeroOrAveCharWidth);
+    if (aMetrics->aveCharWidth == 0.0) {
+        aMetrics->aveCharWidth = aMetrics->spaceWidth;
+    }
+    if (aMetrics->zeroOrAveCharWidth == 0.0) {
+        aMetrics->zeroOrAveCharWidth = aMetrics->aveCharWidth;
+    }
+    // Apparently hinting can mean that max_advance is not always accurate.
+    aMetrics->maxAdvance =
+        PR_MAX(aMetrics->maxAdvance, aMetrics->aveCharWidth);
+
+    // gfxFont::Metrics::underlineOffset is the position of the top of the
+    // underline.
+    //
+    // FT_FaceRec documentation describes underline_position as "the
+    // center of the underlining stem".  This was the original definition
+    // of the PostScript metric, but in the PostScript table of OpenType
+    // fonts the metric is "the top of the underline"
+    // (http://www.microsoft.com/typography/otspec/post.htm), and FreeType
+    // (up to version 2.3.7) doesn't make any adjustment.
+    //
+    // Therefore get the underline position directly from the table
+    // ourselves when this table exists.  Use FreeType's metrics for
+    // other (including older PostScript) fonts.
+    if (mFace->underline_position && mFace->underline_thickness) {
+        aMetrics->underlineSize = mFace->underline_thickness * yScale;
+        TT_Postscript *post = static_cast<TT_Postscript*>
+            (FT_Get_Sfnt_Table(mFace, ft_sfnt_post));
+        if (post && post->underlinePosition) {
+            aMetrics->underlineOffset = post->underlinePosition * yScale;
+        } else {
+            aMetrics->underlineOffset = mFace->underline_position * yScale
+                + 0.5 * aMetrics->underlineSize;
+        }
+    } else { // No underline info.
+        // Imitate Pango.
+        aMetrics->underlineSize = emHeight / 14.0;
+        aMetrics->underlineOffset = -aMetrics->underlineSize;
+    }
+
+    if (os2 && os2->yStrikeoutSize && os2->yStrikeoutPosition) {
+        aMetrics->strikeoutSize = os2->yStrikeoutSize * yScale;
+        aMetrics->strikeoutOffset = os2->yStrikeoutPosition * yScale;
+    } else { // No strikeout info.
+        aMetrics->strikeoutSize = aMetrics->underlineSize;
+        // Use OpenType spec's suggested position for Roman font.
+        aMetrics->strikeoutOffset = emHeight * 409.0 / 2048.0
+            + 0.5 * aMetrics->strikeoutSize;
+    }
+    SnapLineToPixels(aMetrics->strikeoutOffset, aMetrics->strikeoutSize);
+
+    if (os2 && os2->ySuperscriptYOffset) {
+        gfxFloat val = ScaleRoundDesignUnits(os2->ySuperscriptYOffset,
+                                             ftMetrics.y_scale);
+        aMetrics->superscriptOffset = PR_MAX(1.0, val);
+    } else {
+        aMetrics->superscriptOffset = aMetrics->xHeight;
+    }
+    
+    if (os2 && os2->ySubscriptYOffset) {
+        gfxFloat val = ScaleRoundDesignUnits(os2->ySubscriptYOffset,
+                                             ftMetrics.y_scale);
+        // some fonts have the incorrect sign. 
+        val = fabs(val);
+        aMetrics->subscriptOffset = PR_MAX(1.0, val);
+    } else {
+        aMetrics->subscriptOffset = aMetrics->xHeight;
+    }
+
+    aMetrics->maxHeight = aMetrics->maxAscent + aMetrics->maxDescent;
+
+    // Make the line height an integer number of pixels so that lines will be
+    // equally spaced (rather than just being snapped to pixels, some up and
+    // some down).  Layout calculates line height from the emHeight +
+    // internalLeading + externalLeading, but first each of these is rounded
+    // to layout units.  To ensure that the result is an integer number of
+    // pixels, round each of the components to pixels.
+    aMetrics->emHeight = NS_floor(emHeight + 0.5);
+
+    // maxHeight will normally be an integer, but round anyway in case
+    // FreeType is configured differently.
+    aMetrics->internalLeading =
+        NS_floor(aMetrics->maxHeight - aMetrics->emHeight + 0.5);
+
+    // Text input boxes currently don't work well with lineHeight
+    // significantly less than maxHeight (with Verdana, for example).
+    lineHeight = NS_floor(PR_MAX(lineHeight, aMetrics->maxHeight) + 0.5);
+    aMetrics->externalLeading =
+        lineHeight - aMetrics->internalLeading - aMetrics->emHeight;
+
+    // Ensure emAscent + emDescent == emHeight
+    gfxFloat sum = aMetrics->emAscent + aMetrics->emDescent;
+    aMetrics->emAscent = sum > 0.0 ?
+        aMetrics->emAscent * aMetrics->emHeight / sum : 0.0;
+    aMetrics->emDescent = aMetrics->emHeight - aMetrics->emAscent;
+}
+
+const gfxFont::Metrics&
+gfxFcFont::GetMetrics()
+{
+    if (mHasMetrics)
+        return mMetrics;
+
+    if (NS_UNLIKELY(GetStyle()->size <= 0.0)) {
+        new(&mMetrics) gfxFont::Metrics(); // zero initialize
+        mSpaceGlyph = 0;
+    } else {
+        LockedFTFace(this).GetMetrics(&mMetrics, &mSpaceGlyph);
+    }
+
+    SanitizeMetrics(&mMetrics, PR_FALSE);
+
+#if 0
+    //    printf("font name: %s %f\n", NS_ConvertUTF16toUTF8(GetName()).get(), GetStyle()->size);
+    //    printf ("pango font %s\n", pango_font_description_to_string (pango_font_describe (font)));
+
+    fprintf (stderr, "Font: %s\n", NS_ConvertUTF16toUTF8(GetName()).get());
+    fprintf (stderr, "    emHeight: %f emAscent: %f emDescent: %f\n", mMetrics.emHeight, mMetrics.emAscent, mMetrics.emDescent);
+    fprintf (stderr, "    maxAscent: %f maxDescent: %f\n", mMetrics.maxAscent, mMetrics.maxDescent);
+    fprintf (stderr, "    internalLeading: %f externalLeading: %f\n", mMetrics.externalLeading, mMetrics.internalLeading);
+    fprintf (stderr, "    spaceWidth: %f aveCharWidth: %f xHeight: %f\n", mMetrics.spaceWidth, mMetrics.aveCharWidth, mMetrics.xHeight);
+    fprintf (stderr, "    uOff: %f uSize: %f stOff: %f stSize: %f suOff: %f suSize: %f\n", mMetrics.underlineOffset, mMetrics.underlineSize, mMetrics.strikeoutOffset, mMetrics.strikeoutSize, mMetrics.superscriptOffset, mMetrics.subscriptOffset);
+#endif
+
+    mHasMetrics = PR_TRUE;
+    return mMetrics;
+}
+
+nsString
+gfxFcFont::GetUniqueName()
+{
+    return GetName();
+}
+
 /**
  ** gfxTextRun
  * 
@@ -2637,6 +3113,47 @@
     return scaledFont;
 }
 
+PRBool
+gfxFcFont::SetupCairoFont(gfxContext *aContext)
+{
+    cairo_t *cr = aContext->GetCairo();
+
+    // The scaled font ctm is not relevant right here because
+    // cairo_set_scaled_font does not record the scaled font itself, but
+    // merely the font_face, font_matrix, font_options.  The scaled_font used
+    // for the target can be different from the scaled_font passed to
+    // cairo_set_scaled_font.  (Unfortunately we have measured only for an
+    // identity ctm.)
+    cairo_scaled_font_t *cairoFont = CairoScaledFont();
+
+    if (cairo_scaled_font_status(cairoFont) != CAIRO_STATUS_SUCCESS) {
+        // Don't cairo_set_scaled_font as that would propagate the error to
+        // the cairo_t, precluding any further drawing.
+        return PR_FALSE;
+    }
+    // Thoughts on which font_options to set on the context:
+    //
+    // cairoFont has been created for screen rendering.
+    //
+    // When the context is being used for screen rendering, we should set
+    // font_options such that the same scaled_font gets used (when the ctm is
+    // the same).  The use of explicit font_options recorded in
+    // CreateScaledFont ensures that this will happen.
+    //
+    // XXXkt: For pdf and ps surfaces, I don't know whether it's better to
+    // remove surface-specific options, or try to draw with the same
+    // scaled_font that was used to measure.  As the same font_face is being
+    // used, its font_options will often override some values anyway (unless
+    // perhaps we remove those from the FcPattern at face creation).
+    //
+    // I can't see any significant difference in printing, irrespective of
+    // what is set here.  It's too late to change things here as measuring has
+    // already taken place.  We should really be measuring with a different
+    // font for pdf and ps surfaces (bug 403513).
+    cairo_set_scaled_font(cr, cairoFont);
+    return PR_TRUE;
+}
+
 static void
 SetupClusterBoundaries(gfxTextRun* aTextRun, const gchar *aUTF8, PRUint32 aUTF8Length,
                        PRUint32 aUTF16Offset, PangoAnalysis *aAnalysis)
