--- wrappers/cpp/genwrapper.py.orig	2017-06-20 10:03:59 UTC
+++ wrappers/cpp/genwrapper.py
@@ -650,6 +650,8 @@ class ClassHeader(object):
 				self._add_include(includes, 'external', 'cstdint')
 			elif _type.name == 'string':
 				self._add_include(includes, 'external', 'string')
+			elif _type.name == 'time':
+				self._add_include(includes, 'external', 'time.h')
 		elif isinstance(_type, AbsApi.ListType):
 			self._add_include(includes, 'external', 'list')
 			self._needed_includes_from_type(_type.containedTypeDesc, includes)
