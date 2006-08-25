--- lib/font/bitmap/pcfread.c.orig	Sat Jul  9 08:36:12 2005
+++ lib/font/bitmap/pcfread.c	Thu Aug 24 21:56:56 2006
@@ -45,6 +45,7 @@
 #endif
 
 #include <stdarg.h>
+#include <stdint.h>
 
 void
 pcfError(const char* message, ...)
@@ -133,6 +134,10 @@
 	return (PCFTablePtr) NULL;
     count = pcfGetLSB32(file);
     if (IS_EOF(file)) return (PCFTablePtr) NULL;
+    if (count < 0 || count > INT32_MAX / sizeof(PCFTableRec)) {
+	pcfError("pcfReadTOC(): invalid file format\n");
+	return NULL;
+    }
     tables = (PCFTablePtr) xalloc(count * sizeof(PCFTableRec));
     if (!tables) {
       pcfError("pcfReadTOC(): Couldn't allocate tables (%d*%d)\n", count, sizeof(PCFTableRec));
@@ -252,6 +257,10 @@
     if (!PCF_FORMAT_MATCH(format, PCF_DEFAULT_FORMAT))
 	goto Bail;
     nprops = pcfGetINT32(file, format);
+    if (nprops <= 0 || nprops > INT32_MAX / sizeof(FontPropRec)) {
+	pcfError("pcfGetProperties(): invalid nprops value (%d)\n", nprops);
+	goto Bail;
+    }
     if (IS_EOF(file)) goto Bail;
     props = (FontPropPtr) xalloc(nprops * sizeof(FontPropRec));
     if (!props) {
@@ -267,6 +276,13 @@
 	props[i].name = pcfGetINT32(file, format);
 	isStringProp[i] = pcfGetINT8(file, format);
 	props[i].value = pcfGetINT32(file, format);
+	if (props[i].name < 0 
+	    || (isStringProp[i] != 0 && isStringProp[i] != 1)
+	    || (isStringProp[i] && props[i].value < 0)) {
+	    pcfError("pcfGetProperties(): invalid file format %d %d %d\n",
+		     props[i].name, isStringProp[i], props[i].value);
+	    goto Bail;
+	}
 	if (IS_EOF(file)) goto Bail;
     }
     /* pad the property array */
@@ -282,6 +298,7 @@
     }
     if (IS_EOF(file)) goto Bail;
     string_size = pcfGetINT32(file, format);
+    if (string_size < 0) goto Bail;
     if (IS_EOF(file)) goto Bail;
     strings = (char *) xalloc(string_size);
     if (!strings) {
@@ -422,6 +439,10 @@
     else
 	nmetrics = pcfGetINT16(file, format);
     if (IS_EOF(file)) goto Bail;
+    if (nmetrics < 0 || nmetrics > INT32_MAX / sizeof(CharInfoRec)) {
+	pcfError("pcfReadFont(): invalid file format\n");
+	goto Bail;
+    }
     metrics = (CharInfoPtr) xalloc(nmetrics * sizeof(CharInfoRec));
     if (!metrics) {
       pcfError("pcfReadFont(): Couldn't allocate metrics (%d*%d)\n", nmetrics, sizeof(CharInfoRec));
@@ -447,7 +468,7 @@
     nbitmaps = pcfGetINT32(file, format);
     if (nbitmaps != nmetrics || IS_EOF(file))
 	goto Bail;
-
+    /* nmetrics is alreadt ok, so nbitmap also is */
     offsets = (CARD32 *) xalloc(nbitmaps * sizeof(CARD32));
     if (!offsets) {
       pcfError("pcfReadFont(): Couldn't allocate offsets (%d*%d)\n", nbitmaps, sizeof(CARD32));
@@ -461,6 +482,7 @@
     for (i = 0; i < GLYPHPADOPTIONS; i++) {
 	bitmapSizes[i] = pcfGetINT32(file, format);
 	if (IS_EOF(file)) goto Bail;
+	if (bitmapSizes[i] < 0) goto Bail;
     }
     
     sizebitmaps = bitmapSizes[PCF_GLYPH_PAD_INDEX(format)];
@@ -536,6 +558,7 @@
 	if (IS_EOF(file)) goto Bail;
 	if (nink_metrics != nmetrics)
 	    goto Bail;
+	/* nmetrics already checked */
 	ink_metrics = (xCharInfo *) xalloc(nink_metrics * sizeof(xCharInfo));
       if (!ink_metrics) {
           pcfError("pcfReadFont(): Couldn't allocate ink_metrics (%d*%d)\n", nink_metrics, sizeof(xCharInfo));       
@@ -809,6 +832,10 @@
     else
 	nmetrics = pcfGetINT16(file, format);
     if (IS_EOF(file)) goto Bail;
+    if (nmetrics < 0 || nmetrics > INT32_MAX / sizeof(CharInfoRec)) {
+	pcfError("pmfReadFont(): invalid file format\n");
+	goto Bail;
+    }
     metrics = (CharInfoPtr) xalloc(nmetrics * sizeof(CharInfoRec));
     if (!metrics) {
       pcfError("pmfReadFont(): Couldn't allocate metrics (%d*%d)\n", nmetrics, sizeof(CharInfoRec));
