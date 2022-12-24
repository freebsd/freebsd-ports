- workaround for https://github.com/boutproject/BOUT-dev/issues/2621

--- include/datafile.hxx.orig	2022-12-24 02:25:29 UTC
+++ include/datafile.hxx
@@ -18,7 +18,7 @@ class Datafile;
 #include "bout/macro_for_each.hxx"
 
 #include "dataformat.hxx"
-#include "../src/fileio/impls/hdf5/h5_format.hxx"
+//#include "../src/fileio/impls/hdf5/h5_format.hxx"
 #include "bout/format.hxx"
 
 #include <cstdarg>
