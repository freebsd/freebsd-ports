--- yum/rpmsack.py.orig	2010-07-26 23:04:25.000000000 +0200
+++ yum/rpmsack.py	2010-08-22 15:38:07.000000000 +0200
@@ -894,7 +894,7 @@
         # http://lists.rpm.org/pipermail/rpm-maint/2007-November/001719.html
         # ...if anything gets implemented, we should change.
         rpmdbvfname = self._cachedir + "/version"
-        rpmdbfname  = self.root + "/var/lib/rpm/Packages"
+        rpmdbfname  = self.root + "@RPMDIR@/Packages"
 
         if os.path.exists(rpmdbvfname) and os.path.exists(rpmdbfname):
             # See if rpmdb has "changed" ...
@@ -1428,6 +1428,7 @@
         self.conf.writable = False
         
         self._packages = {} # pkgid = dir
+        self.yumdb_cache = None
         if not os.path.exists(self.conf.db_path):
             try:
                 os.makedirs(self.conf.db_path)
