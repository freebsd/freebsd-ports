Description: Make protobuf_json work on Python 3 and protobuf 7 (relative
  import, no long/unicode, FieldDescriptor.is_repeated).
Issue ID: https://github.com/keepkey/python-keepkey/pull/231
Changeset: none
TODO: Drop once a release includes it.

--- keepkeylib/protobuf_json.py.orig	2021-09-30 20:27:48 UTC
+++ keepkeylib/protobuf_json.py
@@ -44,11 +44,19 @@ import binascii
 import json
 from google.protobuf.descriptor import FieldDescriptor as FD
 import binascii
-import types_pb2 as types
+from . import types_pb2 as types
 
 class ParseError(Exception): pass
 
 
+def _is_repeated(field):
+    # protobuf 7 removed FieldDescriptor.label; is_repeated replaces it
+    try:
+        return field.is_repeated
+    except AttributeError:
+        return field.label == FD.LABEL_REPEATED
+
+
 def json2pb(pb, js):
     ''' convert JSON string to google.protobuf.descriptor instance '''
     for field in pb.DESCRIPTOR.fields:
@@ -61,7 +69,7 @@ def json2pb(pb, js):
         else:
             raise ParseError("Field %s.%s of type '%d' is not supported" % (pb.__class__.__name__, field.name, field.type, ))
         value = js[field.name]
-        if field.label == FD.LABEL_REPEATED:
+        if _is_repeated(field):
             pb_value = getattr(pb, field.name, None)
             for v in value:
                 if field.type == FD.TYPE_MESSAGE:
@@ -91,7 +99,7 @@ def pb2json(pb):
             ftype = _ftype2js[field.type]
         else:
             raise ParseError("Field %s.%s of type '%d' is not supported" % (pb.__class__.__name__, field.name, field.type, ))
-        if field.label == FD.LABEL_REPEATED:
+        if _is_repeated(field):
             js_value = []
             for v in value:
                 js_value.append(ftype(v))
@@ -104,33 +112,33 @@ _ftype2js = {
 _ftype2js = {
     FD.TYPE_DOUBLE: float,
     FD.TYPE_FLOAT: float,
-    FD.TYPE_INT64: long,
-    FD.TYPE_UINT64: long,
+    FD.TYPE_INT64: int,
+    FD.TYPE_UINT64: int,
     FD.TYPE_INT32: int,
     FD.TYPE_FIXED64: float,
     FD.TYPE_FIXED32: float,
     FD.TYPE_BOOL: bool,
-    FD.TYPE_STRING: unicode,
+    FD.TYPE_STRING: str,
     #FD.TYPE_MESSAGE handled specially
-    FD.TYPE_BYTES: lambda x: binascii.hexlify(x),
+    FD.TYPE_BYTES: lambda x: binascii.hexlify(x).decode('ascii'),
     FD.TYPE_UINT32: int,
     # FD.TYPE_ENUM: handled specially
     FD.TYPE_SFIXED32: float,
     FD.TYPE_SFIXED64: float,
     FD.TYPE_SINT32: int,
-    FD.TYPE_SINT64: long,
+    FD.TYPE_SINT64: int,
 }
 
 _js2ftype = {
     FD.TYPE_DOUBLE: float,
     FD.TYPE_FLOAT: float,
-    FD.TYPE_INT64: long,
-    FD.TYPE_UINT64: long,
+    FD.TYPE_INT64: int,
+    FD.TYPE_UINT64: int,
     FD.TYPE_INT32: int,
     FD.TYPE_FIXED64: float,
     FD.TYPE_FIXED32: float,
     FD.TYPE_BOOL: bool,
-    FD.TYPE_STRING: unicode,
+    FD.TYPE_STRING: str,
     # FD.TYPE_MESSAGE handled specially
     FD.TYPE_BYTES: lambda x: binascii.unhexlify(x),
     FD.TYPE_UINT32: int,
@@ -138,5 +146,5 @@ _js2ftype = {
     FD.TYPE_SFIXED32: float,
     FD.TYPE_SFIXED64: float,
     FD.TYPE_SINT32: int,
-    FD.TYPE_SINT64: long,
+    FD.TYPE_SINT64: int,
 }
