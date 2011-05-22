--- ./core/service_config.py.orig	2009-10-07 01:02:28.000000000 +0200
+++ ./core/service_config.py	2011-05-22 19:41:52.000000000 +0200
@@ -18,7 +18,7 @@
 ## Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ###############################################################################
 
-import os
+import os, stat
 import pickle
 import base64
 import logging
@@ -157,6 +157,7 @@
 
 	def save(self):
 		""""""
+		os.chmod(self.path + CONF, stat.S_IRUSR|stat.S_IWUSR)
 		f = open(self.path + CONF, "w")
 		self.write(f)
 		f.close()
