--- setup.sh.orig	2011-07-08 20:21:46.000000000 +0200
+++ setup.sh	2011-08-04 01:55:05.000000000 +0200
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
 
 [[ $STATIC = 1 ]] || STATIC=0
 
