--- libnemo-private/nemo-statx.c.orig	2018-12-15 14:00:45 UTC
+++ libnemo-private/nemo-statx.c
@@ -21,16 +21,17 @@
 #define _ATFILE_SOURCE
 #include <config.h>
 #include <time.h>
-#include <linux/fcntl.h>        // for AT_FDCWD, AT_NO_AUTOMOUNT
-#include <linux/stat.h>         // for statx, STATX_BTIME, statx_timestamp
 #include <string.h>             // for memset
-#include <syscall.h>            // for __NR_statx
 #include <unistd.h>             // for syscall, ssize_t
 #include <stdio.h>
 #include <errno.h>
 
 #if NATIVE_STATX
 /* native statx call */
+#include <linux/fcntl.h>        // for AT_FDCWD, AT_NO_AUTOMOUNT
+#include <linux/stat.h>         // for statx, STATX_BTIME, statx_timestamp
+#include <syscall.h>            // for __NR_statx
+
 static __attribute__((unused))
 ssize_t statx (int dfd, const char *filename, unsigned flags,
           unsigned int mask, struct statx *buffer)
@@ -41,6 +42,11 @@ ssize_t statx (int dfd, const char *filename, unsigned
 #else
 /* statx wrapper/compatibility */
 
+#define AT_FDCWD		-100    /* Special value used to indicate
+                                           openat should use the current
+                                           working directory. */
+#define AT_NO_AUTOMOUNT		0x800	/* Suppress terminal automount traversal */
+
 /* this code works ony with x86 and x86_64 */
 #if __x86_64__
 #define __NR_statx 332
@@ -51,39 +57,39 @@ ssize_t statx (int dfd, const char *filename, unsigned
 #define STATX_BTIME             0x00000800U     /* Want/got stx_btime */
 
 struct statx_timestamp {
-    __s64   tv_sec;
-    __u32   tv_nsec;
-    __s32   __reserved;
+    int64_t   tv_sec;
+    uint32_t   tv_nsec;
+    int32_t   __reserved;
 };
 
 struct statx {
     /* 0x00 */
-    __u32                   stx_mask;       /* What results were written [uncond] */
-    __u32                   stx_blksize;    /* Preferred general I/O size [uncond] */
-    __u64                   stx_attributes; /* Flags conveying information about the file [uncond] */
+    uint32_t                   stx_mask;       /* What results were written [uncond] */
+    uint32_t                   stx_blksize;    /* Preferred general I/O size [uncond] */
+    uint64_t                   stx_attributes; /* Flags conveying information about the file [uncond] */
     /* 0x10 */
-    __u32                   stx_nlink;      /* Number of hard links */
-    __u32                   stx_uid;        /* User ID of owner */
-    __u32                   stx_gid;        /* Group ID of owner */
-    __u16                   stx_mode;       /* File mode */
-    __u16                   __spare0[1];
+    uint32_t                   stx_nlink;      /* Number of hard links */
+    uint32_t                   stx_uid;        /* User ID of owner */
+    uint32_t                   stx_gid;        /* Group ID of owner */
+    uint16_t                   stx_mode;       /* File mode */
+    uint16_t                   __spare0[1];
     /* 0x20 */
-    __u64                   stx_ino;        /* Inode number */
-    __u64                   stx_size;       /* File size */
-    __u64                   stx_blocks;     /* Number of 512-byte blocks allocated */
-    __u64                   stx_attributes_mask; /* Mask to show what's supported in stx_attributes */
+    uint64_t                   stx_ino;        /* Inode number */
+    uint64_t                   stx_size;       /* File size */
+    uint64_t                   stx_blocks;     /* Number of 512-byte blocks allocated */
+    uint64_t                   stx_attributes_mask; /* Mask to show what's supported in stx_attributes */
     /* 0x40 */
     struct statx_timestamp  stx_atime;      /* Last access time */
     struct statx_timestamp  stx_btime;      /* File creation time */
     struct statx_timestamp  stx_ctime;      /* Last attribute change time */
     struct statx_timestamp  stx_mtime;      /* Last data modification time */
     /* 0x80 */
-    __u32                   stx_rdev_major; /* Device ID of special file [if bdev/cdev] */
-    __u32                   stx_rdev_minor;
-    __u32                   stx_dev_major;  /* ID of device containing file [uncond] */
-    __u32                   stx_dev_minor;
+    uint32_t                   stx_rdev_major; /* Device ID of special file [if bdev/cdev] */
+    uint32_t                   stx_rdev_minor;
+    uint32_t                   stx_dev_major;  /* ID of device containing file [uncond] */
+    uint32_t                   stx_dev_minor;
     /* 0x90 */
-    __u64                   __spare2[14];   /* Spare space for future expansion */
+    uint64_t                   __spare2[14];   /* Spare space for future expansion */
     /* 0x100 */
 };
 
@@ -129,4 +135,4 @@ get_file_btime (const char *path)
     btime = (&stxbuf)->stx_btime.tv_sec;
 
     return btime;
-}
\ No newline at end of file
+}
