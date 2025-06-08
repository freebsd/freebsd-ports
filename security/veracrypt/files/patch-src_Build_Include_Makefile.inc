--- src/Build/Include/Makefile.inc	2025-06-07 16:38:57.314038000 -0700
+++ src/Build/Include/Makefile.inc	2025-06-07 16:41:54.192457000 -0700
@@ -26,19 +26,35 @@
 	
 %.osse41: %.c
 	@echo Compiling $(<F)
+ifeq "$(PLATFORM_ARCH)" "arm64"
+	$(CC) $(CFLAGS) -c $< -o $@
+else
 	$(CC) $(CFLAGS) -mssse3 -msse4.1 -c $< -o $@
+endif
 
 %.oshani: %.c
 	@echo Compiling $(<F)
+ifeq "$(PLATFORM_ARCH)" "arm64"
+	$(CC) $(CFLAGS) -c $< -o $@
+else
 	$(CC) $(CFLAGS) -mssse3 -msse4.1 -msha -c $< -o $@
+endif
 
 %.oaesni: %.c
 	@echo Compiling $(<F)
+ifeq "$(PLATFORM_ARCH)" "arm64"
+	$(CC) $(CFLAGS) -c $< -o $@
+else
 	$(CC) $(CFLAGS) -mssse3 -msse4.1 -maes -c $< -o $@
+endif
 	
 %.ossse3: %.c
 	@echo Compiling $(<F)
+ifeq "$(PLATFORM_ARCH)" "arm64"
+	$(CC) $(CFLAGS) -c $< -o $@
+else
 	$(CC) $(CFLAGS) -mssse3 -c $< -o $@
+endif
 
 %.oarmv8crypto: %.c
 	@echo Compiling $(<F)
