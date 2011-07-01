--- core/config.py.orig	2011-01-03 20:00:07.000000000 +0100
+++ core/config.py	2011-06-30 01:58:31.000000000 +0200
@@ -18,7 +18,7 @@
 ## Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ###############################################################################
 
-import os
+import os,stat
 import uuid
 import shutil
 import __builtin__
@@ -91,6 +91,8 @@
 					package, icon, name, enabled, config = self.service(path)
 					if name:
 						self.set(SECTION_SERVICES, name, path.encode("utf-8"))
+					for service_file in os.listdir(path):
+						os.chmod(path + service_file, stat.S_IRUSR|stat.S_IWUSR)
 			self.save()
 
 	def check_config(self):
