--- third_party/federated_compute/src/fcp/client/opstats/pds_backed_opstats_db.cc.orig	2026-08-12 09:02:10 UTC
+++ third_party/federated_compute/src/fcp/client/opstats/pds_backed_opstats_db.cc
@@ -17,6 +17,7 @@
 
 #include <fcntl.h>
 #include <sys/file.h>
+#include <sys/stat.h>
 
 #include <algorithm>
 #include <cstdint>
