--- xpdf/GfxState.cc.orig	Wed Jun 25 00:41:27 2003
+++ xpdf/GfxState.cc	Tue Jan 11 18:21:14 2005
@@ -708,6 +708,11 @@
   }
   nCompsA = obj2.getInt();
   obj2.free();
+  if (nCompsA > gfxColorMaxComps) {
+    error(-1, "ICCBased color space with too many (%d > %d) components",
+	  nCompsA, gfxColorMaxComps);
+    nCompsA = gfxColorMaxComps;
+  }
   if (dict->lookup("Alternate", &obj2)->isNull() ||
       !(altA = GfxColorSpace::parse(&obj2))) {
     switch (nCompsA) {
