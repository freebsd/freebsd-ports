
$FreeBSD$

--- cmd/platlibs.mk	Wed Apr  6 17:35:41 2005
+++ cmd/platlibs.mk	Wed Jul 27 22:22:59 2005
@@ -72,5 +72,4 @@
 	$(DIST)/lib/$(LIB_PREFIX)nssdev.$(LIB_SUFFIX) \
 	$(DIST)/lib/$(LIB_PREFIX)nssb.$(LIB_SUFFIX) \
-	$(DIST)/lib/$(LIB_PREFIX)dbm.$(LIB_SUFFIX) \
 	$(DIST)/lib/$(NSPR31_LIB_PREFIX)plc4.$(LIB_SUFFIX) \
 	$(DIST)/lib/$(NSPR31_LIB_PREFIX)plds4.$(LIB_SUFFIX) \
@@ -85,5 +84,4 @@
 
 JAR_LIBS = $(DIST)/lib/$(LIB_PREFIX)jar.$(LIB_SUFFIX) \
-	$(DIST)/lib/$(LIB_PREFIX)zlib.$(LIB_SUFFIX) \
 	$(NULL)
 else
@@ -120,5 +118,4 @@
 	$(CRYPTOLIB) \
 	$(DIST)/lib/$(LIB_PREFIX)secutil.$(LIB_SUFFIX) \
-	$(DIST)/lib/$(LIB_PREFIX)dbm.$(LIB_SUFFIX) \
 	$(NULL)
 
@@ -141,4 +138,5 @@
 	-lplds4 \
 	-lnspr4 \
+	-lz \
 	$(NULL)
 endif
@@ -146,5 +144,4 @@
 
 JAR_LIBS = $(DIST)/lib/$(LIB_PREFIX)jar.$(LIB_SUFFIX) \
-	$(DIST)/lib/$(LIB_PREFIX)zlib.$(LIB_SUFFIX) \
 	$(NULL)
 
@@ -171,5 +168,4 @@
 
 JAR_LIBS = $(DIST)/lib/$(LIB_PREFIX)jar.$(LIB_SUFFIX) \
-	$(DIST)/lib/$(LIB_PREFIX)zlib.$(LIB_SUFFIX) \
 	$(NULL)
 else
@@ -226,8 +222,8 @@
 	-lplds4 \
 	-lnspr4 \
+	-lz \
 	$(NULL)
 
 JAR_LIBS = $(DIST)/lib/$(LIB_PREFIX)jar.$(LIB_SUFFIX) \
-	$(DIST)/lib/$(LIB_PREFIX)zlib.$(LIB_SUFFIX) \
 	$(NULL)
 endif
