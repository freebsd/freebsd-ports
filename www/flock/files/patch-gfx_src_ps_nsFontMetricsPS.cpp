--- gfx/src/ps/nsFontMetricsPS.cpp.orig	Fri Dec 15 01:42:25 2006
+++ gfx/src/ps/nsFontMetricsPS.cpp	Fri Dec 15 01:41:20 2006
@@ -1037,8 +1037,10 @@ nsFontPSXft::Init(nsXftEntry* aEntry,
 
 nsFontPSXft::~nsFontPSXft()
 {
-  if (mEntry->mFace) 
+  if (mEntry->mFace) {
     FT_Done_Face(mEntry->mFace);
+    mEntry->mFace = nsnull;
+  }
 
   if (FT_Done_FreeType(mFreeTypeLibrary))
     return;
@@ -2327,8 +2329,10 @@ nsXftType1Generator::Init(nsXftEntry* aE
 
 nsXftType1Generator::~nsXftType1Generator()
 {
-  if (mEntry->mFace) 
+  if (mEntry->mFace) {
     FT_Done_Face(mEntry->mFace);
+    mEntry->mFace = nsnull;
+  }
 
   if (FT_Done_FreeType(mFreeTypeLibrary))
     return;
