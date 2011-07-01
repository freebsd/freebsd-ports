--- core/service_config.py.orig	2011-06-29 20:00:20.785827385 +0200
+++ core/service_config.py	2011-06-29 20:00:44.438339926 +0200
@@ -18,7 +18,7 @@
 ## Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ###############################################################################
 
-import os
+import os, stat
 import pickle
 import base64
 import logging
@@ -184,6 +184,7 @@
 
 	def save(self):
 		""""""
+		os.chmod(self.path + CONF, stat.S_IRUSR|stat.S_IWUSR)
 		f = open(self.path + CONF, "w")
 		self.write(f)
 		f.close()
