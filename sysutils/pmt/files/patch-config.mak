--- config.mak.orig	2005-06-14 19:50:57 UTC
+++ config.mak
@@ -1,6 +1,6 @@
 VERSION = 0.2
 MAKEFLAGS += --print-directory
-PMT_CFLAGS = -std=c99 -Wall -Werror -pedantic \
+PMT_CFLAGS = -std=c99 -Wall -Werror -pedantic -D_XOPEN_SOURCE=500 \
 			 -D_POSIX_SOURCE -DVERSION='$(VERSION)' \
 			 -I. -Ilibowfat
 
