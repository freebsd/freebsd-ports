--- modules/hdf5/src/java/org/scilab/modules/hdf5/read/H5Read.java.orig	2010-03-01 00:10:54.000000000 -0800
+++ modules/hdf5/src/java/org/scilab/modules/hdf5/read/H5Read.java	2010-03-01 00:11:38.000000000 -0800
@@ -53,7 +53,8 @@
 	int nb_objs = H5.H5Gn_members(fileId, groupName);
 	String[] allObjectsName = new String[nb_objs];
 	int[] allObjectsType = new int[nb_objs];
-	H5.H5Gget_obj_info_all(fileId, groupName, allObjectsName, allObjectsType); 
+	long[] refs = new long[nb_objs];
+	H5.H5Gget_obj_info_all(fileId, groupName, allObjectsName, allObjectsType, refs); 
 
 	for (int i = 0 ; i < nb_objs ; ++i) {
 	    if (allObjectsType[i] == HDF5Constants.H5G_DATASET) {
