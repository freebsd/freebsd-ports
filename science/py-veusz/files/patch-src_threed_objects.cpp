--- src/threed/objects.cpp.orig	2023-03-08 19:51:09 UTC
+++ src/threed/objects.cpp
@@ -177,7 +177,7 @@ void Mesh::getLineFragments(const Mat4& perspM, const 
       if(hidehorzline && stepindex==0) continue;
       if(hidevertline && stepindex==1) continue;
 
-      const ValVector& vec_step = stepindex==0 ? pos1 : pos2;
+      const ValVector& vec_step_ = stepindex==0 ? pos1 : pos2;
       const ValVector& vec_const = stepindex==0 ? pos2 : pos1;
       const unsigned vidx_step = stepindex==0 ? vidx_1 : vidx_2;
       const unsigned vidx_const = stepindex==0 ? vidx_2 : vidx_1;
@@ -185,10 +185,10 @@ void Mesh::getLineFragments(const Mat4& perspM, const 
       for(unsigned consti=0; consti<vec_const.size(); ++consti)
         {
           pt(vidx_const) = vec_const[consti];
-          for(unsigned stepi=0; stepi<vec_step.size(); ++stepi)
+          for(unsigned stepi=0; stepi<vec_step_.size(); ++stepi)
             {
               double heightsval = heights[stepindex==0 ? stepi*n2+consti : consti*n2+stepi];
-              pt(vidx_step) = vec_step[stepi];
+              pt(vidx_step) = vec_step_[stepi];
               pt(vidx_h) = heightsval;
 
               // shuffle new to old positions and calculate new new
