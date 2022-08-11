--- archey/entries/model.py.orig	2022-05-17 21:03:36 UTC
+++ archey/entries/model.py
@@ -23,7 +23,8 @@ class Model(Entry):
             or self._fetch_dmi_info() \
             or self._fetch_sysctl_hw() \
             or self._fetch_raspberry_pi_revision() \
-            or self._fetch_android_device_model()
+            or self._fetch_android_device_model() \
+            or self._fetch_freebsd_model()
 
     def _fetch_virtual_env_info(self) -> Optional[str]:
         """
@@ -179,3 +180,20 @@ class Model(Entry):
             return None
 
         return f'{brand} ({model})'
+
+    @staticmethod
+    def _fetch_freebsd_model() -> Optional[str]:
+        """Retrieve `vendor` and `product` properties on FreeBSD """
+        try:
+            vendor = check_output(
+                ['kenv', 'smbios.bios.vendor'],
+                universal_newlines=True
+            ).rstrip()
+            product = check_output(
+                ['kenv', 'smbios.system.product'],
+                universal_newlines=True
+            ).rstrip()
+        except FileNotFoundError:
+            return None
+
+        return f'{vendor} ({product})'
