--- general.make.orig	2026-03-30 08:52:40 UTC
+++ general.make
@@ -16,6 +16,7 @@ ADDITIONAL_OBJCFLAGS=-O0
 ADDITIONAL_OBJCFLAGS=-O2
 ifeq ($(debug),yes)
 ADDITIONAL_OBJCFLAGS=-O0
+ADDITIONAL_OBJCFLAGS += -g $(call cc-option,-frecord-gcc-switches)
 else
 ADDITIONAL_OBJCFLAGS=-Wuninitialized
 endif
@@ -23,5 +24,3 @@ endif
 # information plus the compiler flags used; that can
 # be afterwards read with:
 # readelf -p .GCC.command.line /path/to/elf_file
-ADDITIONAL_OBJCFLAGS += -g $(call cc-option,-frecord-gcc-switches)
-
