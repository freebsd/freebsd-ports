--- nyx/panel/__init__.py.orig	2024-11-18 07:13:38 UTC
+++ nyx/panel/__init__.py
@@ -78,7 +78,7 @@ class KeyHandler(collections.namedtuple('Help', ['key'
       is_match = self._key_func(key) if self._key_func else key.match(self.key)
 
       if is_match:
-        if inspect.getargspec(self._action).args == ['key']:
+        if inspect.getfullargspec(self._action).args == ['key']:
           self._action(key)
         else:
           self._action()
