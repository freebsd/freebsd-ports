From 8b2031c747e7c7e6b845ee2e3db47de617d33cc6 Mon Sep 17 00:00:00 2001
From: Takeshi KOMIYA <i.tkomiya@gmail.com>
Date: Fri, 30 Jul 2021 01:27:38 +0900
Subject: [PATCH] Fix #9512: sphinx-build: crashed with the HEAD of Python 3.10

Recently, `types.Union` was renamed to `types.UnionType` on the HEAD
of 3.10 (refs: python/cpython#27342). After this change, sphinx-build
has been crashed because of ImportError.
--- CHANGES.orig	2021-03-06 11:59:38 UTC
+++ CHANGES
@@ -419,6 +419,8 @@ Bugs fixed
 * #6914: figure numbers are unexpectedly assigned to uncaptioned items
 * #8320: make "inline" line numbers un-selectable
 
+* #9512: sphinx-build: crashed with the HEAD of Python 3.10
+
 Testing
 --------
 
 CHANGES               |  2 ++
 sphinx/util/typing.py | 12 ++++++------
 2 files changed, 8 insertions(+), 6 deletions(-)

--- sphinx/util/typing.py.orig	2021-03-06 11:58:24 UTC
+++ sphinx/util/typing.py
@@ -30,10 +30,10 @@ else:
             ref = _ForwardRef(self.arg)
             return ref._eval_type(globalns, localns)
 
-if sys.version_info > (3, 10):
-    from types import Union as types_Union
-else:
-    types_Union = None
+try:
+    from types import UnionType  # type: ignore  # python 3.10 or above
+except ImportError:
+    UnionType = None
 
 if False:
     # For type annotation
@@ -107,7 +107,7 @@ def restify(cls: Optional["Type"]) -> str:
         return ':class:`struct.Struct`'
     elif inspect.isNewType(cls):
         return ':class:`%s`' % cls.__name__
-    elif types_Union and isinstance(cls, types_Union):
+    elif UnionType and isinstance(cls, UnionType):
         if len(cls.__args__) > 1 and None in cls.__args__:
             args = ' | '.join(restify(a) for a in cls.__args__ if a)
             return 'Optional[%s]' % args
@@ -349,7 +349,7 @@ def _stringify_py37(annotation: Any) -> str:
     elif hasattr(annotation, '__origin__'):
         # instantiated generic provided by a user
         qualname = stringify(annotation.__origin__)
-    elif types_Union and isinstance(annotation, types_Union):  # types.Union (for py3.10+)
+    elif UnionType and isinstance(annotation, UnionType):  # types.Union (for py3.10+)
         qualname = 'types.Union'
     else:
         # we weren't able to extract the base type, appending arguments would
