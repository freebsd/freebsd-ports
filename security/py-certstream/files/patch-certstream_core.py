--- certstream/core.py.orig	2018-03-02 11:20:56 UTC
+++ certstream/core.py
@@ -27,12 +27,12 @@ class CertStreamClient(WebSocketApp):
             on_error=self._on_error,
         )
 
-    def _on_open(self, instance):
+    def _on_open(self):
         logging.info("Connection established to CertStream! Listening for events...")
         if self.on_open_handler:
-            self.on_open_handler(instance)
+            self.on_open_handler()
 
-    def _on_message(self, _, message):
+    def _on_message(self, message):
         frame = json.loads(message)
 
         if frame.get('message_type', None) == "heartbeat" and self.skip_heartbeats:
@@ -40,11 +40,11 @@ class CertStreamClient(WebSocketApp):
 
         self.message_callback(frame, self._context)
 
-    def _on_error(self, instance, ex):
+    def _on_error(self, ex):
         if type(ex) == KeyboardInterrupt:
             raise
         if self.on_error_handler:
-            self.on_error_handler(instance, ex)
+            self.on_error_handler(ex)
         logging.error("Error connecting to CertStream - {} - Sleeping for a few seconds and trying again...".format(ex))
 
 def listen_for_events(message_callback, url, skip_heartbeats=True, setup_logger=True, on_open=None, on_error=None, **kwargs):
