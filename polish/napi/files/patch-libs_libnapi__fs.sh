--- libs/libnapi_fs.sh.orig	2020-04-24 07:22:41 UTC
+++ libs/libnapi_fs.sh
@@ -54,7 +54,7 @@ _fs_configureStat_GV() {
     # verify stat tool
     ___g_fsWrappers[$___g_fsStat]="stat -c%s "
 
-    if wrappers_isSystemDarwin; then
+    if wrappers_isSystemDarwin || wrappers_isSystemFreeBSD; then
         # stat may be installed through macports, check if
         # there's a need to reconfigure it to BSD flavour
         ${___g_fsWrappers[$___g_fsStat]} "$0" >/dev/null 2>&1 ||
@@ -72,6 +72,8 @@ _fs_configureBase64_GV() {
     # verify base64
     wrappers_isSystemDarwin &&
         ___g_fsWrappers[$___g_fsBase64]="base64 -D"
+    wrappers_isSystemFreeBSD &&
+        ___g_fsWrappers[$___g_fsBase64]="base64 -d"
 }
 
 #
@@ -83,6 +85,8 @@ _fs_configureMd5_GV() {
     # verify md5 tool
     ___g_fsWrappers[$___g_fsMd5]="md5sum"
     wrappers_isSystemDarwin &&
+        ___g_fsWrappers[$___g_fsMd5]="md5"
+    wrappers_isSystemFreeBSD &&
         ___g_fsWrappers[$___g_fsMd5]="md5"
 }
 
