--- ./config.mak.orig	2010-01-06 08:21:36.000000000 -0500
+++ ./config.mak	2010-01-06 08:21:54.000000000 -0500
@@ -1,6 +1,6 @@
 VERSION = 0.2
 MAKEFLAGS += --print-directory
-PMT_CFLAGS = -std=c99 -Wall -Werror -pedantic \
+PMT_CFLAGS = -std=c99 -Wall -Werror -pedantic -D__XSI_VISIBLE \
 			 -D_POSIX_SOURCE -DVERSION='$(VERSION)' \
 			 -I. -Ilibowfat
 
