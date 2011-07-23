--- src/ov-galois.cc-orig	2011-07-22 23:43:09.000000000 +0000
+++ src/ov-galois.cc	2011-07-22 23:52:23.000000000 +0000
@@ -205,10 +205,6 @@
 void
 octave_galois::print_raw (std::ostream& os, bool) const
 {
-  unwind_protect::begin_frame ("octave_galois_print");
-
-  unwind_protect_int (Vstruct_levels_to_print);
-
   bool first = true;
   int m = gval.m();
   int primpoly = gval.primpoly();
@@ -256,8 +252,6 @@
 
   octave_print_internal (os, data, false, current_print_indent_level ());
   newline (os);
-
-  unwind_protect::run_frame ("octave_galois_print");
 }
 
 bool
@@ -554,7 +548,7 @@
 {
   Matrix mval = matrix_value ();
   hid_t group_hid = -1;
-  group_hid = H5Gcreate (loc_id, name, 0);
+  group_hid = H5Gcreate (loc_id, name, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
   if (group_hid < 0 ) return false;
 
   dim_vector d = dims ();
@@ -572,7 +566,7 @@
     }
 
   data_hid = H5Dcreate (group_hid, "m", H5T_NATIVE_UCHAR, space_hid, 
-			H5P_DEFAULT);
+			H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
   if (data_hid < 0) 
     {
       H5Sclose (space_hid);
@@ -592,7 +586,7 @@
     }    
 
   data_hid = H5Dcreate (group_hid, "prim", H5T_NATIVE_UINT, space_hid, 
-			H5P_DEFAULT);
+			H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
   if (data_hid < 0) 
     {
       H5Sclose (space_hid);
@@ -644,7 +638,7 @@
     }
 
   data_hid = H5Dcreate (group_hid, "val", save_type_hid, space_hid, 
-			H5P_DEFAULT);
+			H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
   if (data_hid < 0)
     {
       H5Sclose (space_hid);
@@ -671,10 +665,10 @@
   hid_t group_hid, data_hid, space_id;
   hsize_t rank;
 
-  group_hid = H5Gopen (loc_id, name);
+  group_hid = H5Gopen (loc_id, name, H5P_DEFAULT);
   if (group_hid < 0 ) return false;
 
-  data_hid = H5Dopen (group_hid, "m");
+  data_hid = H5Dopen (group_hid, "m", H5P_DEFAULT);
   space_id = H5Dget_space (data_hid);
   rank = H5Sget_simple_extent_ndims (space_id);
 
@@ -694,7 +688,7 @@
     }
 
   H5Dclose (data_hid);
-  data_hid = H5Dopen (group_hid, "prim");
+  data_hid = H5Dopen (group_hid, "prim", H5P_DEFAULT);
   space_id = H5Dget_space (data_hid);
   rank = H5Sget_simple_extent_ndims (space_id);
 
@@ -714,7 +708,7 @@
     }
 
   H5Dclose (data_hid);
-  data_hid = H5Dopen (group_hid, "val");
+  data_hid = H5Dopen (group_hid, "val", H5P_DEFAULT);
   space_id = H5Dget_space (data_hid);
   rank = H5Sget_simple_extent_ndims (space_id);
 
