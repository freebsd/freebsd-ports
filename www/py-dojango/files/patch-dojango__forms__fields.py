--- ./dojango/forms/fields.py.orig	2011-04-14 15:25:02.000000000 -0700
+++ ./dojango/forms/fields.py	2011-09-26 17:14:30.353122595 -0700
@@ -6,8 +6,7 @@
 from dojango.util import json_encode
 
 __all__ = (
-    'Field', 'DEFAULT_DATE_INPUT_FORMATS', 'DEFAULT_TIME_INPUT_FORMATS', # original django classes
-    'DEFAULT_DATETIME_INPUT_FORMATS', 'MultiValueField', 'ComboField', # original django classes
+    'Field', 'MultiValueField', 'ComboField', # original django classes
     'DojoFieldMixin', 'CharField', 'ChoiceField', 'TypedChoiceField',
     'IntegerField', 'BooleanField', 'FileField', 'ImageField',
     'DateField', 'TimeField', 'DateTimeField', 'SplitDateTimeField',
@@ -74,26 +73,30 @@
 class ImageField(DojoFieldMixin, fields.ImageField):
     widget = widgets.FileInput
 
+# also support dojo's default date-string
+dj_settings.DATE_INPUT_FORMATS = tuple(list(dj_settings.DATE_INPUT_FORMATS) + [
+        '%Y-%m-%dT%H:%M', '%Y-%m-%dT%H:%M:%S'
+        ])
+
 class DateField(DojoFieldMixin, fields.DateField):
     widget = widgets.DateInput
     
     def __init__(self, input_formats=None, min_value=None, max_value=None, *args, **kwargs):
-        kwargs['input_formats'] = input_formats or \
-            tuple(list(formats.get_format('DATE_INPUT_FORMATS')) + [
-                '%Y-%m-%dT%H:%M', '%Y-%m-%dT%H:%M:%S' # also support dojo's default date-strings
-            ])
+        kwargs['input_formats'] = input_formats or formats.get_format('DATE_INPUT_FORMATS')
         self.max_value = max_value
         self.min_value = min_value
         super(DateField, self).__init__(*args, **kwargs)
 
+# also support dojo's default date-string
+dj_settings.TIME_INPUT_FORMATS = tuple(list(dj_settings.TIME_INPUT_FORMATS) + [
+        '%Y-%m-%dT%H:%M', '%Y-%m-%dT%H:%M:%S', 'T%H:%M:%S', 'T%H:%M'
+        ])
+
 class TimeField(DojoFieldMixin, fields.TimeField):
     widget = widgets.TimeInput
     
     def __init__(self, input_formats=None, min_value=None, max_value=None, *args, **kwargs):
-        kwargs['input_formats'] = input_formats or \
-            tuple(list(formats.get_format('TIME_INPUT_FORMATS')) + [
-                '%Y-%m-%dT%H:%M', '%Y-%m-%dT%H:%M:%S', 'T%H:%M:%S', 'T%H:%M' # also support dojo's default time-strings
-            ])
+        kwargs['input_formats'] = input_formats or formats.get_format('TIME_INPUT_FORMATS')
         self.max_value = max_value
         self.min_value = min_value
         super(TimeField, self).__init__(*args, **kwargs)
