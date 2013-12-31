--- dojango/forms/fields.py.orig	2013-12-31 14:27:55.320053693 +0000
+++ dojango/forms/fields.py	2013-12-31 14:28:29.718050373 +0000
@@ -61,9 +61,13 @@
     widget = widgets.Select
 
 class IntegerField(DojoFieldMixin, fields.IntegerField):
-    widget = widgets.NumberTextInput
     decimal_places = 0
 
+    def __init__(self, *args, **kwargs):
+        if 'widget' not in kwargs:
+            kwargs['widget'] = widgets.NumberTextInput
+        super(IntegerField, self).__init__(*args, **kwargs)
+
 class BooleanField(DojoFieldMixin, fields.BooleanField):
     widget = widgets.CheckboxInput
 
