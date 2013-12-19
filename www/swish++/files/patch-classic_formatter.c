--- classic_formatter.c.orig
+++ classic_formatter.c
@@ -79,7 +79,7 @@
 //
 // SYNOPSIS
 //
-        void classic_formatter::result( int rank, file_info const &fi ) const
+        void classic_formatter::result( int my_rank, file_info const &fi ) const
 //
 // DESCRIPTION
 //
@@ -88,13 +88,13 @@
 //
 // PARAMETERS
 //
-//      rank    The rank (1-100) of the result.
+//      my_rank The rank (1-100) of the result.
 //
 //      fi      The search result's file information.
 //
 //*****************************************************************************
 {
-    out_ << rank << result_separator
+    out_ << my_rank << result_separator
          << directories[ fi.dir_index() ] << '/' << fi.file_name()
          << result_separator << fi.size()
          << result_separator << fi.title() << '\n';
