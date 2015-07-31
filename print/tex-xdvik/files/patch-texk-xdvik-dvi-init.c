--- texk/xdvik/dvi-init.c.orig	2013-04-05 00:14:54 UTC
+++ texk/xdvik/dvi-init.c
@@ -31,6 +31,10 @@ in xdvi.c.
 
 #include "dvi-init.h"
 #include "dvi-draw.h"
+#ifdef PTEX
+#include "ptexvf.h"
+#include "ptexmap.h"
+#endif
 #include "util.h"
 #include "x_util.h"
 #include "exit-handlers.h"
@@ -53,6 +57,9 @@ in xdvi.c.
 #include "statusline.h"
 #include "events.h"
 #include "font-open.h"
+#ifdef HAVE_LIBPAPER
+#include <paper.h>
+#endif
 
 #if FREETYPE
 # include FT_SIZES_H
@@ -67,6 +74,10 @@ in xdvi.c.
 #define	VF_PRE		247
 #define	VF_ID_BYTE	202
 #define	VF_MAGIC	((VF_PRE << 8) | VF_ID_BYTE)
+#ifdef PTEX
+#define	JFMS_MAGIC	11
+#define	JFMS_TATEMAGIC	9
+#endif /* PTEX */
 
 /* font stuff */
 struct font *tn_table[TNTABLELEN];
@@ -170,8 +181,22 @@ static void
 delete_glyphs(struct font *fontp)
 {
     struct glyph *g;
+#ifdef PTEX
+    int n, maxchar;
 
+    maxchar = fontp->maxchar + 1;
+    for (n = 0; n < maxchar; ++n) {
+	g = (fontp->flags & FONT_KANJI) ? fontp->kglyph[n] : &fontp->glyph[n];
+	if (g == NULL) continue;
+#else /* !PTEX */
     for (g = fontp->glyph; g <= fontp->glyph + fontp->maxchar; ++g) {
+#endif /* !PTEX */
+	free_bitmap2(g);
+    }
+}
+
+void free_bitmap2(struct glyph *g) {
+    {
 	if (g->bitmap2.bits) {
 	    free(g->bitmap2.bits);
 	    g->bitmap2.bits = NULL;
@@ -283,7 +308,23 @@ free_unused_fonts(void)
 		}
 		else {
 		    delete_glyphs(fontp);
+#ifdef PTEX
+		    if (fontp->flags & FONT_KANJI) {
+			int n;
+			for (n = 0; n < (int)fontp->maxchar + 1; ++n) {
+			    if (fontp->kglyph[n] != NULL) {
+				free(fontp->kglyph[n]);
+			    }
+			}
+			free(fontp->kglyph);
+		    }
+		    else {
+#endif /* PTEX */
 		    free((char *)fontp->glyph);
+		    fontp->glyph = NULL;
+#ifdef PTEX
+		    }
+#endif /* PTEX */
 		}
 		free((char *)fontp);
 	    }
@@ -324,7 +365,11 @@ reset_colors(void)
 	struct glyph *g;
 
 	for (f = font_head; f != NULL; f = f->next)
-	    if ((f->flags & FONT_LOADED) && !(f->flags & FONT_VIRTUAL))
+	    if ((f->flags & FONT_LOADED) && !(f->flags & FONT_VIRTUAL)
+#ifdef PTEX
+		&& !(f->flags & FONT_KANJI)
+#endif /* PTEX */
+		)
 		for (g = f->glyph; g <= f->glyph + f->maxchar; ++g)
 		    g->fg = NULL;
     }
@@ -447,6 +492,10 @@ load_font(struct font *fontp
      * appear before the main window comes up ...
      */
 
+#ifdef PTEX
+    fontp->dir = 0;
+#endif /* PTEX */
+
     fontp->file = font_open(
 #if DELAYED_MKTEXPK
 			    load_font_now,
@@ -511,6 +560,12 @@ load_font(struct font *fontp
     fontp->fsize = size_found;
     fontp->timestamp = ++current_timestamp;
     fontp->maxchar = maxchar = 255;
+#ifdef PTEX
+    if (iskanjifont(fontp->fontname)) {
+	fontp->flags |= FONT_KANJI;
+	fontp->set_char_p = set_char2;
+    } else
+#endif /* PTEX */
     fontp->set_char_p = set_char;
     magic = get_bytes(fontp->file, 2);
 
@@ -529,6 +584,13 @@ load_font(struct font *fontp
 	else
 	    (void)read_VF_index(fontp, (wide_bool)hushcs);
 	break;
+#ifdef PTEX
+    case JFMS_MAGIC:
+    case JFMS_TATEMAGIC:
+	fontp->dir = (magic == JFMS_TATEMAGIC);
+	read_PTEXVF_index(fontp);
+	return True;
+#endif /* PTEX */
     default:
 	XDVI_FATAL((stderr, "Cannot recognize format for font file %s",
 	  fontp->filename));
@@ -783,7 +845,13 @@ process_preamble(FILE *fp, dviErrFlagT *
 	TRACE_FILES((stderr, "process_preamble: fp = %p, errflag = %d, returning False", (void *)fp, *errflag));
 	return False;
     }
-    if (get_byte(fp) != 2) {
+#ifdef PTEX
+    k = get_byte(fp);
+    if (k != 2 && k != 3)
+#else /* !PTEX */
+    if (get_byte(fp) != 2)
+#endif /* !PTEX */
+    {
 	*errflag = WRONG_DVI_VERSION;
 	TRACE_FILES((stderr, "process_preamble: fp = %p, errflag = %d, returning False", (void *)fp, *errflag));
 	return False;
@@ -845,7 +913,12 @@ find_postamble(FILE *fp, dviErrFlagT *er
 	fseek(fp, --pos, SEEK_SET);
 	byte = get_byte(fp);
     }
-    if (byte != 2) {
+#ifdef PTEX
+    if (byte != 2 && byte != 3)
+#else /* !PTEX */
+    if (byte != 2)
+#endif /* !PTEX */
+    {
 	*errflag = WRONG_DVI_VERSION;
 	TRACE_FILES((stderr, "find_postamble: returning FALSE"));
 	return False;
@@ -865,9 +938,14 @@ set_paper_type(const char *arg)
     char temp[21];
     const char **p;
     char *q;
+#ifdef HAVE_LIBPAPER
+    const struct paper *pp;
+    int landscape = 0;
+#else
     const char **paper_types = get_paper_types();
     size_t paper_types_size = get_paper_types_size();
-    
+#endif
+
     if (*arg == '+') {
 	++arg;
 	ignore_papersize_specials = True;
@@ -884,6 +962,57 @@ set_paper_type(const char *arg)
 	    break;
     }
     arg = temp;
+#ifdef HAVE_LIBPAPER
+    paperinit();
+    if (strcmp(temp, "libpaper") == 0) {
+	const char *name;
+
+	name = systempapername();
+	if (name == NULL)
+		name = defaultpapername();
+	if (strcmp(name, "libpaper") == 0)
+		name = "a4";
+
+	strncpy(temp, name, sizeof(temp));
+	temp[sizeof(temp) - 1] = '\0';
+    }
+    if (strcmp(temp, "letter") != 0 &&
+	strcmp(temp, "ledger") != 0) {
+	if (temp[strlen(temp) - 1] == 'r') {
+		temp[strlen(temp) - 1] = '\0';
+		landscape = 1;
+	}
+    }
+    for (pp = paperfirst(); pp; pp = papernext(pp)) {
+	if (strcmp(temp, papername(pp)) == 0) {
+		double w, h;
+		char wstr[256];
+		char hstr[256];
+		
+		if (landscape == 0) {
+			w = paperpswidth(pp);
+			h = paperpsheight(pp);
+		} else {
+			h = paperpswidth(pp);
+			w = paperpsheight(pp);
+		}
+		w = w / 72.0 * 10 * 2.54;
+		h = h / 72.0 * 10 * 2.54;
+		snprintf(wstr, sizeof(wstr), "%f mm", w);
+		snprintf(hstr, sizeof(hstr), "%f mm", h);
+		wstr[sizeof(wstr) - 1] = '\0';
+		hstr[sizeof(hstr) - 1] = '\0';
+		m_paper_unshrunk_w = atopix(wstr, False);
+		m_paper_unshrunk_h = atopix(hstr, False);
+    		globals.grid_paper_unit = atopixunit("mm");
+
+		break;
+	}
+    }
+    paperdone();
+    if (pp == NULL)
+	return (False);
+#else
     /* perform substitutions */
     for (p = paper_types; p < paper_types + paper_types_size; p += 2) {
 	if (strcmp(temp, *p) == 0) {
@@ -898,6 +1027,7 @@ set_paper_type(const char *arg)
     m_paper_unshrunk_h = atopix(arg1 + 1, False);
 
     globals.grid_paper_unit = atopixunit(arg);
+#endif
     
     return (m_paper_unshrunk_w != 0 && m_paper_unshrunk_h != 0);
 }
