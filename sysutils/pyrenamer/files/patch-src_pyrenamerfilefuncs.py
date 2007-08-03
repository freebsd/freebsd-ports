--- src/pyrenamerfilefuncs.py	2007/07/30 11:27:53	45
+++ src/pyrenamerfilefuncs.py	2007/08/02 12:15:22	53
@@ -242,7 +242,7 @@
     repattern = re.compile(pattern)
     try:
         groups = repattern.search(name).groups()
-    
+
         for i in range(len(groups)):
             newname = newname.replace('{'+`i+1`+'}',groups[i])
     except:
@@ -250,19 +250,24 @@
     
     # Replace {num} with item number.
     # If {num2} the number will be 02
-    # If {num3-10} the number will be 010
+    # If {num3+10} the number will be 010
     count = `count`
     cr = re.compile("{(num)([0-9]*)}"
-                    "|{(num)([0-9]*)-([0-9]*)}")
+                    "|{(num)([0-9]*)(\+)([0-9]*)}")
     try:
         cg = cr.search(newname).groups()
-        if len(cg) == 5:
+        if len(cg) == 6:
+            
             if cg[0] == 'num':
+                # {num2}
                 if cg[1] != '': count = count.zfill(int(cg[1]))
                 newname = cr.sub(count, newname)
-            if cg[2] == 'num':
-                if cg[4] != '': count = str(int(count)+int(cg[4])-1)
+            
+            elif cg[2] == 'num' and cg[4] == '+':
+                # {num2+5}
+                if cg[5] != '': count = str(int(count)+int(cg[5]))
                 if cg[3] != '': count = count.zfill(int(cg[3]))
+                
         newname = cr.sub(count, newname)
     except:
         pass
