Fixes unittests with net-mgmt/py-junos-eznc >= 2.3.0

See also:
https://github.com/napalm-automation/napalm/issues/1060

--- test/junos/conftest.py.orig	2019-10-10 10:31:18 UTC
+++ test/junos/conftest.py
@@ -77,6 +77,10 @@ class FakeJunOSDevice(BaseTestDouble):
         }
         self._uptime = 4380
 
+        # Since junos-eznc 2.3.0 the new SAX parser is used as default. Thus
+        # disable it to use the DOM parser which was used prior.
+        self._use_filter = False
+
     @property
     def facts(self):
         # we want to reinitialize it every time to avoid side effects
