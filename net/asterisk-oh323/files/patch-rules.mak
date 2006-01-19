--- rules.mak.orig	Wed Jan 18 10:53:49 2006
+++ rules.mak	Wed Jan 18 11:45:16 2006
@@ -42,9 +42,8 @@
 SUBDIRS = wrapper asterisk-driver
 .PHONY: all build install clean subdirs_build subdir_install subdir_clean \
 		rpm rpm_clean help $(SUBDIRS)
-CC = gcc
-CPP = g++
-MAKE = make
+CC ?= gcc
+CPP ?= g++
 INSTALL = install
 TOUCH = touch
 AR = ar
@@ -108,7 +107,7 @@
  
 clean: subdirs_clean rpm_clean
 
-all: subdirs_build subdirs_strip subdirs_install
+all: subdirs_build subdirs_strip
 
 subdirs_build:
 	for x in $(SUBDIRS); do $(MAKE) -C $$x build || exit 1 ; done
