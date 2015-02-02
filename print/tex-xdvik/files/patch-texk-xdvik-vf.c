--- texk/xdvik/vf.c.orig	2014-09-02 18:41:34.000000000 +0900
+++ texk/xdvik/vf.c	2015-01-31 21:02:18.000000000 +0900
@@ -126,7 +126,7 @@
 	    len = get_bytes(VF_file, 4);
 	    cc = get_bytes(VF_file, 4);
 	    width = get_bytes(VF_file, 4);
-	    if ((resource.omega && cc >= 65536)
+	    if ((resource.omega && cc >= 0x110000)
 		|| (!resource.omega && cc >= 256)) {
 		XDVI_WARNING((stderr, "Virtual character %lu in font %s ignored.",
 			      cc, fontp->fontname));
@@ -141,6 +141,13 @@
 	}
 	if (resource.omega) {
 	    maxcc = (cc > maxcc) ? cc : maxcc;
+	    if (cc > fontp->maxchar) {
+		int i = 65536 * ((int)(cc / 65536)+1);
+		fontp->macro = xrealloc(fontp->macro, sizeof(struct macro) * i);
+		memset((char *)&fontp->macro[fontp->maxchar+1], 0,
+			(i-fontp->maxchar-1) * sizeof(struct macro));
+		fontp->maxchar = i-1;
+	    }
 	}
 	m = &fontp->macro[cc];
 	m->dvi_adv = width * fontp->dimconv;
