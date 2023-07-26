--- wxVillaLib/ThumbnailFactory.cpp	2023-07-24 10:21:13.152544000 +0100
+++ wxVillaLib/ThumbnailFactory.cpp	2023-07-24 10:18:45.440168000 +0100
@@ -363,7 +363,7 @@
 				img = decoder.GetNextFrame();
 		}
 		if (img.Ok() && decoder.GetFrameAspectRatio() > 0 
-				&& labs(decoder.GetFrameAspectRatio()*100 - img.GetWidth()*100/img.GetHeight()) >= 5) {
+				&& std::abs(decoder.GetFrameAspectRatio()*100 - img.GetWidth()*100/img.GetHeight()) >= 5) {
 			if (lround(img.GetWidth() / decoder.GetFrameAspectRatio()) > img.GetHeight())
 				img.Rescale(img.GetWidth(), lround(img.GetWidth() / decoder.GetFrameAspectRatio()));
 			else
