--- ttf.cpp	2003-01-08 00:25:25.000000000 -0500
+++ ttf.cpp	2012-12-07 12:34:54.000000000 -0500
@@ -51,20 +51,27 @@
 bool
 Face::MappingPresent (int cmapidx, NumericMapping *m, int enc_size, int start_code, bool enc_comp)
 {
-    int idx, missing = 0;
+    int idx;
+    unsigned int missing = 0, bail_at, msize;
+
     FT_Set_Charmap (face, face->charmaps[cmapidx]);
 
-    for (unsigned int i = start_code; i < m->size (); i++) {
+    msize = m->size();
+    if (enc_size <= 256) {
+       bail_at = int (cmdline::instance()->option ("max-missing"));
+    } else {
+       bail_at = ((int (cmdline::instance()->option ("max-missing-percentage"))
+& enc_comp)*enc_size)/100;
+    }
+
+    for (unsigned int i = start_code; i < msize && missing < bail_at; i++) {
 	if ((*m)[i] < 0) 
 	    continue;
 	if ((idx = FT_Get_Char_Index (face, (*m)[i])) == 0)
 	    missing++;
     }
-    if (enc_size <= 256) {
-        return (missing <= int (cmdline::instance()->option ("max-missing")));
-    } else {
-        return ((100 * missing/enc_size) <= int (cmdline::instance()->option ("max-missing-percentage")) & enc_comp);
-    }
+
+    return missing < bail_at;
 }
 
 Face::Face (const std::string &filename)
@@ -239,7 +246,7 @@
 	for (i = 0; i < n; i++) {
 	    if ((fterror = FT_Get_Sfnt_Name (face, i, &NamePtr)) != FT_Err_Ok) {
                     std::cout << "Warning: Can't SFNT name : " << FileName << "(" << fterror << ")" << std::endl;
-	            return;
+	            return NULL;
             };
             platform = NamePtr.platform_id;
             encoding = NamePtr.encoding_id;
@@ -483,7 +490,7 @@
 const char *
 Face::PanoseWeight (void) const
 {
-    static char *panose_weight_latin[] = {
+    static const char *panose_weight_latin[] = {
 	"any",
 	"no fit",
 	"very light",
@@ -548,7 +555,7 @@
 const char *
 Face::PanoseWidth (void) const
 {
-    static char *panose_spacing_latin_text [] = {
+    static const char *panose_spacing_latin_text [] = {
 	"any",
 	"no fit",
 	"old style",
@@ -561,7 +568,7 @@
 	"monospaced",
     };
     
-    static char *panose_spacing_latin_decorative [] = {
+    static const char *panose_spacing_latin_decorative [] = {
 	"any",
 	"no fit",
 	"super condensed",
