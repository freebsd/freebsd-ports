# Description: Hangs on freebsd when starting shell
# Issue ID: https://github.com/fish-shell/fish-shell/issues/1741
# TODO: Remove after 2.1.2 update

--- env_universal_common.cpp.orig	2015-04-18 11:58:07 UTC
+++ env_universal_common.cpp
@@ -151,6 +151,7 @@ static const char *iconv_wide_names_4[]=
 {
     "wchar_t", "WCHAR_T",
     "wchar", "WCHAR",
+    "UCS-4-INTERNAL", 
     "ucs-4", "UCS-4",
     "ucs4", "UCS4",
     "utf-32", "UTF-32",
