--- src/input/r_qtmp4.cpp.orig	2016-09-11 12:16:51 UTC
+++ src/input/r_qtmp4.cpp
@@ -107,7 +107,7 @@ read_qtmp4_atom(mm_io_c *read_from,
     if (exit_on_error)
       mxerror(boost::format(Y("Quicktime/MP4 reader: Invalid chunk size %1% at %2%.\n")) % a.size % a.pos);
     else
-      throw mtx::atom_chunk_size_x{a.size, a.pos};
+      throw mtx::atom_chunk_size_x{static_cast<size_t>(a.size), static_cast<size_t>(a.pos)};
   }
 
   return a;
