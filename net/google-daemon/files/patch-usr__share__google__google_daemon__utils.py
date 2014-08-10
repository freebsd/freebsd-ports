--- ./usr/share/google/google_daemon/utils.py.orig	2014-08-10 19:54:08.845935081 +0000
+++ ./usr/share/google/google_daemon/utils.py	2014-08-10 19:54:08.851934272 +0000
@@ -69,30 +69,14 @@
   def UserAdd(self, user, groups):
     logging.info('Creating account %s', user)
 
-    # We must set the crypto passwd via useradd to '*' to make ssh work
-    # on Linux systems without PAM.
-    #
-    # Unfortunately, there is no spec that I can find that defines how
-    # this stuff is used and from the manpage of shadow it says that "!"
-    # or "*" or any other invalid crypt can be used.
-    #
-    # ssh just takes it upon itself to use "!" as its locked account token:
-    # https://github.com/openssh/openssh-portable/blob/master/configure.ac#L705
-    #
-    # If '!' token is used then it simply denies logins:
-    # https://github.com/openssh/openssh-portable/blob/master/auth.c#L151
-    #
-    # To solve the issue make the passwd '*' which is also recognized as
-    # locked but doesn't prevent ssh logins.
     result = self.RunCommand([
-        '/usr/sbin/useradd', user, '-m', '-s', '/bin/bash', '-p', '*', '-G',
-        ','.join(groups)])
+        'pw', 'useradd', user, '-G', ','.join(groups)])
     if self.RunCommandFailed(result, 'Could not create user %s', user):
       return False
     return True
 
   def IsValidSudoersFile(self, filename):
-    result = self.RunCommand(['/usr/sbin/visudo', '-c', '-f', filename])
+    result = self.RunCommand(['%%PREFIX%%/sbin/visudo', '-c', '-f', filename])
     if result[0] != 0:
       with self.system.OpenFile(filename, 'r') as f:
         contents = f.read()
