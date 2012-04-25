--- gfx/thebes/gfxPlatform.cpp~	2012-02-07 11:59:39.717184907 +0000
+++ gfx/thebes/gfxPlatform.cpp	2012-02-07 13:06:01.084668445 +0000
@@ -446,6 +446,7 @@
   static_cast<SourceSurface*>(srcBuffer)->Release();
 }
 
+#ifdef MOZ_TREE_CAIRO
 void SourceSnapshotDetached(cairo_surface_t *nullSurf)
 {
   gfxImageSurface* origSurf =
@@ -453,6 +454,7 @@
 
   origSurf->SetData(&kSourceSurface, NULL, NULL);
 }
+#endif
 
 RefPtr<SourceSurface>
 gfxPlatform::GetSourceSurfaceForSurface(DrawTarget *aTarget, gfxASurface *aSurface)
@@ -522,6 +524,7 @@
                                                      imgSurface->Stride(),
                                                      format);
 
+    #ifdef MOZ_TREE_CAIRO
     cairo_surface_t *nullSurf =
 	cairo_null_surface_create(CAIRO_CONTENT_COLOR_ALPHA);
     cairo_surface_set_user_data(nullSurf,
@@ -530,6 +533,7 @@
 				NULL);
     cairo_surface_attach_snapshot(imgSurface->CairoSurface(), nullSurf, SourceSnapshotDetached);
     cairo_surface_destroy(nullSurf);
+    #endif
   }
 
   srcBuffer->AddRef();
