
$FreeBSD$

--- PkgTrackInst/PkgDbWriter.py.orig
+++ PkgTrackInst/PkgDbWriter.py
@@ -74,7 +74,7 @@
         print >> self.pkgfile('+COMMENT'), self.pkginfo['comment']
         print >> self.pkgfile('+DESC'), self.pkginfo['description'].strip()
 
-        mtree = open('/etc/mtree/BSD.local.dist').read()
+        mtree = open('/usr/ports/Templates/BSD.local.dist').read()
         self.pkgfile('+MTREE_DIRS').write(mtree)
 
     def write_scripts(self):
