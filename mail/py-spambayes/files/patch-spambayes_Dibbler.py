--- spambayes/Dibbler.py.orig	2013-02-06 11:28:18 UTC
+++ spambayes/Dibbler.py
@@ -215,7 +215,7 @@ class BrighterAsyncChat(asynchat.async_c
         # self.initiate_send() raises an exception, causing self.close()
         # to be called.  If we didn't check, we could end up in an infinite
         # loop.
-        while (self.producer_fifo or self.ac_out_buffer) and not self._closed:
+        while (self.producer_fifo) and not self._closed:
             self.initiate_send()
 
     def close(self):
