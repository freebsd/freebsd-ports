#https://bugzilla.mozilla.org/show_bug.cgi?id=1853867
#https://aur.archlinux.org/cgit/aur.git/commit/unity-menubar.patch?h=firefox-appmenu&id=1ab4aad0eaaa2f5313aee62606420b0b92c3d238
--- widget/gtk/nsMenuObject.cpp.orig	2023-10-06 21:50:32.804805000 +0200
+++ widget/gtk/nsMenuObject.cpp	2023-10-06 21:11:59.559090000 +0200
@@ -82,7 +82,7 @@
     nsMenuObject *mOwner;
     RefPtr<imgRequestProxy> mImageRequest;
     nsCOMPtr<nsIURI> mURI;
-    nsIntRect mImageRect;
+
 };
 
 NS_IMPL_ISUPPORTS(nsMenuObjectIconLoader, imgINotificationObserver)
@@ -136,10 +136,8 @@
         return;
     }
 
-    if (!mImageRect.IsEmpty()) {
-        img = ImageOps::Clip(img, mImageRect);
-    }
 
+
     int32_t width, height;
     img->GetWidth(&width);
     img->GetHeight(&height);
@@ -174,7 +172,7 @@
     dom::Document *doc = mOwner->ContentNode()->OwnerDoc();
 
     nsCOMPtr<nsIURI> uri;
-    nsIntRect imageRect;
+
     imgRequestProxy *imageRequest = nullptr;
 
     nsAutoString uriString;
@@ -197,9 +195,6 @@
         imageRequest = list->mListStyleImage.GetImageRequest();
         if (imageRequest) {
             imageRequest->GetURI(getter_AddRefs(uri));
-            auto& rect = list->mImageRegion.AsRect();
-            imageRect = rect.ToLayoutRect().ToNearestPixels(
-                            pc->AppUnitsPerDevPixel());
         }
     }
 
@@ -217,7 +212,7 @@
 
     bool same;
     if (mURI && NS_SUCCEEDED(mURI->Equals(uri, &same)) && same &&
-        (!imageRequest || imageRect == mImageRect)) {
+        (!imageRequest)) {
         return;
     }
 
@@ -229,10 +224,10 @@
     mURI = uri;
 
     if (imageRequest) {
-        mImageRect = imageRect;
+
         imageRequest->Clone(this, nullptr, getter_AddRefs(mImageRequest));
     } else {
-        mImageRect.SetEmpty();
+
         nsCOMPtr<nsILoadGroup> loadGroup = doc->GetDocumentLoadGroup();
         RefPtr<imgLoader> loader =
             nsContentUtils::GetImgLoaderForDocument(doc);
