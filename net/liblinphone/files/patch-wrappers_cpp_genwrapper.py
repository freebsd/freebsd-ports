--- wrappers/cpp/genwrapper.py.orig	2025-03-20 22:21:32 UTC
+++ wrappers/cpp/genwrapper.py
@@ -425,6 +425,8 @@ class ClassHeader:
 		elif isinstance(type_, AbsApi.BaseType):
 			if type_.name == 'integer' and isinstance(type_.size, int):
 				self._add_include('external', 'cstdint')
+			elif type_.name == 'time':
+				self._add_include('external', 'ctime')
 			elif type_.name == 'string':
 				self._add_include('external', 'string')
 		elif isinstance(type_, AbsApi.ListType):
