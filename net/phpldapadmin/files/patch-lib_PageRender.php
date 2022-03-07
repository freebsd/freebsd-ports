--- lib/PageRender.php.orig	2021-12-12 02:35:51 UTC
+++ lib/PageRender.php
@@ -827,7 +827,7 @@ class PageRender extends Visitor {
 		if (! $attribute->getOldValue($i))
 			return;
 
-		draw_jpeg_photo($this->getServer(),$this->template->getDN(),$attribute->getName(),$i,false,false);
+		draw_jpeg_photo($this->getServer(),$this->template->getDN(),$i,$attribute->getName(),false,false);
 	}
 
 	/**
@@ -844,16 +844,16 @@ class PageRender extends Visitor {
 		# If the attribute is modified, the new value needs to be stored in a session variable for the draw_jpeg_photo callback.
 		if ($attribute->hasBeenModified()) {
 			$_SESSION['tmp'][$attribute->getName()][$i] = $attribute->getValue($i);
-			draw_jpeg_photo(null,$this->template->getDN(),$attribute->getName(),$i,false,false);
+			draw_jpeg_photo(null,$this->template->getDN(),$i,$attribute->getName(),false,false);
 		} else
-			draw_jpeg_photo($this->getServer(),$this->template->getDN(),$attribute->getName(),$i,false,false);
+			draw_jpeg_photo($this->getServer(),$this->template->getDN(),$i,$attribute->getName(),false,false);
 	}
 
 	protected function drawFormReadOnlyValueJpegAttribute($attribute,$i) {
 		$this->draw('HiddenValue',$attribute,$i);
 		$_SESSION['tmp'][$attribute->getName()][$i] = $attribute->getValue($i);
 
-		draw_jpeg_photo(null,$this->template->getDN(),$attribute->getName(),$i,false,false);
+		draw_jpeg_photo(null,$this->template->getDN(),$i,$attribute->getName(),false,false);
 	}
 
 	protected function drawFormReadOnlyValueMultiLineAttribute($attribute,$i) {
