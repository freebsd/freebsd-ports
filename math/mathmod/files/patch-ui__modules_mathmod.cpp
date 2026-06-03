--- ui_modules/mathmod.cpp.orig	2026-05-04 10:52:41 UTC
+++ ui_modules/mathmod.cpp
@@ -1665,7 +1665,7 @@ void MathMod::CopyData(ObjectProperties *scene)
     {
         glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
-        if(scene->VertxNumber>previousVertxNumber>0)
+        if((scene->VertxNumber>previousVertxNumber) && (scene->VertxNumber>0))
         {
             glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT)*10*(scene->VertxNumber+(12+60+36)), scene->ArrayNorVer_localPt, GL_STATIC_DRAW);
             previousVertxNumber = scene->VertxNumber;
@@ -1676,7 +1676,8 @@ void MathMod::CopyData(ObjectProperties *scene)
             previousVertxNumber = scene->VertxNumber;
         }
 
-        if((scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize)>previousPolyNumberNbPolygnNbVertexPtMin)
+        if(((scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize)>previousPolyNumberNbPolygnNbVertexPtMin) &&
+            ((scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize)>0))
         {
             glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*(scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize), scene->PolyIndices_localPt, GL_STATIC_DRAW);
             previousPolyNumberNbPolygnNbVertexPtMin =  (scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize);
