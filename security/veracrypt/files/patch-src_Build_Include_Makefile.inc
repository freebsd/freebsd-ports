--- src/Build/Include/Makefile.inc.orig	2026-06-09 10:55:00 UTC
+++ src/Build/Include/Makefile.inc
@@ -26,23 +26,43 @@ clean:
 	
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
 
 %.oavx2: %.c
 	@echo Compiling $(<F)
+ifeq "$(PLATFORM_ARCH)" "arm64"
+	$(CC) $(CFLAGS) -c $< -o $@
+else
 	$(CC) $(CFLAGS) -mavx2 -c $< -o $@
+endif
 
 %.oarmv8crypto: %.c
 	@echo Compiling $(<F)
