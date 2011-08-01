--- libpb/builder.py
+++ libpb/builder.py
@@ -425,7 +425,7 @@ class StageBuilder(Builder):
         assert not port.dependency.check(self.stage)
         del self._pending[port]
         if self._port_check(port):
-            assert port.stage == self.stage - 1
+            assert port.stage == self.stage - 1 or self.stage > Port.PACKAGE
             self.update.emit(self, Builder.QUEUED, port)
             self.ports[port].started.connect(self._started)
             self.queue.add(self.ports[port])
