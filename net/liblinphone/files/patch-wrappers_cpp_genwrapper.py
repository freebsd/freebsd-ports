--- wrappers/cpp/genwrapper.py.orig	2023-03-17 13:29:37 UTC
+++ wrappers/cpp/genwrapper.py
@@ -414,6 +414,8 @@ class ClassHeader:
 		elif isinstance(type_, AbsApi.BaseType):
 			if type_.name == 'integer' and isinstance(type_.size, int):
 				self._add_include('external', 'cstdint')
+			elif type_.name == 'time':
+				self._add_include('external', 'ctime')
 			elif type_.name == 'string':
 				self._add_include('external', 'string')
 		elif isinstance(type_, AbsApi.ListType):
