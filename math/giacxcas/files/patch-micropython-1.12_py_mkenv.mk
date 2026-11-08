--- micropython-1.12/py/mkenv.mk.orig	2026-10-04 08:37:56 UTC
+++ micropython-1.12/py/mkenv.mk
@@ -46,15 +46,15 @@ PYTHON = /usr/local/bin/python3.12
 TOUCH = touch
 PYTHON = /usr/local/bin/python3.12
 
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
