--- disc/discinfo.py	Sun Feb  8 17:44:05 2004
+++ disc/discinfo.py	Thu Jun 17 00:04:48 2004
@@ -191,7 +191,9 @@
     
     fd = open(device, 'rb')
     try:
-    	fd.seek(0x0000832d)
+	fd.seek(32768) # 2048 multiple boundary for FreeBSD
+	# FreeBSD doesn't return IOError unless we try and read:
+	fd.read(1)
     except IOError:
     	fd.close()
 	return 3
@@ -223,22 +225,12 @@
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
+        # FreeBSD can only seek to 2048 multiple boundaries.
+        # Below works on Linux and FreeBSD:
+        f.seek(32768)
+        id = f.read(829)
+        label = id[40:72]
+        id = id[813:829]
 
         if CREATE_MD5_ID:
             id_md5 = md5.new()
