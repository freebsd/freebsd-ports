--- app/utility/base_world.py	2026-02-01 12:36:00.906543000 -0800
+++ app/utility/base_world.py	2026-02-01 12:36:44.181765000 -0800
@@ -12,9 +12,7 @@
 from enum import Enum
 
 import marshmallow as ma
-import marshmallow_enum as ma_enum
 
-
 class BaseWorld:
     """
     A collection of base static functions for service & object module usage
@@ -164,8 +162,8 @@
 
 
 class AccessSchema(ma.Schema):
-    access = ma_enum.EnumField(BaseWorld.Access)
+    access = ma.fields.Enum(BaseWorld.Access)
 
 
 class PrivilegesSchema(ma.Schema):
-    privilege = ma_enum.EnumField(BaseWorld.Privileges)
+    privilege = ma.fields.Enum(BaseWorld.Privileges)
