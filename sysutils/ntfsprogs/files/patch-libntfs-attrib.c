--- libntfs/attrib.c.orig	Fri Feb 24 10:17:49 2006
+++ libntfs/attrib.c	Thu May  4 04:44:07 2006
@@ -763,7 +763,7 @@
  */
 s64 ntfs_attr_pread(ntfs_attr *na, const s64 pos, s64 count, void *b)
 {
-	s64 br, to_read, ofs, total, total2;
+	s64 br, old_to_read, to_read, ofs, total, total2;
 	ntfs_volume *vol;
 	runlist_element *rl;
 
@@ -799,6 +799,7 @@
 	if (pos + count > na->data_size) {
 		if (pos >= na->data_size)
 			return 0;
+		ntfs_log_trace("trunacting read pos=%lld, na->data_size=%lld, (old) count=%lld\n", pos, na->data_size, count);
 		count = na->data_size - pos;
 	}
 	/* If it is a resident attribute, get the value from the mft record. */
@@ -887,6 +888,10 @@
 		/* It is a real lcn, read it into @dst. */
 		to_read = min(count, (rl->length << vol->cluster_size_bits) -
 				ofs);
+		old_to_read = to_read;
+		to_read = (to_read + 511) / 512 * 512;
+		if(old_to_read != to_read)
+			ntfs_log_trace("adjusted %lld->%lld\n", old_to_read, to_read);
 retry:
 		ntfs_log_trace("Reading 0x%llx bytes from vcn 0x%llx, lcn 0x%llx, "
 				"ofs 0x%llx.\n", to_read, rl->vcn, rl->lcn, ofs);
@@ -894,6 +899,8 @@
 				ofs, to_read, b);
 		/* If everything ok, update progress counters and continue. */
 		if (br > 0) {
+			if(br > old_to_read)
+				br = old_to_read;
 			total += br;
 			count -= br;
 			b = (u8*)b + br;
