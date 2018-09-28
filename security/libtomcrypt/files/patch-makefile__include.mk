--- makefile_include.mk.orig	2018-09-28 13:43:18 UTC
+++ makefile_include.mk
@@ -73,8 +73,6 @@ LTC_CFLAGS += -Wdeclaration-after-statement
 LTC_CFLAGS += -Wwrite-strings
 endif
 
-LTC_CFLAGS += -Wno-type-limits
-
 ifdef LTC_DEBUG
 $(info Debug build)
 # compile for DEBUGGING (required for ccmalloc checking!!!)
