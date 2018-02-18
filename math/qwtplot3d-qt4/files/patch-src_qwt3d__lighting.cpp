src/qwt3d_lighting.cpp:178:27: error: non-constant-expression cannot be narrowed from type 'double' to 
'GLfloat' (aka 'float') in initializer list [-Wc++11-narrowing]
  GLfloat lightPos[4] = { lights_[light].shift.x, lights_[light].shift.y, lights_[light].shift.z, 1.0};
                          ^~~~~~~~~~~~~~~~~~~~~~
src/qwt3d_lighting.cpp:178:27: note: insert an explicit cast to silence this issue


--- src/qwt3d_lighting.cpp.orig	2018-02-17 23:11:11 UTC
+++ src/qwt3d_lighting.cpp
@@ -175,7 +175,7 @@ void Plot3D::applyLight(unsigned light)
   glRotatef( lights_[light].rot.x-90, 1.0, 0.0, 0.0 ); 
   glRotatef( lights_[light].rot.y   , 0.0, 1.0, 0.0 ); 
   glRotatef( lights_[light].rot.z   , 0.0, 0.0, 1.0 );
-  GLfloat lightPos[4] = { lights_[light].shift.x, lights_[light].shift.y, lights_[light].shift.z, 1.0};
+  GLfloat lightPos[4] = { static_cast<GLfloat>(lights_[light].shift.x), static_cast<GLfloat>(lights_[light].shift.y), static_cast<GLfloat>(lights_[light].shift.z), 1.0};
   GLenum le = lightEnum(light);
   glLightfv(le, GL_POSITION, lightPos);  
 }
