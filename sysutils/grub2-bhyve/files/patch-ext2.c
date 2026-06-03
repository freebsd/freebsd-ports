--- grub-core/fs/ext2.c
+++ grub-core/fs/ext2.c
@@ -100,7 +100,10 @@ GRUB_MOD_LICENSE ("GPLv3+");
 #define EXT2_FEATURE_INCOMPAT_META_BG		0x0010
 #define EXT4_FEATURE_INCOMPAT_EXTENTS		0x0040 /* Extents used */
 #define EXT4_FEATURE_INCOMPAT_64BIT		0x0080
+#define EXT4_FEATURE_INCOMPAT_MMP		0x0100
 #define EXT4_FEATURE_INCOMPAT_FLEX_BG		0x0200
+#define EXT4_FEATURE_INCOMPAT_CSUM_SEED		0x2000
+#define EXT4_FEATURE_INCOMPAT_LARGEDIR		0x4000 /* >2GB or 3 level htree */
 
 /* The set of back-incompatible features this driver DOES support. Add (OR)
  * flags here as the related features are implemented into the driver.  */
@@ -114,8 +117,26 @@ GRUB_MOD_LICENSE ("GPLv3+");
  *                 journal because they will ignore the journal, but the next
  *                 ext3 driver to mount the volume will find the journal and
  *                 replay it, potentially corrupting the metadata written by
- *                 the ext2 drivers. Safe to ignore for this RO driver.  */
-#define EXT2_DRIVER_IGNORED_INCOMPAT ( EXT3_FEATURE_INCOMPAT_RECOVER )
+ *                 the ext2 drivers. Safe to ignore for this RO driver.
+ * mmp:            Not really back-incompatible - was added as such to
+ *                 avoid multiple read-write mounts. Safe to ignore for this
+ *                 RO driver.
+ * checksum seed:  Not really back-incompatible - was added to allow tools
+ *                 such as tune2fs to change the UUID on a mounted metadata
+ *                 checksummed filesystem. Safe to ignore for now since the
+ *                 driver doesn't support checksum verification. However, it
+ *                 has to be removed from this list if the support is added later.
+ * large_dir:      Not back-incompatible given that the GRUB ext2 driver does
+ *                 not implement EXT2_FEATURE_COMPAT_DIR_INDEX. If the GRUB
+ *                 eventually supports the htree feature (aka dir_index)
+ *                 it should support 3 level htrees and then move
+ *                 EXT4_FEATURE_INCOMPAT_LARGEDIR to
+ *                 EXT2_DRIVER_SUPPORTED_INCOMPAT.
+ */
+#define EXT2_DRIVER_IGNORED_INCOMPAT ( EXT3_FEATURE_INCOMPAT_RECOVER \
+                                      | EXT4_FEATURE_INCOMPAT_MMP \
+                                      | EXT4_FEATURE_INCOMPAT_CSUM_SEED \
+                                      | EXT4_FEATURE_INCOMPAT_LARGEDIR)
 
 
 #define EXT3_JOURNAL_MAGIC_NUMBER	0xc03b3998U
