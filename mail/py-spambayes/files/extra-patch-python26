--- spambayes/Dibbler.py~	2009-07-10 21:43:59.000000000 +0200
+++ spambayes/Dibbler.py	2009-07-10 21:44:37.655326444 +0200
@@ -218,7 +218,7 @@
         # self.initiate_send() raises an exception, causing self.close()
         # to be called.  If we didn't check, we could end up in an infinite
         # loop.
-        while (self.producer_fifo or self.ac_out_buffer) and not self._closed:
+        while (self.producer_fifo) and not self._closed:
             self.initiate_send()
 
     def close(self):
