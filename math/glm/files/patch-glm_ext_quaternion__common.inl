--- glm/ext/quaternion_common.inl.orig	2020-04-13 17:41:16 UTC
+++ glm/ext/quaternion_common.inl
@@ -104,7 +104,7 @@ namespace glm
         {
             // Graphics Gems III, page 96
             T angle = acos(cosTheta);
-            T phi = angle + k * glm::pi<T>();
+            T phi = angle + static_cast<T>(k) * glm::pi<T>();
             return (sin(angle - a * phi)* x + sin(a * phi) * z) / sin(angle);
         }
     }
