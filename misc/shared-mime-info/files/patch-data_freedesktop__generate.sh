https://gitlab.freedesktop.org/xdg/shared-mime-info/-/issues/170

--- data/freedesktop_generate.sh.orig	2021-10-19 15:24:23 UTC
+++ data/freedesktop_generate.sh
@@ -9,4 +9,4 @@ itstool \
     --its "${src_root}/data/its/shared-mime-info.its" \
     --join "${src_root}/data/freedesktop.org.xml.in" \
     -o "${build_root}/data/freedesktop.org.xml" \
-    "${build_root}/po/"*".gmo"
+    "${build_root}/po/"*"/LC_MESSAGES/"*".mo"
