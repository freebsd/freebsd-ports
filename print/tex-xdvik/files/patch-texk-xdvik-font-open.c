--- texk/xdvik/font-open.c.orig	2013-05-14 05:26:19 UTC
+++ texk/xdvik/font-open.c
@@ -27,6 +27,9 @@
 #include "xdvi-config.h"
 #include "xdvi.h"
 #include "dvi-draw.h"
+#ifdef PTEX
+#include "ptexmap.h"
+#endif
 #include "util.h"
 #include "events.h"
 #include "dvi-init.h"
@@ -213,6 +216,38 @@ getdefaults(FILE *f)
 		p_node->value = xmemdup(p, len + 1);
 		*p_tail = p_node;
 		p_tail = &p_node->next;
+	    } else if (*p == 'x') {
+		char *name;
+
+		name = NULL;
+		do ++p;
+		while (*p == ' ' || *p == '\t');
+
+		if (*p == '+')
+		    do ++p;
+		    while (*p == ' ' || *p == '\t');
+
+		name = strtok(p, " \t");
+		if (name == NULL) {
+		    XDVI_WARNING((stderr, "Syntax error in entry \"%s\" "
+			"(ignored)", ffline));
+		    continue;
+		}
+		read_ptexmap_file(name);
+	    } else if (*p == 'r') {
+		char *name, *ptr;
+
+		name = ptr = NULL;
+		do ++p;
+		while (*p == ' ' || *p == '\t');
+		name = strtok(p, " \t");
+		if ((name == NULL) ||
+		    (ptr  = strtok(NULL, " \t")) == NULL) {
+		    XDVI_WARNING((stderr, "Syntax error in entry \"%s\" "
+			"(ignored)", ffline));
+		    continue;
+		}
+		add_replace_dictionary(name, ptr);
 	    }
 	}
 
@@ -446,13 +481,38 @@ init_t1_lookup(void)
 		TRACE_FT((stderr, "Encoding[%d]: '%s' = '%s' -> '%s'",
 		  i, enc, name, ptr));
 #  endif
+#ifdef PTEX
+	    }
+	    else if (strcmp(keyword, "ptexmap") == 0) {
+		if ((ptr = strtok(NULL, delim)) == NULL) {
+		    XDVI_WARNING((stderr,
+			    "Syntax error in entry \"%s\" (skipping line)",
+			    ffline));
+		    continue;
+		}
+		read_ptexmap_file(ptr);
+	    }
+	    else if (strcmp(keyword, "replace") == 0) {
+		if ((name = strtok(NULL, delim)) == NULL ||
+		    (ptr  = strtok(NULL, delim)) == NULL) {
+		    XDVI_WARNING((stderr,
+			    "Syntax error in entry \"%s\" (skipping line)",
+			    ffline));
+		    continue;
+		}
+		add_replace_dictionary(name, ptr);
+#endif
 	    } else {
 		/* again, nag them with a popup so that they'll do something
 		   about this ... */
 		popup_message(globals.widgets.top_level,
 			  MSG_ERR,
 			  "Please check the syntax of your config file.  "
+#ifdef PTEX
+			  "Valid keywords are: \"enc\", \"dvipsmap\", \"ptexmap\" and \"replace\".",
+#else
 			  "Valid keywords are: \"enc\" and \"dvipsmap\".",
+#endif
 			  "Skipping unknown keyword \"%s\" in config file %s.",
 			  keyword, filename);
 	    }
@@ -1103,7 +1163,7 @@ process_gs_fontmap(FILE *f)
 	    if (ttype == GS_EOF || ttype == GS_ERR)
 		break;
 	    if (ttype == LPAREN) {
-		Boolean	quiet = False;
+	        Boolean quiet = False;
 		FILE	*f1;
 
 		ttype = get_gs_token(&gsf, pos1, &pos2, "Fontmap");
@@ -1692,7 +1752,7 @@ font_open(
 	  const char **font_ret,
 	  int *dpi_ret)
 {
-    char *name;
+    char *name = NULL;
     kpse_glyph_file_type file_ret;
 #if DELAYED_MKTEXPK
     Boolean message_done = False;
@@ -1706,6 +1766,12 @@ font_open(
     fontp->filename = NULL;
     *dpi_ret = fontp->fsize;
 
+#ifdef PTEX
+     /* for kanji, first try jfm's, then 8-bit vf's (not 16bit ovf's). */
+    if (iskanjifont(fontp->fontname))
+	name = kpse_find_tfm(fontp->fontname);
+    else
+#endif /* PTEX */
     if (resource.omega) { /* for omega, first try 16-bit ovf's, then 8-bit vf's. */
 	name = kpse_find_ovf(fontp->fontname);
 	if (name == NULL)
