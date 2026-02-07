--- texk/xdvik/fontconfig.c.orig	2015-07-19 18:49:42 UTC
+++ texk/xdvik/fontconfig.c
@@ -0,0 +1,92 @@
+#include "xdvi-config.h"
+#include "xdvi.h"
+#include <stdio.h>
+#include "util.h"
+#include "string-utils.h"
+
+#ifdef	PTEX
+#include "kpathsea/tex-file.h"
+
+#if	HAVE_FONTCONFIG
+#include <fontconfig/fontconfig.h>
+
+char *fc_match(char *name)
+{
+    FcFontSet   *fs;
+    FcPattern   *pat;
+    FcResult    result;
+    FcPattern   *match;
+    char        *ret = NULL;
+    static int inited = false;
+
+    if (!inited) {
+        if (FcInit() == 0) {
+            XDVI_WARNING((stderr, "fontconfig: Can't init library.\n"));
+            return NULL;
+        }
+        inited = true;
+    }
+
+    pat = FcNameParse((FcChar8 *)name);
+    FcConfigSubstitute(0, pat, FcMatchPattern);
+    FcDefaultSubstitute(pat);
+    fs = FcFontSetCreate();
+    match = FcFontMatch(0, pat, &result);
+    if (match != NULL) FcFontSetAdd(fs, match);
+    if (pat != NULL) FcPatternDestroy(pat);
+
+    if (fs != NULL) {
+        if (fs->nfont > 0) {
+            FcChar8   *file;
+            if (FcPatternGetString(fs->fonts[0], FC_FILE, 0, &file)
+                == FcResultMatch) {
+                ret = strdup(file);
+            }
+        }
+        FcFontSetDestroy(fs);
+    }
+    if (kpathsea_debug) {
+        fprintf(stderr, "fontconfig:fc_match(%s) => %s\n", name, ret);
+    }
+    return ret;
+}
+
+char *fc_convert(char *name) {
+    char *tmp, *s;
+
+    if (str_is_suffix(".otf", name, false)) return NULL;
+    if (str_is_suffix(".ttf", name, false)) return NULL;
+    if (str_is_suffix(".ttc", name, false)) return NULL;
+    tmp = strdup(name);
+    s = strstr(tmp, "-Light");   if (s != NULL) *s = '\0';
+    s = strstr(tmp, "-Medium");  if (s != NULL) *s = '\0';
+    s = strstr(tmp, "-Regular"); if (s != NULL) *s = '\0';
+    s = fc_match(tmp);
+    free(tmp);
+    return s;
+}
+#endif	/* HAVE_FONTCONFIG */
+
+
+const char *get_ptex_font_pathname(char *name)
+{
+    char *s = NULL;
+    FILE *fp;
+
+    if ((fp=XFOPEN(name, "r")) != NULL) {
+	fclose(fp);
+	s = name;
+    }
+
+    if (s == NULL) s = kpse_find_file(name, kpse_opentype_format, true);
+    if (s == NULL) s = kpse_find_file(name, kpse_truetype_format, true);
+    if (s == NULL) s = kpse_find_file(name, kpse_miscfonts_format, true);
+    if (s == NULL) s = kpse_find_file(name, kpse_program_text_format, true);
+#if	HAVE_FONTCONFIG
+    if (s == NULL) s = fc_convert(name);
+#endif	/* HAVE_FONTCONFIG */
+    if (s == NULL) s = name;
+    return s;
+}
+
+#endif	/* PTEX */
