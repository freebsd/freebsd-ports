--- setup.sh.orig	2013-02-09 21:55:43.000000000 +0100
+++ setup.sh	2013-09-12 21:34:08.051742488 +0200
@@ -19,8 +19,9 @@
 tim=($(date '+%s %Y-%m-%d %T'))
 
 have_fuse=0
-[[ $NO_FUSE != 1 && -r /usr/include/fuse.h || -r /usr/local/include/fuse.h ]] \
-	&& have_fuse=1
+# TO DO: Fix fuse compilation (need to add a dependency to the port Makefile too
+#[[ $NO_FUSE != 1 && -r /usr/include/fuse.h || -r /usr/local/include/fuse.h ]] \
+#	&& have_fuse=1
 
 if [[ $M32 = 1 ]]
 then
@@ -38,9 +39,13 @@
 	&& grep -qw fallocate /usr/include/bits/fcntl.h \
 	&& defines="$defines -DHAVE_FALLOCATE=1"
 
-[[ -r /usr/include/fcntl.h ]] \
-	&& grep -qw posix_fallocate /usr/include/fcntl.h \
-	&& defines="$defines -DHAVE_POSIX_FALLOCATE=1"
+# Wrong test: FreeBSD fcntl.h include a comment with string "posix_fallocate"
+#[[ -r /usr/include/fcntl.h ]] \
+#	&& grep -qw posix_fallocate /usr/include/fcntl.h \
+#	&& defines="$defines -DHAVE_POSIX_FALLOCATE=1"
+
+# FreeBSD didn't support Pre-alloc
+defines="$defines -DNO_PREALLOC"
 
 [[ -r /usr/include/linux/fiemap.h ]] \
 	&& grep -qw fiemap_extent /usr/include/linux/fiemap.h \
@@ -110,6 +115,6 @@
 
 	---EOT---
 
-gcc $xflags system.c -o system.tmp && ./system.tmp >>Makefile.setup
+${CC} $xflags system.c -o system.tmp && ./system.tmp >>Makefile.setup
 rm -f system.tmp
