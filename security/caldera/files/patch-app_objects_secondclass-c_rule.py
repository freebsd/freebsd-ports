--- app/objects/secondclass/c_rule.py	2026-02-01 12:29:45.348469000 -0800
+++ app/objects/secondclass/c_rule.py	2026-02-01 12:31:22.350284000 -0800
@@ -1,5 +1,4 @@
 import marshmallow as ma
-import marshmallow_enum as ma_enum
 
 from app.utility.base_object import BaseObject
 from app.utility.rule_set import RuleAction
@@ -7,7 +6,7 @@
 
 class RuleSchema(ma.Schema):
 
-    action = ma_enum.EnumField(RuleAction, required=True)
+    action = ma.fields.Enum(RuleAction, required=True)
     trait = ma.fields.String(required=True)
     match = ma.fields.String()
 
