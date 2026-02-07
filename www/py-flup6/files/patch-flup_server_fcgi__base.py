--- flup/server/fcgi_base.py	2015-08-01 02:01:48 UTC
+++ flup/server/fcgi_base.py	
@@ -49,9 +49,11 @@ thread_available = True
 if sys.hexversion >= 0x03000000:
     text_type = str
     force_str = lambda s: s.decode('latin-1')
+    py3k = True
 else:
     text_type = unicode
     force_str = lambda s: s
+    py3k = False
 
 # Apparently 2.3 doesn't define SHUT_WR? Assume it is 1 in this case.
 if not hasattr(socket, 'SHUT_WR'):
@@ -601,9 +603,14 @@ class CGIRequest(Request):
         
         self.server = server
         self.params = dict(os.environ)
-        self.stdin = sys.stdin.buffer
-        self.stdout = StdoutWrapper(sys.stdout.buffer) # Oh, the humanity!
-        self.stderr = sys.stderr.buffer
+        if py3k:
+            self.stdin = sys.stdin.buffer
+            self.stdout = StdoutWrapper(sys.stdout.buffer) # Oh, the humanity!
+            self.stderr = sys.stderr.buffer
+        else:
+            self.stdin = sys.stdin
+            self.stdout = StdoutWrapper(sys.stdout) # Oh, the humanity!
+            self.stderr = sys.stderr
         self.data = BytesIO()
         
     def _end(self, appStatus=0, protocolStatus=FCGI_REQUEST_COMPLETE):
