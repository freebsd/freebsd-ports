--- lib/exabgp/bgp/message/update/attribute/aspath.py.orig	2015-07-22 10:19:42 UTC
+++ lib/exabgp/bgp/message/update/attribute/aspath.py
@@ -140,7 +140,7 @@ class ASPath (Attribute):
 		return self._json[name]
 
 	@classmethod
-	def __new_aspaths (cls, data, asn4, klass=None):
+	def _new_aspaths (cls, data, asn4, klass=None):
 		as_set = []
 		as_seq = []
 		as_cset = []
@@ -199,7 +199,7 @@ class ASPath (Attribute):
 	def unpack (cls, data, negotiated):
 		if not data:
 			return None  # ASPath.Empty
-		return cls.__new_aspaths(data,negotiated.asn4,ASPath)
+		return cls._new_aspaths(data,negotiated.asn4,ASPath)
 
 
 ASPath.Empty = ASPath([],[])
@@ -220,6 +220,6 @@ class AS4Path (ASPath):
 	def unpack (cls, data, negotiated):
 		if not data:
 			return None  # AS4Path.Empty
-		return cls.__new_aspaths(data,True,AS4Path)
+		return cls._new_aspaths(data,True,AS4Path)
 
 AS4Path.Empty = AS4Path([],[])
