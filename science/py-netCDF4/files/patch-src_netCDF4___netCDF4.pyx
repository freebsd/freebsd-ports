Description: Compare the netcdf-c library version as numbers instead of strings.
  As strings, '4.10.1' < '4.2.1', so with netcdf-c 4.10 Dataset(diskless=True)
  raises ValueError, NC_PERSIST falls back to NC_DISKLESS (persisted diskless
  datasets are not written), and the other version-gated paths take the
  pre-4.6.2 / pre-4.5.1 / pre-4.4 branches.  Backport of the 1.7.5.1 change
  (it uses packaging.version; a tuple needs no new dependency).
Issue ID: https://github.com/Unidata/netcdf4-python/issues/1515
Changeset: none (fixed in 1.7.5.1)
TODO: Drop when updating to 1.7.5.1 or later.

--- src/netCDF4/_netCDF4.pyx.orig	2024-10-22 17:41:10 UTC
+++ src/netCDF4/_netCDF4.pyx
@@ -1480,13 +1480,15 @@ def set_alignment(threshold, alignment):
 
 
 __netcdf4libversion__ = getlibversion().split()[0]
+# parsed for comparisons: comparing the strings breaks with netcdf-c 4.10+
+_nclibversion = tuple(int(v) for v in __netcdf4libversion__.split('-')[0].split('.')[:3])
 __hdf5libversion__ = _gethdf5libversion()
-_needsworkaround_issue485 = __netcdf4libversion__ < "4.4.0" or \
+_needsworkaround_issue485 = _nclibversion < (4, 4, 0) or \
                (__netcdf4libversion__.startswith("4.4.0") and \
                 "-development" in __netcdf4libversion__)
 
 # issue warning for hdf5 1.10 (issue #549)
-if __netcdf4libversion__[0:5] < "4.4.1" and\
+if _nclibversion < (4, 4, 1) and\
    __hdf5libversion__.startswith("1.10"):
     msg = """
 WARNING: Backwards incompatible files will be created with HDF5 1.10.x
@@ -1604,7 +1606,7 @@ is_native_big = numpy.dtype('>f4').byteo
 # so it will compile with versions <= 4.2.
 NC_DISKLESS = 0x0008
 # introduced in 4.6.2
-if __netcdf4libversion__[0:5] >= "4.6.2":
+if _nclibversion >= (4, 6, 2):
     NC_PERSIST = 0x4000
 else:  # prior to 4.6.2 this flag doesn't work, so make the same as NC_DISKLESS
     NC_PERSIST = NC_DISKLESS
@@ -2410,7 +2412,7 @@ strings.
 
         # flag to indicate that Variables in this Dataset support orthogonal indexing.
         self.__orthogonal_indexing__ = True
-        if diskless and __netcdf4libversion__ < '4.2.1':
+        if diskless and _nclibversion < (4, 2, 1):
             #diskless = False # don't raise error, instead silently ignore
             raise ValueError('diskless mode requires netcdf lib >= 4.2.1, you have %s' % __netcdf4libversion__)
         # convert filename into string (from os.path object for example),
@@ -4469,7 +4471,7 @@ does not do anything."""
         # a fix for strided slice access using HDF5 was added
         # in 4.6.2.
         # always use nc_get_vars for strided access with OpenDAP (issue #838).
-        if __netcdf4libversion__ >= "4.6.2" or\
+        if _nclibversion >= (4, 6, 2) or\
            self._grp.filepath().startswith('http'):
             self._use_get_vars = True
         else:
@@ -4544,7 +4546,7 @@ does not do anything."""
         if (self._grp.path != '/'): ncdump.append('path = %s' % self._grp.path)
         ncdump.append('unlimited dimensions: %s' % ', '.join(unlimdims))
         ncdump.append('current shape = %r' % (self.shape,))
-        if __netcdf4libversion__ < '4.5.1' and\
+        if _nclibversion < (4, 5, 1) and\
             self._grp.file_format.startswith('NETCDF3'):
             # issue #908: no_fill not correct for NETCDF3 files before 4.5.1
             # before 4.5.1 there was no way to turn off filling on a
@@ -5238,7 +5240,7 @@ rename a `Variable` attribute named `old
         # issue 209: don't return masked array if variable filling
         # is disabled.
         else:
-            if __netcdf4libversion__ < '4.5.1' and\
+            if _nclibversion < (4, 5, 1) and\
                 self._grp.file_format.startswith('NETCDF3'):
                 # issue #908: no_fill not correct for NETCDF3 files before 4.5.1
                 # before 4.5.1 there was no way to turn off filling on a
