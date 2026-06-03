--- app/objects/secondclass/c_fact.py	2026-02-01 12:32:46.225935000 -0800
+++ app/objects/secondclass/c_fact.py	2026-02-01 12:33:53.068614000 -0800
@@ -2,7 +2,6 @@
 from enum import Enum
 
 import marshmallow as ma
-import marshmallow_enum as ma_enum
 
 from app.utility.base_object import BaseObject
 
@@ -47,7 +46,7 @@
     created = ma.fields.DateTime(format=BaseObject.TIME_FORMAT, dump_only=True)
     score = ma.fields.Integer()
     source = ma.fields.String(allow_none=True)
-    origin_type = ma_enum.EnumField(OriginType, allow_none=True)
+    origin_type = ma.fields.Enum(OriginType, allow_none=True)
     links = ma.fields.List(ma.fields.String())
     relationships = ma.fields.List(ma.fields.String())
     limit_count = ma.fields.Integer()
