--- xpdf/Gfx.cc.orig	Wed Jun 25 00:41:27 2003
+++ xpdf/Gfx.cc	Tue Jan 11 18:21:14 2005
@@ -2381,7 +2381,9 @@
     haveMask = gFalse;
     dict->lookup("Mask", &maskObj);
     if (maskObj.isArray()) {
-      for (i = 0; i < maskObj.arrayGetLength(); ++i) {
+      for (i = 0;
+	   i < maskObj.arrayGetLength() && i < 2*gfxColorMaxComps;
+	   ++i) {
 	maskObj.arrayGet(i, &obj1);
 	maskColors[i] = obj1.getInt();
 	obj1.free();
