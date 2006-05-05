--- ntfsprogs/ntfsresize.c.orig	Tue Feb 14 12:17:52 2006
+++ ntfsprogs/ntfsresize.c	Thu May  4 04:46:10 2006
@@ -1974,6 +1974,11 @@
 		err_exit("Resident attribute in $Bitmap isn't supported!\n");
 
 	bm_bsize = nr_clusters_to_bitmap_byte_size(resize->new_volume_size);
+	if(bm_bsize % 512 != 0) {
+		s64 old_bm_bsize = bm_bsize;
+		bm_bsize = (bm_bsize + 511) / 512 * 512;
+		ntfs_log_verbose("adjusted bm_bsize: %lld->%lld\n", old_bm_bsize, bm_bsize);
+	}
 	nr_bm_clusters = rounded_up_division(bm_bsize, vol->cluster_size);
 
 	if (resize->shrink) {
