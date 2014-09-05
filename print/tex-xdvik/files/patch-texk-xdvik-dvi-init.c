--- dvi-init.c.orig	2013-04-05 09:14:54.000000000 +0900
+++ dvi-init.c	2014-08-22 23:26:27.000000000 +0900
@@ -53,6 +53,9 @@
 #include "statusline.h"
 #include "events.h"
 #include "font-open.h"
+#ifdef HAVE_LIBPAPER
+#include <paper.h>
+#endif
 
 #if FREETYPE
 # include FT_SIZES_H
@@ -865,9 +868,14 @@
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
@@ -884,6 +892,57 @@
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
@@ -898,6 +957,7 @@
     m_paper_unshrunk_h = atopix(arg1 + 1, False);
 
     globals.grid_paper_unit = atopixunit(arg);
+#endif
     
     return (m_paper_unshrunk_w != 0 && m_paper_unshrunk_h != 0);
 }
