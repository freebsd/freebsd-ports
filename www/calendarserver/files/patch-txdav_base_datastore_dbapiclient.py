--- txdav/base/datastore/dbapiclient.py.orig	2016-03-01 19:40:29 UTC
+++ txdav/base/datastore/dbapiclient.py
@@ -427,7 +427,10 @@ def pg8000Preflight(connection, **kwargs
         return v.encode("utf-8") if isinstance(v, unicode) else str(v)
 
     connection.realConnection.py_types[str] = (705, postgres.core.FC_TEXT, my_text_out)
-    connection.realConnection.py_types[postgres.six.text_type] = (705, postgres.core.FC_TEXT, my_text_out)
+
+    # http://trac.calendarserver.org/ticket/940
+    from six import text_type
+    connection.realConnection.py_types[text_type] = (705, postgres.core.FC_TEXT, my_text_out)
 
     def my_text_recv(data, offset, length):
         return str(data[offset: offset + length])
