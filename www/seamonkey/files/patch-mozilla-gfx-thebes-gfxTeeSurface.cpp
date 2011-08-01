diff --git a/gfx/thebes/gfxTeeSurface.cpp b/gfx/thebes/gfxTeeSurface.cpp
--- mozilla/gfx/thebes/gfxTeeSurface.cpp
+++ mozilla/gfx/thebes/gfxTeeSurface.cpp
@@ -47,4 +47,5 @@ gfxTeeSurface::gfxTeeSurface(cairo_surfa
 gfxTeeSurface::gfxTeeSurface(gfxASurface **aSurfaces, PRInt32 aSurfaceCount)
 {
+#ifdef MOZ_TREE_CAIRO
     NS_ASSERTION(aSurfaceCount > 0, "Must have a least one surface");
     cairo_surface_t *csurf = cairo_tee_surface_create(aSurfaces[0]->CairoSurface());
@@ -54,4 +55,5 @@ gfxTeeSurface::gfxTeeSurface(gfxASurface
         cairo_tee_surface_add(csurf, aSurfaces[i]->CairoSurface());
     }
+#endif
 }
 
@@ -59,6 +61,8 @@ const gfxIntSize
 gfxTeeSurface::GetSize() const
 {
+#ifdef MOZ_TREE_CAIRO
     nsRefPtr<gfxASurface> master = Wrap(cairo_tee_surface_index(mSurface, 0));
     return master->GetSize();
+#endif
 }
 
@@ -66,4 +70,5 @@ void
 gfxTeeSurface::GetSurfaces(nsTArray<nsRefPtr<gfxASurface> >* aSurfaces)
 {
+#ifdef MOZ_TREE_CAIRO
     for (PRInt32 i = 0; ; ++i) {
         cairo_surface_t *csurf = cairo_tee_surface_index(mSurface, i);
@@ -75,3 +80,4 @@ gfxTeeSurface::GetSurfaces(nsTArray<nsRe
         *elem = Wrap(csurf);
     }
+#endif
 }

