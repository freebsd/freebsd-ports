--- texk/xdvik/ft2vert.c.orig	2015-07-19 18:49:42 UTC
+++ texk/xdvik/ft2vert.c
@@ -0,0 +1,399 @@
+/*
+ * "ft2vert.c"
+ * 
+ * Converter to vertical glyph ID by handling GSUB vrt2/vert feature
+ * requires FreeType-2.1.10 or latter
+ *
+ * (C) 2005 Nobuyuki TSUCHIMURA
+ *
+ * This file is free
+ * software; you can redistribute it and/or modify it under the terms of
+ * the GNU Library General Public License as published by the Free
+ * Software Foundation; either version 2 of the License, or (at your
+ * option) any later version.  This library is distributed in the hope
+ * that it will be useful, but WITHOUT ANY WARRANTY; without even the
+ * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
+ * PURPOSE.  See the GNU Library General Public License for more details.
+ * You should have received a copy of the GNU Library General Public
+ * License along with this library; if not, write to the Free Software
+ * Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
+ *
+ * using such Lookup
+ *   ScriptTag == 'kana'
+ *   DefaultLangSys or LangSysTag == 'JAN '
+ *   FeatureTag == 'vrt2' or 'vert'
+ *
+ * [reference]
+ * http://partners.adobe.com/public/developer/opentype/index_table_formats1.html
+ * http://partners.adobe.com/public/developer/opentype/index_table_formats.html
+ * http://partners.adobe.com/public/developer/opentype/index_tag9.html#vrt2
+ */
+
+#include "xdvi-config.h"
+#include "xdvi.h"
+#ifdef	PTEX
+
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_OPENTYPE_VALIDATE_H
+
+#include <stdio.h>
+#include <stdlib.h>
+#include "ft2vert.h"
+
+#define TAG_KANA FT_MAKE_TAG('k', 'a', 'n', 'a')
+#define TAG_JAN  FT_MAKE_TAG('J', 'A', 'N', ' ')
+#define TAG_VERT FT_MAKE_TAG('v', 'e', 'r', 't')
+#define TAG_VRT2 FT_MAKE_TAG('v', 'r', 't', '2')
+
+#define MALLOC(ptr, size) ptr = xmalloc(sizeof((ptr)[0]) * (size))
+#define BYTE2(p) ((p) += 2, (int)(p)[-2] << 8  | (p)[-1])
+#define BYTE4(p) ((p) += 4, (int)(p)[-4] << 24 | (int)(p)[-3] << 16 | \
+		  (int)(p)[-2] << 8 | (p)[-1])
+
+struct ft2vert_st {
+    int SubTableCount;
+    struct SubTable_st {
+	struct SingleSubst_st {
+	    FT_UInt SubstFormat;
+	    FT_UInt DeltaGlyphID; /* SubstFormat == 1 */
+	    int     GlyphCount;   /* SubstFormat == 2 */
+	    FT_UInt *Substitute;  /* SubstFormat == 2 */
+	} SingleSubst;
+	struct Coverage_st {
+	    FT_UInt CoverageFormat;
+	    int     GlyphCount;   /* CoverageFormat == 1 */
+	    FT_UInt *GlyphArray;  /* CoverageFormat == 1 */
+	    int     RangeCount;   /* CoverageFormat == 2 */
+	    struct  RangeRecord_st
+		   *RangeRecord;  /* CoverageFormat == 2 */
+	} Coverage;
+    } *SubTable;
+    FT_Bytes kanaFeature;
+    FT_Bytes vertLookup;
+    FT_Bytes vrt2Lookup;
+};
+
+struct RangeRecord_st {
+    FT_UInt Start;
+    FT_UInt End;
+};
+
+
+int isInIndex(FT_Bytes s, int index) {
+    int i, count;
+
+    if (s == NULL) return FALSE;
+    count = BYTE2(s);
+    for (i=0; i<count; i++) {
+	if (index == BYTE2(s)) return TRUE;
+    }
+    return FALSE;
+}
+
+
+/**********  Debug ***************/
+
+#ifdef DEBUG
+static FT_Bytes gsub_top;
+
+void print_offset(char *message, const FT_Bytes ptr) {
+    printf("%s offset = %x\n", message, ptr - gsub_top);
+}
+
+char *tag_to_string(FT_Tag tag) {
+    static char str[5];
+    str[0] = tag >> 24;
+    str[1] = tag >> 16;
+    str[2] = tag >> 8;
+    str[3] = tag;
+    return str;
+}
+
+void hex_dump(const FT_Bytes top) {
+    int i, j;
+    FT_Bytes s = top;
+
+    for (j=0; j<100; j++) {
+	printf("%04x : ", j*8);
+	for (i=0; i<8; i++) {
+	    printf("%02x ", s[i+j*8]);
+	}
+	printf("\n");
+    }
+}
+#endif /* DEBUG */
+
+/**********  Lookup part ***************/
+
+void scan_Coverage(struct ft2vert_st *ret, const FT_Bytes top) {
+    int i;
+    FT_Bytes s = top;
+    struct Coverage_st *t;
+
+    t = &ret->SubTable[ret->SubTableCount].Coverage;
+    t->CoverageFormat = BYTE2(s);
+    switch (t->CoverageFormat) {
+    case 1: 
+	t->GlyphCount = BYTE2(s);
+	MALLOC(t->GlyphArray, t->GlyphCount);
+	for (i=0; i<t->GlyphCount; i++) {
+	    t->GlyphArray[i] = BYTE2(s);
+	}
+	break;
+    case 2:
+	t->RangeCount = BYTE2(s);
+	MALLOC(t->RangeRecord, t->RangeCount);
+	for (i=0; i<t->RangeCount; i++) {
+	    t->RangeRecord[i].Start = BYTE2(s);
+	    t->RangeRecord[i].End   = BYTE2(s);
+	    s += 2; /* drop StartCoverageIndex */
+	}
+	break;
+    default:
+	fprintf(stderr, "scan_Coverage: unknown CoverageFormat (%d).",
+		t->CoverageFormat);
+	exit(1);
+    }
+    ret->SubTableCount++;
+}
+
+void scan_SubTable(struct ft2vert_st *ret, const FT_Bytes top) {
+    int i;
+    FT_Bytes s = top;
+    FT_Offset Coverage;
+    struct SingleSubst_st *t;
+
+    t = &ret->SubTable[ret->SubTableCount].SingleSubst;
+    t->SubstFormat = BYTE2(s);
+    Coverage       = BYTE2(s);
+    scan_Coverage(ret, top + Coverage);
+    switch (t->SubstFormat) {
+    case 1: /* SingleSubstFormat1 */
+	t->DeltaGlyphID = BYTE2(s);
+	break;
+    case 2: /* SingleSubstFormat2 */
+	t->GlyphCount   = BYTE2(s);
+	MALLOC(t->Substitute, t->GlyphCount);
+	for (i=0; i<t->GlyphCount; i++) {
+	    t->Substitute[i] = BYTE2(s);
+	}
+	break;
+    default:
+	fprintf(stderr, "scan_SubTable: unknown SubstFormat (%d).",
+		t->SubstFormat);
+	exit(1);
+    }
+}
+
+void scan_Lookup(struct ft2vert_st *ret, const FT_Bytes top) {
+    int i;
+    FT_Bytes s = top;
+    FT_UShort LookupType;
+    FT_UShort LookupFlag;
+    FT_UShort SubTableCount;
+    FT_UShort SubTable;
+
+    LookupType    = BYTE2(s);
+    LookupFlag    = BYTE2(s);
+    SubTableCount = BYTE2(s);
+    SubTable      = BYTE2(s);
+
+    MALLOC(ret->SubTable, SubTableCount);
+    for (i=0; i<SubTableCount; i++) {
+	scan_SubTable(ret, top + SubTable);
+    }
+    if (ret->SubTableCount != SubTableCount) {
+	fprintf(stderr, "warning (scan_Lookup): "
+		"SubTableCount (=%d) is not expected (=%d).\n",
+		ret->SubTableCount, SubTableCount);
+    }
+}
+
+
+void scan_LookupList(struct ft2vert_st *ret, const FT_Bytes top) {
+    int i;
+    FT_Bytes s = top;
+    int LookupCount;
+
+    LookupCount = BYTE2(s);
+
+    for (i=0; i<LookupCount; i++) {
+	FT_Bytes t = top + BYTE2(s);
+	if (isInIndex(ret->vertLookup, i)) {
+	    scan_Lookup(ret, t);
+	}
+    }
+}
+
+/********** Feature part ****************/
+
+void scan_FeatureList(struct ft2vert_st *ret, const FT_Bytes top) {
+    int i;
+    FT_Bytes s = top;
+    int FeatureCount;
+
+    FeatureCount = BYTE2(s);
+
+    for (i=0; i<FeatureCount; i++) {
+	FT_Tag FeatureTag = BYTE4(s);
+	FT_Offset Feature = BYTE2(s);
+	if (!isInIndex(ret->kanaFeature, i)) continue;
+	if (FeatureTag == TAG_VERT) {
+	    ret->vertLookup = top + Feature + 2;
+	} else if (FeatureTag == TAG_VRT2) {
+	    ret->vrt2Lookup = top + Feature + 2;
+	}
+    }
+}
+
+/********** Script part ****************/
+
+void scan_LangSys(struct ft2vert_st *ret, const FT_Bytes top) {
+    if (ret->kanaFeature == NULL) ret->kanaFeature = top + 4;
+}
+
+void scan_Script(struct ft2vert_st *ret, const FT_Bytes top) {
+    int i;
+    FT_Bytes s = top;
+    FT_Offset DefaultLangSys;
+    int LangSysCount;
+
+    DefaultLangSys = BYTE2(s);
+    if (DefaultLangSys != 0) {
+	scan_LangSys(ret, top + DefaultLangSys);
+    }
+    LangSysCount = BYTE2(s);
+
+    for (i=0; i<LangSysCount; i++) {
+	FT_Tag LangSysTag = BYTE4(s);
+	FT_Bytes t = top + BYTE2(s);
+	if (LangSysTag == TAG_JAN) {
+	    scan_LangSys(ret, t);
+	}
+    }
+}
+
+void scan_ScriptList(struct ft2vert_st *ret, const FT_Bytes top) {
+    int i;
+    FT_Bytes s = top;
+    int ScriptCount;
+
+    ScriptCount = BYTE2(s);
+
+    for (i=0; i<ScriptCount; i++) {
+	FT_Tag ScriptTag = BYTE4(s);
+	FT_Bytes t = top + BYTE2(s);
+	if (ScriptTag == TAG_KANA) {
+	    scan_Script(ret, t);
+	}
+    }
+}
+
+/********** header part *****************/
+
+void scan_GSUB_Header(struct ft2vert_st *ret, const FT_Bytes top) {
+    FT_Bytes s = top;
+    FT_Fixed  Version;
+    FT_Offset ScriptList;
+    FT_Offset FeatureList;
+    FT_Offset LookupList;
+
+#ifdef DEBUG
+    gsub_top    = top;
+#endif /* DEBUG */
+    Version     = BYTE4(s);
+    ScriptList  = BYTE2(s);
+    FeatureList = BYTE2(s);
+    LookupList  = BYTE2(s);
+
+    if (Version != 0x00010000) {
+	fprintf(stderr, "warning: GSUB Version (=%.1f) is not 1.0\n",
+		(double)Version / 0x10000);
+    }
+
+    scan_ScriptList (ret, top + ScriptList);
+    scan_FeatureList(ret, top + FeatureList);
+    /* vrt2 has higher priority over vert */
+    if (ret->vrt2Lookup != NULL) ret->vertLookup = ret->vrt2Lookup;
+    scan_LookupList (ret, top + LookupList);
+}
+
+struct ft2vert_st *ft2vert_init(FT_Face face) {
+    struct ft2vert_st *ret;
+    int ft_error;
+    FT_Bytes dummy, GSUB_table;
+
+    MALLOC(ret, 1);
+    ret->SubTableCount = 0;
+    ret->vertLookup  = NULL;
+    ret->vrt2Lookup  = NULL;
+    ret->kanaFeature = NULL;
+    ft_error =
+	FT_OpenType_Validate( face, FT_VALIDATE_GSUB,
+			      &dummy, &dummy, &dummy, &GSUB_table, &dummy);
+    if (ft_error == FT_Err_Unimplemented_Feature) {
+        fprintf(stderr, "warning: FT_OpenType_Validate is disabled. "
+                "Replace FreeType2 with otvalid-enabled version.\n");
+        return ret;
+    } else if (ft_error != 0 || GSUB_table == 0) {
+	fprintf(stderr, "warning: %s has no GSUB table.\n",
+		face->family_name);
+	return ret;
+    }
+    scan_GSUB_Header(ret, GSUB_table);
+    if (ret->SubTableCount == 0) {
+	fprintf(stderr, "warning: %s has no vrt2/vert feature.\n",
+		face->family_name);
+    }
+    free((void*)GSUB_table);
+    return ret;
+}
+
+/********** converting part *****************/
+
+static FT_UInt get_vert_nth_gid(struct SubTable_st *t, FT_UInt gid, int n) {
+    switch (t->SingleSubst.SubstFormat) {
+    case 1:
+	return gid + t->SingleSubst.DeltaGlyphID;
+    case 2:
+	return t->SingleSubst.Substitute[n];
+    }
+    fprintf(stderr, "get_vert_nth_gid: internal error");
+    exit(1);
+    return 0;
+}
+
+
+FT_UInt ft2vert_get_gid(struct ft2vert_st *ft2vert, FT_UInt gid) {
+    int i, k;
+    int j = 0; /* StartCoverageIndex */
+
+    for (k=0; k<ft2vert->SubTableCount; k++) {
+	struct SubTable_st *t = &ft2vert->SubTable[k];
+	switch (t->Coverage.CoverageFormat) {
+	case 1:
+	    for (i=0; i<t->Coverage.GlyphCount; i++) {
+		if (t->Coverage.GlyphArray[i] == gid) {
+		    return get_vert_nth_gid(t, gid, i);
+		}
+	    }
+	    break;
+	case 2:
+	    for (i=0; i<t->Coverage.RangeCount; i++) {
+		struct RangeRecord_st *r = &t->Coverage.RangeRecord[i];
+		if (r->Start <= gid && gid <= r->End) {
+		    return get_vert_nth_gid(t, gid, gid - r->Start + j);
+		}
+		j += r->End - r->Start + 1;
+	    }
+	    break;
+	default:
+	    fprintf(stderr, "ft2vert_get_gid: internal error");
+	    exit(1);
+	}
+    }
+    return gid;
+}
+
+#endif	/* PTEX */
