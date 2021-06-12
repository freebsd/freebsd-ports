Why is this patch needed?

--- UI/window-basic-preview.cpp.orig	2021-06-11 14:20:50 UTC
+++ UI/window-basic-preview.cpp
@@ -577,8 +577,8 @@ void OBSBasicPreview::mousePressEvent(QMouseEvent *eve
 	GetStretchHandleData(startPos, false);
 
 	vec2_divf(&startPos, &startPos, main->previewScale / pixelRatio);
-	startPos.x = std::round(startPos.x);
-	startPos.y = std::round(startPos.y);
+	startPos.x = ::round(startPos.x);
+	startPos.y = ::round(startPos.y);
 
 	mouseOverItems = SelectedAtPos(startPos);
 	vec2_zero(&lastMoveOffset);
@@ -1228,8 +1228,8 @@ void OBSBasicPreview::ClampAspect(vec3 &tl, vec3 &br, 
 			size.y = size.x / baseAspect * -1.0f;
 	}
 
-	size.x = std::round(size.x);
-	size.y = std::round(size.y);
+	size.x = ::round(size.x);
+	size.y = ::round(size.y);
 
 	if (stretchFlags & ITEM_LEFT)
 		tl.x = br.x - size.x;
@@ -1470,7 +1470,7 @@ void OBSBasicPreview::StretchItem(const vec2 &pos)
 	vec3_transform(&pos3, &pos3, &itemToScreen);
 
 	vec2 newPos;
-	vec2_set(&newPos, std::round(pos3.x), std::round(pos3.y));
+	vec2_set(&newPos, ::round(pos3.x), ::round(pos3.y));
 	obs_sceneitem_set_pos(stretchItem, &newPos);
 }
 
@@ -1501,8 +1501,8 @@ void OBSBasicPreview::mouseMoveEvent(QMouseEvent *even
 			mouseOverItems = SelectedAtPos(startPos);
 		}
 
-		pos.x = std::round(pos.x);
-		pos.y = std::round(pos.y);
+		pos.x = ::round(pos.x);
+		pos.y = ::round(pos.y);
 
 		if (stretchHandle != ItemHandle::None) {
 			selectionBox = false;
