--- ./python/PETSc/packages/Spooles.py.orig	Wed Sep 22 02:45:51 2004
+++ ./python/PETSc/packages/Spooles.py	Tue Sep 28 23:09:00 2004
@@ -71,7 +71,8 @@
       if 'with-'+self.package+'-lib' in self.framework.argDB: #~spooles-2.2/MPI/src/spoolesMPI.a ~spooles-2.2/spooles.a
         lib = self.framework.argDB['with-'+self.package+'-lib']
         (lib_mpi,dummy) = os.path.split(lib)
-        lib_mpi = os.path.join(lib_mpi,'MPI/src/spoolesMPI.a')
+	# FreeBSD: MPI is included in our spooles.a
+        #lib_mpi = os.path.join(lib_mpi,'MPI/src/spoolesMPI.a')
         yield ('User specified '+self.PACKAGE+' library',lib_mpi,lib)
       elif 'with-'+self.package+'-include' in self.framework.argDB:
         dir = self.framework.argDB['with-'+self.package+'-include'] #~spooles-2.2
