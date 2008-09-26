--- setup.py.orig	2008-09-21 22:20:16.000000000 +0800
+++ setup.py	2008-09-21 22:20:34.000000000 +0800
@@ -33,7 +33,8 @@
     print string.join(l, '\n')
     # Prompt the user with a list of selections.
     while not (s >= 1 and s <= len(valid_paths)):
-        s = input('Selection [default=1]:' % s)
+#        s = input('Selection [default=1]:' % s)
+	s=1
         if s == '':
             s = 1
         else:
