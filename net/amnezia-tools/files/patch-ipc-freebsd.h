--- ipc-freebsd.h.orig	2026-08-12 00:00:00 UTC
+++ ipc-freebsd.h
@@ -20,1 +20,1 @@
-		sock = socket(AF_INET, SOCK_DGRAM, 0);
+		sock = socket(AF_LOCAL, SOCK_DGRAM, 0);
@@ -24,1 +24,1 @@
-	struct ifgroupreq ifgr = { .ifgr_name = "wg" };
+	struct ifgroupreq ifgr = { .ifgr_name = "amn" };
@@ -551,1 +551,1 @@
-		nvlist_add_binary(nvl_device, "i1", dev->i1, strlen(dev->i1) + 1);
+		nvlist_add_binary(nvl_device, "i1", dev->i1 ? dev->i1 : "", strlen(dev->i1 ? dev->i1 : "") + 1);
@@ -553,1 +553,1 @@
-		nvlist_add_binary(nvl_device, "i2", dev->i2, strlen(dev->i2) + 1);
+		nvlist_add_binary(nvl_device, "i2", dev->i2 ? dev->i2 : "", strlen(dev->i2 ? dev->i2 : "") + 1);
@@ -555,1 +555,1 @@
-		nvlist_add_binary(nvl_device, "i3", dev->i3, strlen(dev->i3) + 1);
+		nvlist_add_binary(nvl_device, "i3", dev->i3 ? dev->i3 : "", strlen(dev->i3 ? dev->i3 : "") + 1);
@@ -557,1 +557,1 @@
-		nvlist_add_binary(nvl_device, "i4", dev->i4, strlen(dev->i4) + 1);
+		nvlist_add_binary(nvl_device, "i4", dev->i4 ? dev->i4 : "", strlen(dev->i4 ? dev->i4 : "") + 1);
@@ -559,1 +559,1 @@
-		nvlist_add_binary(nvl_device, "i5", dev->i5, strlen(dev->i5) + 1);
+		nvlist_add_binary(nvl_device, "i5", dev->i5 ? dev->i5 : "", strlen(dev->i5 ? dev->i5 : "") + 1);
