--- waf-tools/cflags.py.orig	2015-09-23 19:28:42 UTC
+++ waf-tools/cflags.py
@@ -19,7 +19,7 @@ class GccTraits(CompilerTraits):
 	def __init__(self):
 		super(GccTraits, self).__init__()
 		# cumulative list of warnings per level
-		self.warnings_flags = [['-Wall'], ['-Werror'], ['-Wextra']]
+		self.warnings_flags = [['-Wall'], ['-Wextra']]
 
 	def get_warnings_flags(self, level):
 		warnings = []
