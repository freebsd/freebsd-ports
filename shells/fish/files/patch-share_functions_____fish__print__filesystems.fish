--- share/functions/__fish_print_filesystems.fish.orig	2017-02-03 01:46:58 UTC
+++ share/functions/__fish_print_filesystems.fish
@@ -4,6 +4,6 @@ function __fish_print_filesystems -d "Pr
     set fs $fs hfs hpfs iso9660 jfs minix msdos ncpfs nfs ntfs proc qnx4 ramfs
     set fs $fs reiserfs romfs smbfs sysv tmpfs udf ufs umsdos vfat xenix xfs xiafs
     # Mount has helper binaries to mount filesystems
-    # These are called mount.* and are placed somewhere in $PATH
-    printf "%s\n" $fs (string replace -ra ".*/mount." "" -- $PATH/mount.*)
+    # These are called mount_* and are placed somewhere in $PATH
+    printf "%s\n" $fs (string replace -ra ".*/mount_" "" -- $PATH/mount_*)
 end
