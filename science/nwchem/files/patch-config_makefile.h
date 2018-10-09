--- config/makefile.h.orig	2018-10-01 05:39:33 UTC
+++ config/makefile.h
@@ -1758,9 +1758,9 @@ endif
         ifeq ($(USE_FLANG),1)
         GNU_GE_4_6=true
         else
-        GNUMAJOR=$(shell $(_FC) -dM -E - < /dev/null 2> /dev/null | grep __GNUC__ |cut -c18)
+        GNUMAJOR=$(shell $(FC) -dM -E - < /dev/null 2> /dev/null | grep __GNUC__ |cut -c18)
         ifdef GNUMAJOR
-        GNUMINOR=$(shell $(_FC) -dM -E - < /dev/null 2> /dev/null | egrep __GNUC_MINOR | cut -c24)
+        GNUMINOR=$(shell $(FC) -dM -E - < /dev/null 2> /dev/null | egrep __GNUC_MINOR | cut -c24)
         GNU_GE_4_6 = $(shell [ $(GNUMAJOR) -gt 4 -o \( $(GNUMAJOR) -eq 4 -a $(GNUMINOR) -ge 6 \) ] && echo true)
         GNU_GE_4_8 = $(shell [ $(GNUMAJOR) -gt 4 -o \( $(GNUMAJOR) -eq 4 -a $(GNUMINOR) -ge 8 \) ] && echo true)
         endif
