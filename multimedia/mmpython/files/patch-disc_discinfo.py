
$FreeBSD$

--- disc/discinfo.py.orig	Thu Jun 10 20:51:51 2004
+++ disc/discinfo.py	Thu Jun 10 20:52:32 2004
@@ -223,22 +223,10 @@
     else:
         f = open(device,'rb')
 
-        f.seek(0x0000832d)
-        if os.uname()[0] == 'FreeBSD':
-            # why doesn't seeking to 0x0000832d+40 and reading 32 work?
-            # no idea, do it this way
-            label = f.read(72);
-            label = label[40:72]
-        else:    
-            id = f.read(16)
-        f.seek(32808, 0)
-        if os.uname()[0] == 'FreeBSD':
-            # why doesn't seeking to 32808 + 829 and reading 16 work?
-            # no idea, do it this way
-            id = f.read(829);
-            id = id[813:829]
-        else:
-            label = f.read(32)
+        f.seek(32768)
+        id = f.read(829)
+        label = id[40:72]
+        id = id[813:829]
 
         if CREATE_MD5_ID:
             id_md5 = md5.new()
