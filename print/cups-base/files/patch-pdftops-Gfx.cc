diff -ruN pdftops/Gfx.cxx /home/josef//temp/pdftops/Gfx.cxx
--- pdftops/Gfx.cxx	Fri Apr  9 22:18:31 2004
+++ /home/josef//temp/pdftops/Gfx.cxx	Fri Dec 24 20:21:32 2004
@@ -2655,7 +2655,9 @@
     haveMask = gFalse;
     dict->lookup("Mask", &maskObj);
     if (maskObj.isArray()) {
-      for (i = 0; i < maskObj.arrayGetLength(); ++i) {
+      for (i = 0;
+	  i < maskObj.arrayGetLength() && i < 2*gfxColorMaxComps;
+	  ++i) {
 	maskObj.arrayGet(i, &obj1);
 	maskColors[i] = obj1.getInt();
 	obj1.free();
diff -ruN pdftops/GfxState.cxx /home/josef//temp/pdftops/GfxState.cxx
--- pdftops/GfxState.cxx	Mon Feb  2 23:41:09 2004
+++ /home/josef//temp/pdftops/GfxState.cxx	Fri Dec 24 20:21:32 2004
@@ -708,6 +708,11 @@
   }
   nCompsA = obj2.getInt();
   obj2.free();
+  if (nCompsA > gfxColorMaxComps) {
+    error(-1, "ICCBased color space with too many (%d > %d) components",
+    nCompsA, gfxColorMaxComps);
+    nCompsA = gfxColorMaxComps;
+  }
   if (dict->lookup("Alternate", &obj2)->isNull() ||
       !(altA = GfxColorSpace::parse(&obj2))) {
     switch (nCompsA) {
