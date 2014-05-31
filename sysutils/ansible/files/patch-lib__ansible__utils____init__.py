--- ./lib/ansible/utils/__init__.py.orig	2014-05-23 16:37:57.000000000 -0400
+++ ./lib/ansible/utils/__init__.py	2014-05-31 09:13:44.140967223 -0400
@@ -952,9 +952,9 @@
     """
     # TODO: work on this function
     randbits = ''.join(chr(random.randint(ord('a'), ord('z'))) for x in xrange(32))
-    prompt = 'assword: '
+    prompt = '[Pp]assword: ?$'
     success_key = 'SUDO-SUCCESS-%s' % randbits
-    sudocmd = '%s %s %s %s -c %s' % (
+    sudocmd = '%s %s %s -c "%s -c %s"' % (
         C.DEFAULT_SU_EXE, C.DEFAULT_SU_FLAGS, su_user, executable or '$SHELL',
         pipes.quote('echo %s; %s' % (success_key, cmd))
     )
