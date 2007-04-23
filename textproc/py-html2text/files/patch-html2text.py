--- html2text.py.orig	2007-01-18 19:06:49.000000000 -0500
+++ html2text.py
@@ -150,7 +150,7 @@ class _html2text(sgmllib.SGMLParser):
 		self.lastWasNL = 0
 	
 	def outtextf(self, s): 
-		if type(s) is type(''): s = codecs.utf_8_decode(s)[0]
+		if type(s) is type(''): s = codecs.utf_8_decode(s, "replace")[0]
 		self.outtext += s
 	
 	def close(self):
@@ -259,6 +259,7 @@ class _html2text(sgmllib.SGMLParser):
 			if attrs.has_key('src'):
 				attrs['href'] = attrs['src']
 				alt = attrs.get('alt', '')
+				alt = re.sub('\n', ' ', alt)
 				i = self.previousIndex(attrs)
 				if i is not None:
 					attrs = self.a[i]
@@ -279,7 +280,7 @@ class _html2text(sgmllib.SGMLParser):
 		if tag in ["ol", "ul"]:
 			if start:
 				self.list.append({'name':tag, 'num':0})
-			else:
+			elif self.list:
 				if self.list: self.list.pop()
 			
 			self.p()
