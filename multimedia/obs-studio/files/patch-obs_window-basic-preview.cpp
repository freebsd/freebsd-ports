--- obs/window-basic-preview.cpp.orig	2016-04-24 23:05:32 UTC
+++ obs/window-basic-preview.cpp
@@ -402,8 +402,8 @@ void OBSBasicPreview::mousePressEvent(QM
 	GetStretchHandleData(startPos);
 
 	vec2_divf(&startPos, &startPos, main->previewScale / pixelRatio);
-	startPos.x = std::round(startPos.x);
-	startPos.y = std::round(startPos.y);
+	startPos.x = ::round(startPos.x);
+	startPos.y = ::round(startPos.y);
 
 	mouseOverItems = SelectedAtPos(startPos);
 	vec2_zero(&lastMoveOffset);
@@ -692,8 +692,8 @@ void OBSBasicPreview::ClampAspect(vec3 &
 		size.y = size.x / baseAspect;
 	}
 
-	size.x = std::round(size.x);
-	size.y = std::round(size.y);
+	size.x = ::round(size.x);
+	size.y = ::round(size.y);
 
 	if (stretchFlags & ITEM_LEFT)
 		tl.x = br.x - size.x;
@@ -826,18 +826,18 @@ void OBSBasicPreview::CropItem(const vec
 	crop = startCrop;
 
 	if (stretchFlags & ITEM_LEFT)
-		crop.left += int(std::round(tl.x / scale.x));
+		crop.left += int(::round(tl.x / scale.x));
 	else if (stretchFlags & ITEM_RIGHT)
-		crop.right += int(std::round((stretchItemSize.x - br.x) / scale.x));
+		crop.right += int(::round((stretchItemSize.x - br.x) / scale.x));
 
 	if (stretchFlags & ITEM_TOP)
-		crop.top += int(std::round(tl.y / scale.y));
+		crop.top += int(::round(tl.y / scale.y));
 	else if (stretchFlags & ITEM_BOTTOM)
-		crop.bottom += int(std::round((stretchItemSize.y - br.y) / scale.y));
+		crop.bottom += int(::round((stretchItemSize.y - br.y) / scale.y));
 
 	vec3_transform(&newPos, &newPos, &itemToScreen);
-	newPos.x = std::round(newPos.x);
-	newPos.y = std::round(newPos.y);
+	newPos.x = ::round(newPos.x);
+	newPos.y = ::round(newPos.y);
 
 #if 0
 	vec3 curPos;
@@ -922,7 +922,7 @@ void OBSBasicPreview::StretchItem(const 
 	vec3_transform(&pos3, &pos3, &itemToScreen);
 
 	vec2 newPos;
-	vec2_set(&newPos, std::round(pos3.x), std::round(pos3.y));
+	vec2_set(&newPos, ::round(pos3.x), ::round(pos3.y));
 	obs_sceneitem_set_pos(stretchItem, &newPos);
 }
 
@@ -937,8 +937,8 @@ void OBSBasicPreview::mouseMoveEvent(QMo
 			mouseOverItems = SelectedAtPos(startPos);
 		}
 
-		pos.x = std::round(pos.x);
-		pos.y = std::round(pos.y);
+		pos.x = ::round(pos.x);
+		pos.y = ::round(pos.y);
 
 		if (stretchHandle != ItemHandle::None) {
 			if (cropping)
