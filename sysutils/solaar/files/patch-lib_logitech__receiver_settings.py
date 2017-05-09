Solaar will die with a silent error when trying to configure devices like
e.g. the Logitech K400 that are detected as keyboards but also have
mouse settings for an integrated touchpad.  Remove the overly cautious
assert.

https://github.com/pwr/Solaar/issues/330

--- lib/logitech_receiver/settings.py.orig	2017-04-17 19:26:20 UTC
+++ lib/logitech_receiver/settings.py
@@ -61,7 +61,6 @@ class Setting(object):
 
 	def __call__(self, device):
 		assert not hasattr(self, '_value')
-		assert self.device_kind is None or self.device_kind == device.kind
 		p = device.protocol
 		if p == 1.0:
 			# HID++ 1.0 devices do not support features
