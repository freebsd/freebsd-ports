
$FreeBSD$

--- rules.mak.orig
+++ rules.mak
@@ -42,9 +42,9 @@
 SUBDIRS = wrapper asterisk-driver
 .PHONY: all build install clean subdirs_build subdir_install subdir_clean \
 		rpm rpm_clean help $(SUBDIRS)
-CC = gcc
-CPP = g++
-MAKE = make
+CC ?= gcc
+CPP ?= g++
+MAKE ?= make
 INSTALL = install
 TOUCH = touch
 AR = ar
@@ -63,8 +63,8 @@
 
 # Set the C++ compiler flags (for wrapper compilation)
 # and C compiler flags (for channel driver compilation)
-CPPFLAGS = -Wall -felide-constructors -x c++ -Os
-CFLAGS = -Wall
+CPPFLAGS += $(CXXFLAGS) -Wall -felide-constructors -x c++
+CFLAGS += -Wall
 ifeq	($(OH323BUILDTYPE),optnotrace)
 OPENH323USERFLAGS := NOTRACE=1
 endif
@@ -78,9 +78,9 @@
 CFLAGS += -DUSE_OLD_CAPABILITIES_API=1
 endif
 
-ifneq	($(PROC),)
-CFLAGS += -march=$(PROC)
-endif
+#ifneq	($(PROC))
+#CFLAGS += -march=$(PROC)
+#endif
 
 ifdef	HAS_OH323MODS
 CPPFLAGS += -DHAS_OH323MODS
@@ -108,7 +108,7 @@
  
 clean: subdirs_clean rpm_clean
 
-all: subdirs_build subdirs_strip subdirs_install
+all: subdirs_build subdirs_strip
 
 subdirs_build:
 	for x in $(SUBDIRS); do $(MAKE) -C $$x build || exit 1 ; done
