
$FreeBSD$

--- lib/ansible/modules/extras/messaging/rabbitmq_user.py.orig
+++ lib/ansible/modules/extras/messaging/rabbitmq_user.py
@@ -162,7 +162,11 @@
         return dict()
 
     def add(self):
-        self._exec(['add_user', self.username, self.password])
+        if self.password is not None:
+            self._exec(['add_user', self.username, self.password])
+        else:
+            self._exec(['add_user', self.username, ''])
+            self._exec(['clear_password', self.username])
 
     def delete(self):
         self._exec(['delete_user', self.username])
