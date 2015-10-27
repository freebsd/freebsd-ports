--- twoping/crc32.py.orig	2015-10-25 05:57:43 UTC
+++ twoping/crc32.py
@@ -69,7 +69,7 @@ if __name__ == '__main__':
         c = new()
         for line in sys.stdin.readlines():
             c.update(line)
-        print c.hexdigest()
+        print(c.hexdigest())
     else:
         for file in files:
             with open(file) as f:
@@ -77,6 +77,6 @@ if __name__ == '__main__':
                 for line in f.readlines():
                     c.update(line)
                 if len(files) > 1:
-                    print '%s\t%s' % (c.hexdigest(), file)
+                    print('%s\t%s' % (c.hexdigest(), file))
                 else:
-                    print c.hexdigest()
+                    print(c.hexdigest())
