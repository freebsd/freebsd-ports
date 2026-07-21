--- base/server/python/pki/server/subsystem.py.orig	2026-07-12 13:46:52 UTC
+++ base/server/python/pki/server/subsystem.py
@@ -910,9 +910,14 @@ class PKISubsystem(object):
 
         try:
             # export audit-events.properties from pki-server.jar
-            server_jar = \
-                '/usr/share/pki/%s/webapps/%s/WEB-INF/lib/pki-server.jar' \
-                % (self.name, self.name)
+            server_jar = os.path.join(
+                pki.server.PKIServer.SHARE_DIR,
+                self.name,
+                'webapps',
+                self.name,
+                'WEB-INF',
+                'lib',
+                'pki-server.jar')
 
             cmd = [
                 'jar',
@@ -2218,23 +2223,31 @@ class PKISubsystem(object):
 
         classpath = [
             pki.server.Tomcat.SHARE_DIR + '/bin/tomcat-juli.jar',
-            '/usr/share/java/tomcat-servlet-api.jar',
+            pki.server.Tomcat.SHARE_DIR + '/lib/servlet-api.jar',
             pki.server.PKIServer.SHARE_DIR + '/' +
             self.name + '/webapps/' + self.name + '/WEB-INF/lib/*',
             self.instance.common_lib_dir + '/*',
             pki.server.PKIServer.SHARE_DIR + '/lib/*'
         ]
 
-        cmd = []
+        subprocess_kwargs = {}
 
-        # by default run command as systemd user
+        # by default run command as service user
         if not as_current_user:
 
-            # switch to systemd user if different from current user
+            # switch to service user if different from current user
             username = pwd.getpwuid(os.getuid()).pw_name
             if username != self.instance.user:
-                cmd.extend(['/usr/sbin/runuser', '-u', self.instance.user, '--'])
+                subprocess_kwargs.update({
+                    'user': self.instance.user,
+                    'group': self.instance.group,
+                    'extra_groups': os.getgrouplist(
+                        self.instance.user,
+                        self.instance.gid)
+                })
 
+        cmd = []
+
         cmd.extend([java_home + '/bin/java'])
 
         cmd.extend([
@@ -2270,7 +2283,8 @@ class PKISubsystem(object):
                 input=input,
                 stdout=stdout,
                 stderr=stderr,
-                check=True)
+                check=True,
+                **subprocess_kwargs)
 
         except KeyboardInterrupt:
             logger.debug('Server stopped')
