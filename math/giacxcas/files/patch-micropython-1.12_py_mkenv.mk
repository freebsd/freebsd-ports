--- micropython-1.12/py/mkenv.mk.orig	2020-04-13 05:21:17 UTC
+++ micropython-1.12/py/mkenv.mk
@@ -46,15 +46,15 @@ PYTHON = python3
 TOUCH = touch
 PYTHON = python3
 
-AS = $(CROSS_COMPILE)as
-CC = $(CROSS_COMPILE)gcc
-CXX = $(CROSS_COMPILE)g++
-GDB = $(CROSS_COMPILE)gdb
-LD = $(CROSS_COMPILE)ld
-OBJCOPY = $(CROSS_COMPILE)objcopy
-SIZE = $(CROSS_COMPILE)size
-STRIP = $(CROSS_COMPILE)strip
-AR = $(CROSS_COMPILE)ar
+#AS = $(CROSS_COMPILE)as
+#CC = $(CROSS_COMPILE)gcc
+#CXX = $(CROSS_COMPILE)g++
+#GDB = $(CROSS_COMPILE)gdb
+#LD = $(CROSS_COMPILE)ld
+#OBJCOPY = $(CROSS_COMPILE)objcopy
+#SIZE = $(CROSS_COMPILE)size
+#STRIP = $(CROSS_COMPILE)strip
+#AR = $(CROSS_COMPILE)ar
 ifeq ($(MICROPY_FORCE_32BIT),1)
 CC += -m32
 CXX += -m32
