--- MoinMoin/user.py.orig	Sun Jun  6 08:58:39 2004
+++ MoinMoin/user.py	Sat Jun 26 20:57:34 2004
@@ -46,7 +46,7 @@
         userdictpickle = os.path.join(config.user_dir, "userdict.pickle")
         try:
             _name2id = pickle.load(open(userdictpickle))
-        except (UnpicklingError,IOError,EOFError,ValueError):
+        except (pickle.UnpicklingError,IOError,EOFError,ValueError):
             _name2id = {}
     id = _name2id.get(searchName, None)
     if id is None:
