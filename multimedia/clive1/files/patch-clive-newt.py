--- clive/newt.py	2007-03-09 13:55:23.000000000 +0200
+++ clive/newt.py.new	2007-03-09 13:55:15.000000000 +0200
@@ -68,7 +68,7 @@
       for item in exist:
         ct.append(item)
 
-      btns = [('Cancel',False,'ESC'),('OK',True)]
+      btns = [('Cancel',False),('OK',True)]
       bb = ButtonBar(scr, btns)
 
       g = GridForm(scr, 'Overwrite existing files:', 1,2) # cols,rows
@@ -134,7 +134,7 @@
             break
       ct.append('%s (%s)' % (file,size), video['file'], selected=issel)
 
-    btns = [('Cancel',False,'ESC'),('OK',True)]
+    btns = [('Cancel',False),('OK',True)]
     bb = ButtonBar(scr, btns)
 
     g = GridForm(scr, 'Select videos:', 1,2) # columns,rows
