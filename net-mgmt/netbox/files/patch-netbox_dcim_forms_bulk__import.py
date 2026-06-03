Add Python 3.11 compatibility

--- netbox/dcim/forms/bulk_import.py.orig	2026-04-17 13:34:58 UTC
+++ netbox/dcim/forms/bulk_import.py
@@ -1518,7 +1518,7 @@ class CableImportForm(PrimaryModelImportForm):
         if data:
             # Limit choices for side_a_device to the assigned side_a_site
             if side_a_site := data.get('side_a_site'):
-                side_a_parent_params = {f'site__{self.fields['side_a_site'].to_field_name}': side_a_site}
+                side_a_parent_params = {f'site__{self.fields["side_a_site"].to_field_name}': side_a_site}
                 self.fields['side_a_device'].queryset = self.fields['side_a_device'].queryset.filter(
                     **side_a_parent_params
                 )
@@ -1528,7 +1528,7 @@ class CableImportForm(PrimaryModelImportForm):
 
             # Limit choices for side_b_device to the assigned side_b_site
             if side_b_site := data.get('side_b_site'):
-                side_b_parent_params = {f'site__{self.fields['side_b_site'].to_field_name}': side_b_site}
+                side_b_parent_params = {f'site__{self.fields["side_b_site"].to_field_name}': side_b_site}
                 self.fields['side_b_device'].queryset = self.fields['side_b_device'].queryset.filter(
                     **side_b_parent_params
                 )
