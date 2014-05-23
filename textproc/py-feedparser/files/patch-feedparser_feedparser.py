--- feedparser/feedparser.py.orig	2014-03-10 01:45:12.000000000 +0900
+++ feedparser/feedparser.py	2014-03-10 01:45:53.000000000 +0900
@@ -3766,7 +3766,11 @@
     chardet_encoding = None
     tried_encodings = []
     if chardet:
-        chardet_encoding = unicode(chardet.detect(data)['encoding'] or '', 'ascii', 'ignore')
+        chardet_encoding = chardet.detect(data)['encoding']
+        if not chardet_encoding:
+            chardet_encoding = ''
+        if not isinstance(chardet_encoding, str):
+            chardet_encoding = str(chardet_encoding, 'ascii', 'ignore')
     # try: HTTP encoding, declared XML encoding, encoding sniffed from BOM
     for proposed_encoding in (rfc3023_encoding, xml_encoding, bom_encoding,
                               chardet_encoding, u'utf-8', u'windows-1252', u'iso-8859-2'):
