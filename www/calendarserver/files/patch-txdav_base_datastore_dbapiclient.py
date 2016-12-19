--- txdav/base/datastore/dbapiclient.py.orig	2016-12-15 11:56:26 UTC
+++ txdav/base/datastore/dbapiclient.py
@@ -24,6 +24,7 @@ from twext.python.filepath import Cachin
 from txdav.common.icommondatastore import InternalDataStoreError
 
 import pg8000 as postgres
+import six
 
 try:
     import os
@@ -430,7 +431,7 @@ def pg8000Preflight(connection, **kwargs
         return v.encode("utf-8") if isinstance(v, unicode) else str(v)
 
     connection.realConnection.py_types[str] = (705, postgres.core.FC_TEXT, my_text_out)
-    connection.realConnection.py_types[postgres.six.text_type] = (705, postgres.core.FC_TEXT, my_text_out)
+    connection.realConnection.py_types[six.text_type] = (705, postgres.core.FC_TEXT, my_text_out)
 
     def my_text_recv(data, offset, length):
         return str(data[offset: offset + length])
