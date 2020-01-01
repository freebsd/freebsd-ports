Fix AttributeError exception in API docs when accessing api/docs

Obtained from:

https://github.com/netbox-community/netbox/commit/55b503da5bdf2a95e903fb657ade195ff89cae91

--- netbox/extras/api/customfields.py.orig	2019-12-16 21:32:00 UTC
+++ netbox/extras/api/customfields.py
@@ -124,6 +124,9 @@ class CustomFieldModelSerializer(ValidatedModelSeriali
 
         else:
 
+            if not hasattr(self, 'initial_data'):
+                self.initial_data = {}
+
             # Populate default values
             if fields and 'custom_fields' not in self.initial_data:
                 self.initial_data['custom_fields'] = {}
