--- parser/PyPlucker/Writer.py.bak	Tue Oct 15 14:47:39 2002
+++ parser/PyPlucker/Writer.py	Fri Jan 31 15:18:09 2003
@@ -81,7 +81,7 @@
         self._current_id = 11
 
         # make sure record number 2 goes to the 'home' document (why?)
-        url = self._alias_list.get('plucker:/home.html')
+        url = self._alias_list.get('plucker:///home.html')
         if url:
             while self._alias_list.has_key(url):
                 url = self._alias_list.get(url)
@@ -91,7 +91,7 @@
             else:
                 self._url_to_id_mapping[url] = 2
         else:
-            doc = self._url_to_doc_mapping.get('plucker:/home.html')
+            doc = self._url_to_doc_mapping.get('plucker:///home.html')
             if doc:
                 self._doc_to_id_mapping[doc] = 2
             else:
