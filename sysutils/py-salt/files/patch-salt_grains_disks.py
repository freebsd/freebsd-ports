--- salt/grains/disks.py.orig	2016-05-25 22:30:31 UTC
+++ salt/grains/disks.py
@@ -57,18 +57,27 @@ class _geomconsts(object):
 
     _datatypes = {
         MEDIASIZE: ('re_int', r'(\d+)'),
-        SECTORSIZE: 'int',
-        STRIPESIZE: 'int',
-        STRIPEOFFSET: 'int',
-        ROTATIONRATE: 'int',
+        SECTORSIZE: 'try_int',
+        STRIPESIZE: 'try_int',
+        STRIPEOFFSET: 'try_int',
+        ROTATIONRATE: 'try_int',
     }
 
 
 def _datavalue(datatype, data):
-    if datatype == 'int':
-        return int(data)
-    elif datatype and datatype[0] == 're_int':
-        return int(re.search(datatype[1], data).group(1))
+    if datatype == 'try_int':
+        try:
+            return int(data)
+        except ValueError:
+            return None
+    elif datatype is tuple and datatype[0] == 're_int':
+        search = re.search(datatype[1], data)
+        if search:
+            try:
+                return int(search.group(1))
+            except ValueError:
+                return None
+        return None
     else:
         return data
 
@@ -97,9 +106,11 @@ def _freebsd_geom():
                         tmp[_geomconsts._aliases[attrib]] = value
 
         name = tmp.pop(_geomconsts.GEOMNAME)
+        if name.startswith('cd'):
+            return
 
         ret['disks'][name] = tmp
-        if tmp[_geomconsts.ROTATIONRATE] == 0:
+        if tmp.get(_geomconsts.ROTATIONRATE) == 0:
             log.trace('Device {0} reports itself as an SSD'.format(device))
             ret['SSDs'].append(name)
 
