--- ./qtvid.cxx.orig	2008-03-02 22:45:11.000000000 +0800
+++ ./qtvid.cxx	2008-03-02 22:45:59.000000000 +0800
@@ -263,21 +263,7 @@
  
 BOOL PTextVideoInputDevice::GetFrameData(BYTE *buffer, PINDEX *bytesReturned)
 {
-  if(frameRate>0) {
-    frameTimeError += msBetweenFrames;
-    
-    do {
-      if ( !GetFrameDataNoDelay(buffer, bytesReturned)) {
-          return FALSE;
-        }
-      PTime now;
-      PTimeInterval delay = now - previousFrameTime;
-      frameTimeError -= (int)delay.GetMilliSeconds();
-      previousFrameTime = now;
-    }  while(frameTimeError > 0) ;
- 
-    return TRUE;
-  }
+  m_pacing.Delay(1000/GetFrameRate());
   return GetFrameDataNoDelay(buffer, bytesReturned);
 }
 
