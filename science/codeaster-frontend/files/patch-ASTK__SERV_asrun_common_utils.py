--- ASTK_SERV/asrun/common/utils.py.orig	2026-10-13 09:57:39 UTC
+++ ASTK_SERV/asrun/common/utils.py
@@ -473,7 +473,7 @@ def check_joker(filename, joker):
 def check_joker(filename, joker):
     """Returns if 'filename' verifies 'joker' : ("toto.comm", "com?") returns True
     """
-    reg = re.compile(joker.replace(".", "\.").replace("?", ".").replace("*", ".*"))
+    reg = re.compile(joker.replace(".", r"\.").replace("?", ".").replace("*", ".*"))
     res = reg.search(osp.basename(filename)) is not None
     return res
 
@@ -487,7 +487,7 @@ def default_install_value(expression, default):
         d = {}
         exec(expression, d)
         if type(d['value']) in (str, str) and \
-           re.search('\?{1}([^\'\"|]+?)\?{1}', d['value']) is None:
+           re.search(r'\?{1}([^\'\"|]+?)\?{1}', d['value']) is None:
             value = d['value']
     except:
         pass
@@ -511,7 +511,7 @@ def find_command(content, command):
     the index of the end of the command.
     """
     pos, endpos = -1, -1
-    re_start = re.compile('^ *%s *\(' % re.escape(command), re.M)
+    re_start = re.compile(r'^ *%s *\(' % re.escape(command), re.M)
     mat_start = re_start.search(content)
     if mat_start is not None:
         pos = mat_start.start()
@@ -592,7 +592,7 @@ def unique_basename(pathname):
     bname = sha1(pathname.encode()).hexdigest() + '.' + osp.basename(pathname)
     return bname
 
-__reg_prefix__ = re.compile('^[a-f0-9]{%d}\.' % (sha1('a'.encode()).digest_size * 2), re.I)
+__reg_prefix__ = re.compile(r'^[a-f0-9]{%d}\.' % (sha1('a'.encode()).digest_size * 2), re.I)
 
 def unique_basename_remove(bname):
     """Remove the prefix added by unique_basename."""
