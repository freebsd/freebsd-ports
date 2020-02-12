--- python/datamodel.py.orig	2014-07-03 07:47:07 UTC
+++ python/datamodel.py
@@ -26,7 +26,7 @@ import os.path
 import gettext
 import time
 import sys
-gettext.install("zeitgeist", unicode=1)
+gettext.install("zeitgeist")
 
 __all__ = [
 	'Interpretation',
@@ -121,12 +121,12 @@ class Symbol(str):
 	def _ensure_all_children (self):
 		if self._all_children is not None : return
 		self._all_children = dict()
-		for child in self._children.itervalues():
+		for child in self._children.values():
 			child._visit(self._all_children)
 	
 	def _visit (self, dikt):
 		dikt[self.name] = self
-		for child in self._children.itervalues():
+		for child in self._children.values():
 			child._visit(dikt) 
 	
 	@staticmethod
@@ -141,7 +141,7 @@ class Symbol(str):
 			children = list(symbol.get_all_children())
 			children.append(uri)
 			return children
-		except KeyError, e:
+		except KeyError as e:
 			return [uri]
 		
 
@@ -174,7 +174,7 @@ class Symbol(str):
 		"""
 		Returns a list of immediate child symbols
 		"""
-		return frozenset(self._children.itervalues())
+		return frozenset(self._children.values())
 		
 	def iter_all_children(self):
 		"""
@@ -182,7 +182,7 @@ class Symbol(str):
 		of this symbol
 		"""
 		self._ensure_all_children()
-		return self._all_children.itervalues()
+		return self._all_children.values()
 		
 	def get_all_children(self):
 		"""
@@ -194,7 +194,7 @@ class Symbol(str):
 		"""
 		Returns a list of immediate parent symbols
 		"""
-		return frozenset(self._parents.itervalues())
+		return frozenset(self._parents.values())
 	
 	def is_child_of (self, parent):
 		"""
@@ -203,7 +203,7 @@ class Symbol(str):
 		if not isinstance (parent, Symbol):
 			try:
 				parent = _SYMBOLS_BY_URI[parent]
-			except KeyError, e:
+			except KeyError as e:
 				# Parent is not a known URI
 				return self.uri == parent
 		
@@ -226,7 +226,7 @@ class Symbol(str):
 		if isinstance (child, basestring):
 			try:
 				child = _SYMBOLS_BY_URI[child]
-			except KeyError, e:
+			except KeyError as e:
 				# Child is not a know URI
 				if isinstance (parent, basestring):
 					return child == parent
@@ -1170,7 +1170,7 @@ _SYMBOLS_BY_URI["Manifestation"] = Manifestation
 # Load the ontology definitions
 ontology_file = os.path.join(os.path.dirname(__file__), "_ontology.py")
 try:
-	execfile(ontology_file)
+	exec(open(ontology_file).read())
 except IOError:
 	raise ImportError("Unable to load Zeitgeist ontology. Did you run `make`?")
 
@@ -1178,23 +1178,23 @@ except IOError:
 # Bootstrap the symbol relations. We use a 2-pass strategy:
 #
 # 1) Make sure that all parents and children are registered on each symbol
-for symbol in _SYMBOLS_BY_URI.itervalues():
+for symbol in _SYMBOLS_BY_URI.values():
 	for parent in symbol._parents:
 		try:
 			_SYMBOLS_BY_URI[parent]._children[symbol.uri] = None
-		except KeyError, e:
-			print "ERROR", e, parent, symbol.uri
+		except KeyError as e:
+			print ("ERROR", e, parent, symbol.uri)
 			pass
 	for child in symbol._children:
 		try:
 			_SYMBOLS_BY_URI[child]._parents.add(symbol.uri)
 		except KeyError:
-			print "ERROR", e, child, symbol.uri
+			print ("ERROR", e, child, symbol.uri)
 			pass
 
 # 2) Resolve all child and parent URIs to their actual Symbol instances
-for symbol in _SYMBOLS_BY_URI.itervalues():
-	for child_uri in symbol._children.iterkeys():
+for symbol in _SYMBOLS_BY_URI.values():
+	for child_uri in symbol._children.keys():
 		symbol._children[child_uri] = _SYMBOLS_BY_URI[child_uri]
 	
 	parents = {}
@@ -1204,8 +1204,8 @@ for symbol in _SYMBOLS_BY_URI.itervalues():
 
 
 if __name__ == "__main__":
-	print "Success"
+	print ("Success")
 	end_symbols = time.time()
-	print >> sys.stderr, "Import time: %s" % (end_symbols - start_symbols)
+	print ("Import time: %s" % (end_symbols - start_symbols), sys.stderr)
 
 # vim:noexpandtab:ts=4:sw=4
