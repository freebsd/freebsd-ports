--- gfx/src/ps/nsType1.cpp.orig	Wed Dec 11 01:24:47 2002
+++ gfx/src/ps/nsType1.cpp	Sun Sep 10 09:52:45 2006
@@ -81,8 +81,8 @@
   int            wmode;
 } FT2PT1_info;
 
-static int cubicto(FT_Vector *aControlPt1, FT_Vector *aControlPt2, 
-                   FT_Vector *aEndPt, void *aClosure);
+static int cubicto(const FT_Vector *aControlPt1, const FT_Vector *aControlPt2, 
+                   const FT_Vector *aEndPt, void *aClosure);
 static int Type1CharStringCommand(unsigned char **aBufPtrPtr, int aCmd);
 static int Type1EncodeCharStringInt(unsigned char **aBufPtrPtr, int aValue);
 
@@ -173,7 +173,7 @@
 }
 
 static PRBool
-sideWidthAndBearing(FT_Vector *aEndPt, FT2PT1_info *aFti)
+sideWidthAndBearing(const FT_Vector *aEndPt, FT2PT1_info *aFti)
 {
   int aw = 0;
   int ah = 0;
@@ -216,7 +216,7 @@
 }
 
 static int
-moveto(FT_Vector *aEndPt, void *aClosure)
+moveto(const FT_Vector *aEndPt, void *aClosure)
 {
   FT2PT1_info *fti = (FT2PT1_info *)aClosure;
   FT_UShort upm = fti->face->units_per_EM;
@@ -253,7 +253,7 @@
 }
 
 static int
-lineto(FT_Vector *aEndPt, void *aClosure)
+lineto(const FT_Vector *aEndPt, void *aClosure)
 {
   FT2PT1_info *fti = (FT2PT1_info *)aClosure;
   FT_UShort upm = fti->face->units_per_EM;
@@ -279,7 +279,7 @@
 }
 
 static int
-conicto(FT_Vector *aControlPt, FT_Vector *aEndPt, void *aClosure)
+conicto(const FT_Vector *aControlPt, const FT_Vector *aEndPt, void *aClosure)
 {
   FT2PT1_info *ftinfo = (FT2PT1_info *)aClosure;
   FT_UShort upm = ftinfo->face->units_per_EM;
@@ -311,7 +311,7 @@
 }
 
 static int
-cubicto(FT_Vector *aControlPt1, FT_Vector *aControlPt2, FT_Vector *aEndPt,
+cubicto(const FT_Vector *aControlPt1, const FT_Vector *aControlPt2, const FT_Vector *aEndPt,
         void *aClosure)
 {
   FT2PT1_info *ftinfo = (FT2PT1_info *)aClosure;
