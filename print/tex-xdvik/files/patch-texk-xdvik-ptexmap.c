--- texk/xdvik/ptexmap.c.orig	2015-07-19 18:49:42 UTC
+++ texk/xdvik/ptexmap.c
@@ -0,0 +1,254 @@
+#include "xdvi-config.h"
+#include "xdvi.h"
+#include "ptexmap.h"
+#include "util.h"
+#include "kpathsea/tex-file.h"
+#ifdef	PTEX
+#include "ft2.h"
+#include <ctype.h>
+
+#define NUM(a)	  ((int)(sizeof(a)/sizeof(*(a))))
+
+static int dictionaries_num = 0;
+static int dictionaries_max = 0;
+static struct dictionary {
+  char *key, *word;
+} *dictionaries = NULL;
+
+static struct dictionary *get_dictionary(char *key)
+{
+    int i;
+
+    if (key == NULL) return NULL;
+    for (i=0; i<dictionaries_num; i++) {
+	if (strcmp(key, dictionaries[i].key) == 0) {
+	    return &dictionaries[i];
+	}
+    }
+    return NULL;
+}
+
+void add_replace_dictionary(char *key, char *word)
+{
+    struct dictionary *d;
+
+    d = get_dictionary(key);
+    if (d == NULL) {
+	if (dictionaries_num == dictionaries_max) {
+	    if (dictionaries_max == 0) dictionaries_max = 16;
+	    else		       dictionaries_max *= 2;
+	    dictionaries = xrealloc(dictionaries,
+			     sizeof(dictionaries[0]) * dictionaries_max);
+	}
+	d = &dictionaries[dictionaries_num++];
+	d->key  = xstrdup(key);
+    } else {
+	XDVI_WARNING((stderr, "Duplication of replace entry '%s' was found. "
+		      "Overwrites '%s' with '%s'.\n", key, d->word, word));
+	free(d->word);
+    }
+
+    d->word = xstrdup(word);
+}
+
+static char *replace_string(char *key)
+{
+    struct dictionary *d = get_dictionary(key);
+    if (d == NULL) return key;
+    return d->word;
+}
+
+
+static int ptexmaps_num = 0;
+static int ptexmaps_max = 0;
+static struct ptexmap *ptexmaps = NULL;
+
+struct ptexmap *getkanjifont(const char *jfm_name)
+{
+    int i;
+
+    for (i=0; i<ptexmaps_num; i++) {
+	if (strcmp(jfm_name, ptexmaps[i].jfm_name) == 0) {
+	    return &ptexmaps[i];
+	}
+    }
+    return NULL;
+}
+
+static struct ptexmap *add_fontmap2(char *jfm, char *font, int encoding,
+				    char *map_filename, char *enc)
+{
+    struct ptexmap *map;
+
+    map = getkanjifont(jfm);
+    if (map == NULL) {
+	if (ptexmaps_num == ptexmaps_max) {
+	    if (ptexmaps_max == 0) ptexmaps_max = 8;
+	    else		   ptexmaps_max *= 2;
+	    ptexmaps = xrealloc(ptexmaps, sizeof(ptexmaps[0]) * ptexmaps_max);
+	}
+	map = &ptexmaps[ptexmaps_num++];
+	map->jfm_name = xstrdup(jfm);
+    } else {
+	XDVI_WARNING((stderr, "A ptexmap entry for '%s' in \"%s\" duplicates "
+		      "a former entry in \"%s\". Overwrites.\n",
+		      jfm, map_filename, map->map_filename));
+	free(map->font_filename);
+    }
+
+    map->face_index = 0;
+    map->ft2_index = -1;
+    if (sscanf(font, ":%d:", &map->face_index) == 1) {
+	font = strchr(font+1, ':') + 1;
+    }
+
+    font = replace_string(font);
+    if (strlen(font) >6 && strstr(font + (strlen(font) - 5), "/AJ16") != NULL) {
+      if (strcmp(enc, "Identity-H") == 0) {
+	encoding = ENC_AJ16_H;
+	if (globals.debug & DBG_PTEXFNT)
+	  fprintf(stderr, "The encoding is replaced by \"AJ16-H\" .\n");
+      }
+      else if (strcmp(enc, "Identity-V") == 0) {
+	encoding = ENC_AJ16_V;
+	if (globals.debug & DBG_PTEXFNT)
+	  fprintf(stderr, "The encoding is replaced by \"AJ16-V\" .\n");
+      }
+      map->font_filename  = xstrndup(font, strlen(font) - 5);
+    } else {
+      map->font_filename  = xstrdup(font);
+    }
+    map->encoding = encoding;
+    map->extend = 1.0;
+    map->slant  = 0.0;
+    map->variant = 0;
+    map->map_filename = map_filename;
+    return map;
+}
+
+int str2encoding(char *enc_name) {
+    int i;
+    static struct {
+	char *enc_name;
+	int encoding;
+    } encodes[] = {
+	{ "JIS-H",      ENC_JIS_H },
+	{ "JIS-V",      ENC_JIS_V },
+	{ "Unicode-H",  ENC_UNICODE_H },
+	{ "Unicode-V",  ENC_UNICODE_V },
+	{ "Unicode-V",  ENC_UNICODE_V },
+	{ "AJ16-H",     ENC_AJ16_H },
+	{ "AJ16-V",     ENC_AJ16_V },
+	{ "Identity-H", ENC_IDENTITY },
+	{ "Identity-V", ENC_IDENTITY },
+	/* caution: Identity-H = Identity-V */
+    };
+
+    if (enc_name == NULL) return ENC_UNKNOWN;
+    for (i=0; i<NUM(encodes); i++) {
+	if (strcmp(enc_name, encodes[i].enc_name) == 0) {
+	    return encodes[i].encoding;
+	}
+    }
+    return ENC_UNKNOWN;
+}
+
+static int add_fontmap(char *line, char *map_filename)
+{
+    struct ptexmap *map;
+    char *s, *jfm, *font, *enc;
+    int encoding = 0;
+    float *ptr = NULL;
+
+    jfm  = strtok(line, " \t");
+    enc  = replace_string(strtok(NULL, " \t"));
+    font = strtok(NULL, " \t,!");
+
+    if (jfm == NULL) return true; /* empty line */
+
+    if (font == NULL) {
+	XDVI_WARNING((stderr, "A font name for \"%s\" is empty.\n",
+		      jfm));
+	return true;
+    }
+
+    if (strlen(font) >6 && strstr(font + (strlen(font) - 5), "/AJ16") != NULL) {
+      if (strcmp(enc, "Identity-H") == 0) enc = "AJ16-H";
+      else if (strcmp(enc, "Identity-V") == 0) enc = "AJ16-V";
+      font[strlen(font) - 5] = '\0';
+    }
+    encoding = str2encoding(enc);
+
+    if (encoding == ENC_UNKNOWN) {
+	XDVI_WARNING((stderr, "Unknown encode \"%s\" for \"%s\".\n",
+		      enc, jfm));
+	return true;
+    }
+
+    if (globals.debug & DBG_PTEXFNT) {
+	fprintf(stderr, "JFM name is \"%s\".\n", jfm);
+	fprintf(stderr, "Font filename is \"%s\".\n", font);
+	fprintf(stderr, "Font is %s encode (#%d).\n", enc, encoding);
+    }
+
+    map = add_fontmap2(jfm, font, encoding, map_filename, enc);
+
+    while ((s=strtok(NULL, " \t,\r\n")) != NULL) {
+	if      (strcmp(s, "-e") == 0) ptr = &map->extend;
+	else if (strcmp(s, "-s") == 0) ptr = &map->slant;
+	else if (strcmp(s, "Bold") == 0)   map->variant |= VAR_BOLD;
+	else if (strcmp(s, "Italic") == 0) map->variant |= VAR_ITALIC;
+	else if (strcmp(s, "BoldItalic") == 0) {
+	    map->variant |= VAR_BOLD | VAR_ITALIC;
+	} else if ((isdigit(*s) || *s == '.' || *s == '-') && ptr != NULL) {
+	    *ptr = atof(s);
+	} else return false;
+    }
+    return true;
+}
+
+
+char *get_ptexmap_name(char *filename)
+{
+    char *s = NULL;
+    FILE *fp;
+
+    if ((fp=fopen(filename, "r")) != NULL) {
+	fclose(fp);
+	s = xstrdup(filename);
+    }
+    if (s == NULL) s = kpse_find_file(filename, kpse_fontmap_format, true);
+    return s;
+}
+
+
+void read_ptexmap_file(char *filename)
+{
+    FILE *fp;
+    char *s;
+    char line[BUFSIZ], line_orig[BUFSIZ];
+
+    filename = get_ptexmap_name(filename);
+    /* 'filename' will stored in ptexmap structure,
+       so we can't free(filename) in this function. */
+    if ((fp = fopen(filename, "r")) == NULL) {
+	XDVI_WARNING((stderr, "Warning: Can't open \"%s\"\n", filename));
+	return;
+    }
+    if (globals.debug & DBG_FILES) {
+	TRACE_FILES((stderr, "read_ptexmap_file for |%s|", filename));
+    }
+
+    while (fgets(line, BUFSIZ, fp) != NULL) {
+	if ((s=strchr(line,'\n')) != NULL) *s = '\0'; /* break \n */
+	strcpy(line_orig, line);
+	if ((s=strchr(line,'%'))  != NULL) *s = '\0'; /* break comment */
+	if ((s=strchr(line,'#'))  != NULL) *s = '\0'; /* break comment */
+
+	if (!add_fontmap(line, filename)) {
+	    XDVI_WARNING((stderr, "'%s', Unknown option.\n", line_orig));
+	}
+    }
+    fclose(fp);
+}
+#endif	/* PTEX */
