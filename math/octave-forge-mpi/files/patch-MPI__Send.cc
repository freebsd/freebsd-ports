--- MPI_Send.cc.orig	2022-11-08 05:02:05 UTC
+++ MPI_Send.cc
@@ -24,9 +24,8 @@
 #include <oct-map.h>
 #include <octave/load-save.h>
 #include <octave/ls-oct-binary.h>
-using namespace octave;
 
-static const load_save_format frmt = load_save_system::BINARY;
+static const octave::load_save_format frmt = octave::load_save_system::BINARY;
 static const octave::mach_info::float_format flt_fmt = octave::mach_info::flt_fmt_unknown;
 static const bool swap = false;
 static const std::ios::openmode omode = std::ios::out | std::ios::binary;
