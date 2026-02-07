--- micropython-1.12/py/dynruntime.mk.orig	2020-04-13 05:21:17 UTC
+++ micropython-1.12/py/dynruntime.mk
@@ -24,8 +24,6 @@ CFLAGS += -std=c99
 
 CFLAGS += -I. -I$(MPY_DIR)
 CFLAGS += -std=c99
-CFLAGS += -Os
-CFLAGS += -Wall -Werror -DNDEBUG
 CFLAGS += -DNO_QSTR
 CFLAGS += -DMP_CONFIGFILE='<$(CONFIG_H)>'
 CFLAGS += -fpic -fno-common
@@ -126,7 +124,7 @@ $(BUILD)/%.o: %.c $(CONFIG_H) Makefile
 # Build .o from .c source files
 $(BUILD)/%.o: %.c $(CONFIG_H) Makefile
 	$(ECHO) "CC $<"
-	$(Q)$(CROSS)gcc $(CFLAGS) -o $@ -c $<
+	$(Q)$(CC) $(CFLAGS) -o $@ -c $<
 
 # Build .mpy from .py source files
 $(BUILD)/%.mpy: %.py
