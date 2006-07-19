--- ttf.cpp.orig	Wed Jul 19 11:13:20 2006
+++ ttf.cpp	Wed Jul 19 11:22:41 2006
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
