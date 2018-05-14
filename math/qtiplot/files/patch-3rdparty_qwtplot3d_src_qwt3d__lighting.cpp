--- 3rdparty/qwtplot3d/src/qwt3d_lighting.cpp.orig	2011-08-24 10:25:10 UTC
+++ 3rdparty/qwtplot3d/src/qwt3d_lighting.cpp
@@ -175,7 +175,7 @@ void ExtGLWidget::applyLight(unsigned li
   glRotatef( lights_[light].rot.x-90, 1.0, 0.0, 0.0 ); 
   glRotatef( lights_[light].rot.y   , 0.0, 1.0, 0.0 ); 
   glRotatef( lights_[light].rot.z   , 0.0, 0.0, 1.0 );
-  GLfloat lightPos[4] = { lights_[light].shift.x, lights_[light].shift.y, lights_[light].shift.z, 1.0};
+  GLfloat lightPos[4] = { static_cast<GLfloat>(lights_[light].shift.x), static_cast<GLfloat>(lights_[light].shift.y), static_cast<GLfloat>(lights_[light].shift.z), 1.0};
   GLenum le = lightEnum(light);
   glLightfv(le, GL_POSITION, lightPos);  
 }
