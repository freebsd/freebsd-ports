
$FreeBSD$

--- gfx/src/x11shared/nsFreeType.cpp.orig	Fri Mar  1 00:37:13 2002
+++ gfx/src/x11shared/nsFreeType.cpp	Mon Mar 18 21:11:36 2002
@@ -1340,12 +1340,20 @@
 nsFreeTypeFace *
 nsFreeTypeGetFaceID(nsFontCatalogEntry *aFce)
 {
-  // in this hash each ttc face has a unique key
-  nsCStringKey key(nsFT2FontCatalog::GetFamilyName(aFce));
+  // We need to have separate keys for the different faces in a ttc file.
+  // We append a slash and the face index to the file name to give us a 
+  // unique key for each ttc face.
+  nsCAutoString key_str(nsFT2FontCatalog::GetFileName(aFce));
+  char buf[20];
+  sprintf(buf, "/%d", nsFT2FontCatalog::GetFaceIndex(aFce));
+  key_str.Append(buf);
+  nsCStringKey key(key_str);
   nsFreeTypeFace *face = (nsFreeTypeFace *)gFreeTypeFaces->Get(&key);
   if (!face) {
     face = new nsFreeTypeFace(aFce);
     NS_ASSERTION(face, "memory error while creating nsFreeTypeFace");
+    if (!face)
+      return nsnull;
     gFreeTypeFaces->Put(&key, face);
   }
   return face;
