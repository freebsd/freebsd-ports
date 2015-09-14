--- setup.py.orig	2008-12-14 09:19:42 UTC
+++ setup.py
@@ -33,7 +33,8 @@ if len(valid_paths) > 1:
     print string.join(l, '\n')
     # Prompt the user with a list of selections.
     while not (s >= 1 and s <= len(valid_paths)):
-        s = input('Selection [default=1]:')
+#        s = input('Selection [default=1]:')
+	s=1
         if s == '':
             s = 1
         else:
