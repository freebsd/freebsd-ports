--- src/disk.c.orig	2015-03-10 14:14:45 UTC
+++ src/disk.c
@@ -53,6 +53,10 @@
 #if HAVE_IOKIT_IOBSD_H
 #  include <IOKit/IOBSD.h>
 #endif
+#if KERNEL_FREEBSD
+#include <devstat.h>
+#include <libgeom.h>
+#endif
 
 #if HAVE_LIMITS_H
 # include <limits.h>
@@ -107,6 +111,9 @@ typedef struct diskstats
 
 static diskstats_t *disklist;
 /* #endif KERNEL_LINUX */
+#elif KERNEL_FREEBSD
+static struct gmesh geom_tree;
+/* #endif KERNEL_FREEBSD */
 
 #elif HAVE_LIBKSTAT
 #define MAX_NUMDISK 1024
@@ -222,6 +229,21 @@ static int disk_init (void)
 	/* do nothing */
 /* #endif KERNEL_LINUX */
 
+#elif KERNEL_FREEBSD
+	int rv;
+
+	rv = geom_gettree(&geom_tree);
+	if (rv != 0) {
+		ERROR ("geom_gettree() failed, returned %d", rv);
+		return (-1);
+	}
+	rv = geom_stats_open();
+	if (rv != 0) {
+		ERROR ("geom_stats_open() failed, returned %d", rv);
+		return (-1);
+	}
+/* #endif KERNEL_FREEBSD */
+
 #elif HAVE_LIBKSTAT
 	kstat_t *ksp_chain;
 
@@ -395,173 +417,223 @@ static int disk_read (void)
 	io_registry_entry_t	disk;
 	io_registry_entry_t	disk_child;
 	io_iterator_t		disk_list;
-	CFDictionaryRef		props_dict;
+	CFMutableDictionaryRef	props_dict, child_dict;
 	CFDictionaryRef		stats_dict;
-	CFDictionaryRef		child_dict;
 	CFStringRef		tmp_cf_string_ref;
 	kern_return_t		status;
 
-	signed long long read_ops;
-	signed long long read_byt;
-	signed long long read_tme;
-	signed long long write_ops;
-	signed long long write_byt;
-	signed long long write_tme;
+	signed long long read_ops, read_byt, read_tme;
+	signed long long write_ops, write_byt, write_tme;
 
-	int  disk_major;
-	int  disk_minor;
+	int  disk_major, disk_minor;
 	char disk_name[DATA_MAX_NAME_LEN];
-	char disk_name_bsd[DATA_MAX_NAME_LEN];
+	char child_disk_name_bsd[DATA_MAX_NAME_LEN], props_disk_name_bsd[DATA_MAX_NAME_LEN];
 
 	/* Get the list of all disk objects. */
-	if (IOServiceGetMatchingServices (io_master_port,
-				IOServiceMatching (kIOBlockStorageDriverClass),
-				&disk_list) != kIOReturnSuccess)
-	{
+	if (IOServiceGetMatchingServices (io_master_port, IOServiceMatching (kIOBlockStorageDriverClass), &disk_list) != kIOReturnSuccess) {
 		ERROR ("disk plugin: IOServiceGetMatchingServices failed.");
 		return (-1);
 	}
 
-	while ((disk = IOIteratorNext (disk_list)) != 0)
-	{
+	while ((disk = IOIteratorNext (disk_list)) != 0) {
 		props_dict = NULL;
 		stats_dict = NULL;
 		child_dict = NULL;
 
-		/* `disk_child' must be released */
-		if ((status = IORegistryEntryGetChildEntry (disk, kIOServicePlane, &disk_child))
-			       	!= kIOReturnSuccess)
-		{
-			/* This fails for example for DVD/CD drives.. */
+		/* get child of disk entry and corresponding property dictionary */
+		if ((status = IORegistryEntryGetChildEntry (disk, kIOServicePlane, &disk_child)) != kIOReturnSuccess) {
+			/* This fails for example for DVD/CD drives, which we want to ignore anyway */
 			DEBUG ("IORegistryEntryGetChildEntry (disk) failed: 0x%08x", status);
 			IOObjectRelease (disk);
 			continue;
 		}
-
-		/* We create `props_dict' => we need to release it later */
-		if (IORegistryEntryCreateCFProperties (disk,
-					(CFMutableDictionaryRef *) &props_dict,
-					kCFAllocatorDefault,
-					kNilOptions)
-				!= kIOReturnSuccess)
-		{
-			ERROR ("disk-plugin: IORegistryEntryCreateCFProperties failed.");
+		if (IORegistryEntryCreateCFProperties (disk_child, (CFMutableDictionaryRef *) &child_dict, kCFAllocatorDefault, kNilOptions) != kIOReturnSuccess || child_dict == NULL) {
+			ERROR ("disk plugin: IORegistryEntryCreateCFProperties (disk_child) failed.");
 			IOObjectRelease (disk_child);
 			IOObjectRelease (disk);
 			continue;
 		}
 
-		if (props_dict == NULL)
-		{
-			DEBUG ("IORegistryEntryCreateCFProperties (disk) failed.");
-			IOObjectRelease (disk_child);
-			IOObjectRelease (disk);
-			continue;
+		/* extract name and major/minor numbers */
+		memset (child_disk_name_bsd, 0, sizeof (child_disk_name_bsd));
+		tmp_cf_string_ref = (CFStringRef) CFDictionaryGetValue (child_dict, CFSTR(kIOBSDNameKey));
+		if (tmp_cf_string_ref) {
+			assert (CFGetTypeID (tmp_cf_string_ref) == CFStringGetTypeID ());
+			CFStringGetCString (tmp_cf_string_ref, child_disk_name_bsd, sizeof (child_disk_name_bsd), kCFStringEncodingUTF8);
 		}
+		disk_major = (int) dict_get_value (child_dict, kIOBSDMajorKey);
+		disk_minor = (int) dict_get_value (child_dict, kIOBSDMinorKey);
+		DEBUG ("disk plugin: child_disk_name_bsd=\"%s\" major=%d minor=%d", child_disk_name_bsd, disk_major, disk_minor);
+		CFRelease (child_dict);
+		IOObjectRelease (disk_child);
 
-		/* tmp_cf_string_ref doesn't need to be released. */
-		tmp_cf_string_ref = (CFStringRef) CFDictionaryGetValue (props_dict,
-				CFSTR(kIOBSDNameKey));
-		if (!tmp_cf_string_ref)
-		{
-			DEBUG ("disk plugin: CFDictionaryGetValue("
-					"kIOBSDNameKey) failed.");
-			CFRelease (props_dict);
-			IOObjectRelease (disk_child);
+		/* get property dictionary of the disk entry itself */
+		if (IORegistryEntryCreateCFProperties (disk, (CFMutableDictionaryRef *) &props_dict, kCFAllocatorDefault, kNilOptions) != kIOReturnSuccess || props_dict == NULL) {
+			ERROR ("disk-plugin: IORegistryEntryCreateCFProperties failed.");
 			IOObjectRelease (disk);
 			continue;
 		}
-		assert (CFGetTypeID (tmp_cf_string_ref) == CFStringGetTypeID ());
 
-		memset (disk_name_bsd, 0, sizeof (disk_name_bsd));
-		CFStringGetCString (tmp_cf_string_ref,
-				disk_name_bsd, sizeof (disk_name_bsd),
-				kCFStringEncodingUTF8);
-		if (disk_name_bsd[0] == 0)
-		{
-			ERROR ("disk plugin: CFStringGetCString() failed.");
-			CFRelease (props_dict);
-			IOObjectRelease (disk_child);
-			IOObjectRelease (disk);
-			continue;
+		/* extract name and stats dictionary */
+		memset (props_disk_name_bsd, 0, sizeof (props_disk_name_bsd));
+		tmp_cf_string_ref = (CFStringRef) CFDictionaryGetValue (props_dict, CFSTR(kIOBSDNameKey));
+		if (tmp_cf_string_ref) {
+			assert (CFGetTypeID (tmp_cf_string_ref) == CFStringGetTypeID ());
+			CFStringGetCString (tmp_cf_string_ref, props_disk_name_bsd, sizeof (props_disk_name_bsd), kCFStringEncodingUTF8);
 		}
-		DEBUG ("disk plugin: disk_name_bsd = \"%s\"", disk_name_bsd);
-
-		stats_dict = (CFDictionaryRef) CFDictionaryGetValue (props_dict,
-				CFSTR (kIOBlockStorageDriverStatisticsKey));
-
-		if (stats_dict == NULL)
-		{
-			DEBUG ("disk plugin: CFDictionaryGetValue ("
-					"%s) failed.",
-				       	kIOBlockStorageDriverStatisticsKey);
+		stats_dict = (CFDictionaryRef) CFDictionaryGetValue (props_dict, CFSTR (kIOBlockStorageDriverStatisticsKey));
+		if (stats_dict == NULL) {
+			ERROR ("disk plugin: CFDictionaryGetValue (%s) failed.", kIOBlockStorageDriverStatisticsKey);
 			CFRelease (props_dict);
-			IOObjectRelease (disk_child);
 			IOObjectRelease (disk);
 			continue;
 		}
+		DEBUG ("disk plugin: props_disk_name_bsd=\"%s\"", props_disk_name_bsd);
 
-		if (IORegistryEntryCreateCFProperties (disk_child,
-					(CFMutableDictionaryRef *) &child_dict,
-					kCFAllocatorDefault,
-					kNilOptions)
-				!= kIOReturnSuccess)
-		{
-			DEBUG ("disk plugin: IORegistryEntryCreateCFProperties ("
-					"disk_child) failed.");
-			IOObjectRelease (disk_child);
-			CFRelease (props_dict);
-			IOObjectRelease (disk);
-			continue;
+		/* choose name */
+		if (use_bsd_name) {
+			if (child_disk_name_bsd[0] != 0)
+				sstrncpy (disk_name, child_disk_name_bsd, sizeof (disk_name));
+			else if (props_disk_name_bsd[0] != 0)
+				sstrncpy (disk_name, props_disk_name_bsd, sizeof (disk_name));
+			else {
+				ERROR ("disk plugin: can't find bsd disk name.");
+				ssnprintf (disk_name, sizeof (disk_name), "%i-%i", disk_major, disk_minor);
+			}
 		}
+		else
+			ssnprintf (disk_name, sizeof (disk_name), "%i-%i", disk_major, disk_minor);
 
-		/* kIOBSDNameKey */
-		disk_major = (int) dict_get_value (child_dict,
-			       	kIOBSDMajorKey);
-		disk_minor = (int) dict_get_value (child_dict,
-			       	kIOBSDMinorKey);
-		read_ops  = dict_get_value (stats_dict,
-				kIOBlockStorageDriverStatisticsReadsKey);
-		read_byt  = dict_get_value (stats_dict,
-				kIOBlockStorageDriverStatisticsBytesReadKey);
-		read_tme  = dict_get_value (stats_dict,
-				kIOBlockStorageDriverStatisticsTotalReadTimeKey);
-		write_ops = dict_get_value (stats_dict,
-				kIOBlockStorageDriverStatisticsWritesKey);
-		write_byt = dict_get_value (stats_dict,
-				kIOBlockStorageDriverStatisticsBytesWrittenKey);
-		/* This property describes the number of nanoseconds spent
-		 * performing writes since the block storage driver was
-		 * instantiated. It is one of the statistic entries listed
-		 * under the top-level kIOBlockStorageDriverStatisticsKey
-		 * property table. It has an OSNumber value. */
-		write_tme = dict_get_value (stats_dict,
-				kIOBlockStorageDriverStatisticsTotalWriteTimeKey);
+		/* extract the stats */
+		read_ops  = dict_get_value (stats_dict, kIOBlockStorageDriverStatisticsReadsKey);
+		read_byt  = dict_get_value (stats_dict, kIOBlockStorageDriverStatisticsBytesReadKey);
+		read_tme  = dict_get_value (stats_dict, kIOBlockStorageDriverStatisticsTotalReadTimeKey);
+		write_ops = dict_get_value (stats_dict, kIOBlockStorageDriverStatisticsWritesKey);
+		write_byt = dict_get_value (stats_dict, kIOBlockStorageDriverStatisticsBytesWrittenKey);
+		write_tme = dict_get_value (stats_dict, kIOBlockStorageDriverStatisticsTotalWriteTimeKey);
+		CFRelease (props_dict);
+		IOObjectRelease (disk);
 
-		if (use_bsd_name)
-			sstrncpy (disk_name, disk_name_bsd, sizeof (disk_name));
-		else
-			ssnprintf (disk_name, sizeof (disk_name), "%i-%i",
-					disk_major, disk_minor);
+		/* and submit */
 		DEBUG ("disk plugin: disk_name = \"%s\"", disk_name);
-
 		if ((read_byt != -1LL) || (write_byt != -1LL))
 			disk_submit (disk_name, "disk_octets", read_byt, write_byt);
 		if ((read_ops != -1LL) || (write_ops != -1LL))
 			disk_submit (disk_name, "disk_ops", read_ops, write_ops);
 		if ((read_tme != -1LL) || (write_tme != -1LL))
-			disk_submit (disk_name, "disk_time",
-					read_tme / 1000,
-					write_tme / 1000);
+			disk_submit (disk_name, "disk_time", read_tme / 1000, write_tme / 1000);
 
-		CFRelease (child_dict);
-		IOObjectRelease (disk_child);
-		CFRelease (props_dict);
-		IOObjectRelease (disk);
 	}
 	IOObjectRelease (disk_list);
 /* #endif HAVE_IOKIT_IOKITLIB_H */
 
+#elif KERNEL_FREEBSD
+	int retry, dirty;
+
+	void *snap = NULL;
+	struct devstat *snap_iter;
+
+	struct gident *geom_id;
+
+	const char *disk_name;
+	long double read_time, write_time;
+
+	for (retry = 0, dirty = 1; retry < 5 && dirty == 1; retry++) {
+		if (snap != NULL)
+			geom_stats_snapshot_free(snap);
+
+		/* Get a fresh copy of stats snapshot */
+		snap = geom_stats_snapshot_get();
+		if (snap == NULL) {
+			ERROR("disk plugin: geom_stats_snapshot_get() failed.");
+			return (-1);
+		}
+
+		/* Check if we have dirty read from this snapshot */
+		dirty = 0;
+		geom_stats_snapshot_reset(snap);
+		while ((snap_iter = geom_stats_snapshot_next(snap)) != NULL) {
+			if (snap_iter->id == NULL)
+				continue;
+			geom_id = geom_lookupid(&geom_tree, snap_iter->id);
+
+			/* New device? refresh GEOM tree */
+			if (geom_id == NULL) {
+				geom_deletetree(&geom_tree);
+				if (geom_gettree(&geom_tree) != 0) {
+					ERROR("disk plugin: geom_gettree() failed");
+					geom_stats_snapshot_free(snap);
+					return (-1);
+				}
+				geom_id = geom_lookupid(&geom_tree, snap_iter->id);
+			}
+			/*
+			 * This should be rare: the device come right before we take the
+			 * snapshot and went away right after it.  We will handle this
+			 * case later, so don't mark dirty but silently ignore it.
+			 */
+			if (geom_id == NULL)
+				continue;
+
+			/* Only collect PROVIDER data */
+			if (geom_id->lg_what != ISPROVIDER)
+				continue;
+
+			/* Only collect data when rank is 1 (physical devices) */
+			if (((struct gprovider *)(geom_id->lg_ptr))->lg_geom->lg_rank != 1)
+				continue;
+
+			/* Check if this is a dirty read quit for another try */
+			if (snap_iter->sequence0 != snap_iter->sequence1) {
+				dirty = 1;
+				break;
+			}
+		}
+	}
+
+	/* Reset iterator */
+	geom_stats_snapshot_reset(snap);
+	for (;;) {
+		snap_iter = geom_stats_snapshot_next(snap);
+		if (snap_iter == NULL)
+			break;
+
+		if (snap_iter->id == NULL)
+			continue;
+		geom_id = geom_lookupid(&geom_tree, snap_iter->id);
+		if (geom_id == NULL)
+			continue;
+		if (geom_id->lg_what != ISPROVIDER)
+			continue;
+		if (((struct gprovider *)(geom_id->lg_ptr))->lg_geom->lg_rank != 1)
+			continue;
+		/* Skip dirty reads, if present */
+		if (dirty && (snap_iter->sequence0 != snap_iter->sequence1))
+			continue;
+
+		disk_name = ((struct gprovider *)geom_id->lg_ptr)->lg_name;
+
+		if ((snap_iter->bytes[1] != 0) || (snap_iter->bytes[2] != 0)) {
+			disk_submit(disk_name, "disk_octets",
+					(derive_t)snap_iter->bytes[1],
+					(derive_t)snap_iter->bytes[2]);
+		}
+
+		if ((snap_iter->operations[1] != 0) || (snap_iter->operations[2] != 0)) {
+			disk_submit(disk_name, "disk_ops",
+					(derive_t)snap_iter->operations[1],
+					(derive_t)snap_iter->operations[2]);
+		}
+
+		read_time = devstat_compute_etime(&snap_iter->duration[DEVSTAT_READ], NULL);
+		write_time = devstat_compute_etime(&snap_iter->duration[DEVSTAT_WRITE], NULL);
+		if ((read_time != 0) || (write_time != 0)) {
+			disk_submit (disk_name, "disk_time",
+					(derive_t)(read_time*1000), (derive_t)(write_time*1000));
+		}
+	}
+	geom_stats_snapshot_free(snap);
+
 #elif KERNEL_LINUX
 	FILE *fh;
 	char buffer[1024];
