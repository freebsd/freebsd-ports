--- MPI_Recv.cc.orig	2022-11-08 05:03:32 UTC
+++ MPI_Recv.cc
@@ -20,13 +20,13 @@
 
 #include <string>
 #include <sstream>
+#include <iostream>
 
 #include <oct-map.h>
 #include <octave/load-save.h>
 #include <octave/ls-oct-binary.h>
 
-using namespace octave;
-static const load_save_format frmt = load_save_system::BINARY;
+static const octave::load_save_format frmt = octave::load_save_system::BINARY;
 static octave::mach_info::float_format flt_fmt = octave::mach_info::native_float_format ();
 static bool swap = false;
 static const std::ios::openmode imode = std::ios::in | std::ios::binary;
