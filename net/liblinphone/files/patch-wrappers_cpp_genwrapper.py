--- wrappers/cpp/genwrapper.py.orig	2022-05-18 10:10:25 UTC
+++ wrappers/cpp/genwrapper.py
@@ -408,6 +408,8 @@ class ClassHeader:
 		elif isinstance(type_, AbsApi.BaseType):
 			if type_.name == 'integer' and isinstance(type_.size, int):
 				self._add_include('external', 'cstdint')
+			elif type_.name == 'time':
+				self._add_include('external', 'ctime')
 			elif type_.name == 'string':
 				self._add_include('external', 'string')
 		elif isinstance(type_, AbsApi.ListType):
