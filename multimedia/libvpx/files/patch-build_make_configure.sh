
$FreeBSD$

--- build/make/configure.sh.orig
+++ build/make/configure.sh
@@ -1135,7 +1135,7 @@
 print_webm_license() {
     local destination=$1
     local prefix=$2
-    local suffix=$3
+    local suffix="$3"
     shift 3
     cat <<EOF > ${destination}
 ${prefix} Copyright (c) 2011 The WebM project authors. All Rights Reserved.${suffix}
