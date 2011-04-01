--- ./third_party/WebKit/Source/WebCore/platform/UUID.cpp.orig	2011-01-25 10:33:42.000000000 +0100
+++ ./third_party/WebKit/Source/WebCore/platform/UUID.cpp	2011-01-25 10:43:15.000000000 +0100
@@ -41,6 +41,8 @@
 #include <objbase.h>
 #elif OS(DARWIN)
 #include <CoreFoundation/CoreFoundation.h>
+#elif OS(FREEBSD)
+#include <uuid.h>
 #elif OS(LINUX) && !PLATFORM(CHROMIUM)
 #include <stdio.h>
 #elif OS(LINUX) && PLATFORM(CHROMIUM)
@@ -80,6 +82,23 @@
     String canonicalUuidStr = uuidStr.lower(); // make it lower.
     ASSERT(canonicalUuidStr[uuidVersionIdentifierIndex] == uuidVersionRequired);
     return canonicalUuidStr;
+#elif OS(FREEBSD)
+    uuid_t *store;
+    char *uuid;
+    store = (uuid_t*)malloc(sizeof(uuid_t));
+    if (store == NULL)
+        return String();
+
+    if (uuidgen(store, 1) != 0)
+        return String();
+
+    uuid_to_string(store, &uuid, NULL);
+    String canonicalUuidStr = String(uuid).lower(); // make it lower
+    free(uuid);
+    free(store);
+    ASSERT(canonicalUuidStr[uuidVersionIdentifierIndex] == uuidVersionRequired);
+    return canonicalUuidStr;
+
 #elif OS(LINUX) && !PLATFORM(CHROMIUM)
     // This does not work for the linux system that turns on sandbox.
     FILE* fptr = fopen("/proc/sys/kernel/random/uuid", "r");
