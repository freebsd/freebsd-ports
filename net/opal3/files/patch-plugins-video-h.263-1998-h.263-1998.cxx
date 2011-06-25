--- plugins/video/H.263-1998/h263-1998.cxx.orig	2009-09-22 02:57:52.000000000 +0200
+++ plugins/video/H.263-1998/h263-1998.cxx	2011-06-25 11:37:56.719449353 +0200
@@ -688,7 +688,8 @@
 
   _inputFrame->data[1] = _inputFrame->data[0] + size;
   _inputFrame->data[2] = _inputFrame->data[1] + (size / 4);
-  _inputFrame->pict_type = (flags && forceIFrame) ? FF_I_TYPE : 0;
+  if (flags && forceIFrame)
+    _inputFrame->pict_type = FF_I_TYPE;
 
   currentMb = 0;
   currentBytes = 0;
@@ -885,7 +886,8 @@
   _inputFrame->data[0] = _inputFrameBuffer + FF_INPUT_BUFFER_PADDING_SIZE;
   _inputFrame->data[1] = _inputFrame->data[0] + size;
   _inputFrame->data[2] = _inputFrame->data[1] + (size / 4);
-  _inputFrame->pict_type = (flags && forceIFrame) ? FF_I_TYPE : 0;
+  if (flags && forceIFrame)
+    _inputFrame->pict_type = FF_I_TYPE;
  
   _txH263PFrame->BeginNewFrame();
   _txH263PFrame->SetTimestamp(srcRTP.GetTimestamp());
