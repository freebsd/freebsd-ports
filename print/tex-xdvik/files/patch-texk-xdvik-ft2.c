--- texk/xdvik/ft2.c.orig	2015-07-19 18:49:42 UTC
+++ texk/xdvik/ft2.c
@@ -0,0 +1,285 @@
+/*========================================================================*\
+
+Copyright (C) 2002-2013 The Xdvik-jp project http://xdvi.sourceforge.jp/
+
+Permission is hereby granted, free of charge, to any person obtaining a copy
+of this software and associated documentation files (the "Software"), to
+deal in the Software without restriction, including without limitation the
+rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
+sell copies of the Software, and to permit persons to whom the Software is
+furnished to do so, subject to the following conditions:
+
+The above copyright notice and this permission notice shall be included in
+all copies or substantial portions of the Software.
+
+THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
+IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
+FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
+THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
+OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
+ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
+OTHER DEALINGS IN THE SOFTWARE.
+
+NOTE:
+This module is based on prior work, as noted in the modification history
+in README.xdvik-jp and changelog.
+
+\*========================================================================*/
+
+#include "xdvi-config.h"
+#include "xdvi.h"
+#include <stdio.h>
+#include <stdlib.h>
+
+#ifdef	PTEX
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_SYNTHESIS_H
+
+#include "kpathsea/tex-file.h"
+#include "ft2.h"
+#include "dvi-init.h"
+#include "util.h"
+#include "ptexmap.h"
+#include "ft2vert.h"
+#include "fontconfig.h"
+#include "encodings.h"
+#include "AJ16.c"
+
+static struct jisv_st {
+    int low, hi;
+} jisv[] = {
+    /* converted from CMap 'V' */
+    /* sed -e '/^</!d' -e 's|<\(....\)> <\(....\)>.*|  { 0x\1, 0x\2 },|' < V */
+    { 0x2122, 0x2123 },
+    { 0x2131, 0x2132 },
+    { 0x213c, 0x213e },
+    { 0x2141, 0x2145 },
+    { 0x214a, 0x215b },
+    { 0x2161, 0x2161 },
+    { 0x2421, 0x2421 },
+    { 0x2423, 0x2423 },
+    { 0x2425, 0x2425 },
+    { 0x2427, 0x2427 },
+    { 0x2429, 0x2429 },
+    { 0x2443, 0x2443 },
+    { 0x2463, 0x2463 },
+    { 0x2465, 0x2465 },
+    { 0x2467, 0x2467 },
+    { 0x246e, 0x246e },
+    { 0x2521, 0x2521 },
+    { 0x2523, 0x2523 },
+    { 0x2525, 0x2525 },
+    { 0x2527, 0x2527 },
+    { 0x2529, 0x2529 },
+    { 0x2543, 0x2543 },
+    { 0x2563, 0x2563 },
+    { 0x2565, 0x2565 },
+    { 0x2567, 0x2567 },
+    { 0x256e, 0x256e },
+    { 0x2575, 0x2576 },
+};
+
+Boolean is_jis_vertical(int jis)
+{
+    size_t l,r,m;
+
+    l=0; r=sizeof(jisv)/sizeof(*jisv)-1;
+    while (l<r) {
+	m=(l+r)/2;
+	if   (jisv[m].hi < jis) l=m+1;
+	else r=m;
+    }
+    if (jisv[l].low <= jis && jis <= jisv[l].hi) return True;
+    return False;
+}
+
+static FT_Library  library = NULL;
+
+static int ft_fonts_num = 0;
+static int ft_fonts_max = 0;
+static struct ft_font {
+    FT_Face face;
+    short   height;
+    short   width;
+    short   ascend;
+    int     encoding;
+    Boolean bold;
+    struct ft2vert_st *ft2vert;
+} *ft_fonts;
+
+static void ft2_init(void)
+{
+    int ft_error = FT_Init_FreeType( &library );
+    if (ft_error != 0) {
+	XDVI_WARNING(( stderr, "FreeType2: Initialization error.\n" ));
+	exit(100);
+    }
+}
+
+int ft2_open_font(struct ptexmap *map)
+{
+    int ft_error;
+    char *fontpath = get_ptex_font_pathname(map->font_filename);
+    struct ft_font *font;
+
+    if (library == NULL) ft2_init();
+    if (map->ft2_index >= 0) {  /* already opened */
+	return map->ft2_index;
+    }
+
+    if (ft_fonts_num == ft_fonts_max) {
+	if (ft_fonts_max == 0) ft_fonts_max = 8;
+	else                   ft_fonts_max *= 2;
+	ft_fonts = xrealloc(ft_fonts, sizeof(ft_fonts[0]) * ft_fonts_max);
+    }
+    font = &ft_fonts[ft_fonts_num];
+
+    memset(font, 0, sizeof(*font));
+    ft_error = FT_New_Face(library, fontpath, map->face_index, &font->face);
+    free(fontpath);
+    if (ft_error != 0) {
+	XDVI_WARNING(( stderr, "FreeType2: Open Font Error (%s).  "
+		       "Error code = %d \n", fontpath, ft_error ));
+    } else {
+	font->encoding = map->encoding;
+	if (map->encoding == ENC_JIS_V || map->encoding == ENC_UNICODE_V) {
+	    font->ft2vert = ft2vert_init(font->face);
+	}
+	font->bold = (map->variant & VAR_BOLD);
+	if (map->variant & VAR_ITALIC) map->slant = 0.3;
+	if (map->extend != 1.0 || map->slant != 0.0) {
+	    /* for debug (attention upper if condition) */
+	    /* FT_Vector vector = { 30 * (1<<6), -30 * (1<<6) }; */
+
+	    /* t1_modify_fm() in tetex-src-3.0/texk/dvipsk/writet1.c */
+	    FT_Matrix matrix;
+	    matrix.xx = (int)(map->extend * (1<<16));
+	    matrix.xy = (int)(map->extend * map->slant * (1<<16));
+	    matrix.yx = 0;
+	    matrix.yy = 1<<16;
+	    FT_Set_Transform( font->face, &matrix, 0 );
+	    /* TODO: vertical font */
+	}
+    }
+    return (map->ft2_index = ft_fonts_num++);
+}
+
+static FT_UInt glyph_index(const int char_code, struct ft_font *font)
+{
+    FT_UInt i = char_code;  /* JIS or UNICODE or GID */
+
+    if (font->encoding == ENC_JIS_H || font->encoding == ENC_JIS_V) {
+	i = jis2unicode(i);
+    }
+    else if (font->encoding == ENC_AJ16_H || font->encoding == ENC_AJ16_V) {
+	i = AJ162uni(i);
+    }
+    if (font->encoding != ENC_IDENTITY) { /* unicode -> gid */
+	i = FT_Get_Char_Index(font->face, i);
+    }
+    if ((font->encoding == ENC_JIS_V && is_jis_vertical(char_code)) ||
+	font->encoding == ENC_UNICODE_V || font->encoding == ENC_AJ16_V) {
+      if (font->ft2vert != NULL) i = ft2vert_get_gid(font->ft2vert, i);
+    }
+    return i;
+}
+
+static void glyph_to_bitmap(struct bitmap *bm, FT_GlyphSlot g, int ascend)
+{
+    int x, xmax, xshift;
+    int y, ymax, yoffset;
+    unsigned char *src, *dst;
+
+    dst  = bm->bits;
+    src  = g->bitmap.buffer;
+    xmax = g->bitmap.pitch;
+    ymax = g->bitmap.rows;
+
+    if ( g->bitmap_left >= 0 ) {  /* to right */
+	if ( g->bitmap_left % 8 != 0 ) xmax++;
+	if ( xmax > bm->bytes_wide - g->bitmap_left/8 ) {
+	    xmax = bm->bytes_wide - g->bitmap_left/8;
+	}
+	dst   += g->bitmap_left / 8;
+	xshift = g->bitmap_left % 8;
+    } else { /* to left */
+	xmax  -=   (-g->bitmap_left) / 8;
+	src   +=   (-g->bitmap_left) / 8;
+	xshift = -((-g->bitmap_left) % 8);
+	if ( xmax > bm->bytes_wide ) xmax = bm->bytes_wide;
+    } /* We love plus % plus, we hate minus % plus. */
+    assert( xmax <= bm->bytes_wide );
+
+    yoffset = ascend - g->bitmap_top;
+    if ( yoffset >= 0 ) { /* to down */
+	dst += yoffset * bm->bytes_wide;
+	if (ymax > bm->h - yoffset) ymax = bm->h - yoffset;
+    } else { /* to up */
+	src  += (-yoffset) * g->bitmap.pitch;
+	ymax -= (-yoffset);
+	if ( ymax > bm->h ) ymax = bm->h;
+    }
+
+    if ( xmax<=0 || ymax<=0 ) return;
+    for ( y=0; y<ymax; y++ ) {
+	if ( xshift == 0 ) {
+	    for ( x=0; x<xmax; x++ ) *dst++ = *src++;
+	} else if ( xshift > 0 ) {
+	    for ( x=0; x<xmax-1; x++ ) {
+		*dst++ |= *src   >> xshift;
+		*dst   |= *src++ << (8 - xshift);
+	    }
+	    dst++; src++;
+	} else {
+	    for ( x=0; x<xmax-1; x++ ) {
+		*dst   |= *src++ << -xshift;
+		*dst++ |= *src   >> (8 + xshift);
+	    }
+	    *dst++ |= *src++ << -xshift;
+	}
+	src += g->bitmap.pitch - xmax;
+	dst += bm->bytes_wide  - xmax;
+    }
+    dst -= bm->bytes_wide - xmax;
+    /* fprintf(stderr, "dst-bm->bits=%d, ", (char*)dst-(char*)bm->bits); */
+    /* fprintf(stderr, "size=%d\n", bm->bytes_wide * bm->h); */
+    assert((char*)dst <= (char*)bm->bits + bm->bytes_wide * bm->h);
+}
+
+int ft2_get_bitmap(long char_code, int ft2_index, struct bitmap *bm)
+{
+    struct ft_font *font = &ft_fonts[ft2_index];
+    FT_Face face = font->face;
+
+    clear_bitmap(bm);
+    if (face == NULL) return 0;
+
+    if ( font->width != bm->w || font->height != bm->h ) {
+	FT_Set_Pixel_Sizes( face, bm->w, bm->h );
+	font->width  = bm->w;
+	font->height = bm->h;
+	font->ascend =
+	    bm->h * face->ascender
+	    /  (face->ascender - face->descender);
+    }
+
+    if ( FT_Load_Glyph( face, glyph_index(char_code,font), FT_LOAD_DEFAULT )
+	 != 0 ) {
+	XDVI_WARNING(( stderr, "FreeType2: Failed in load glyph. "
+		       "(char=0x%X)\n", char_code ));
+	fill_bitmap(bm);
+	return 0;
+    }
+    if ( font->bold ) FT_GlyphSlot_Embolden( face->glyph );
+    if ( FT_Render_Glyph( face->glyph, FT_RENDER_MODE_MONO ) != 0 ) {
+	XDVI_WARNING(( stderr, "FreeType2: Failed in render glyph. "
+		       "(char=0x%X)\n", char_code ));
+	fill_bitmap(bm);
+	return 0;
+    }
+    glyph_to_bitmap( bm, face->glyph, font->ascend );
+    return font->ascend;
+}
+
+#endif	/* PTEX */
