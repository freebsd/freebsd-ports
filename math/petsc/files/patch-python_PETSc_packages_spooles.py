--- ./python/PETSc/packages/spooles.py.orig	Thu Aug 11 01:08:42 2005
+++ ./python/PETSc/packages/spooles.py	Sun Aug 21 23:04:09 2005
@@ -11,7 +11,8 @@
     self.download   = ['ftp://ftp.mcs.anl.gov/pub/petsc/externalpackages/spooles-2.2.tar.gz']
     self.functions  = ['InpMtx_init']
     self.includes   = ['MPI/spoolesMPI.h']
-    self.liblist    = [[os.path.join('MPI','src','spoolesMPI.a'),'spooles.a']]
+    # FreeBSD: MPI is included in our spooles.a
+    # self.liblist    = [[os.path.join('MPI','src','spoolesMPI.a'),'spooles.a']]
     self.libdir     = ''
     self.includedir = ''
     return
