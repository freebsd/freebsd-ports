--- testsuite/get_path_to_exe.pro.orig	2025-12-18 17:13:01 UTC
+++ testsuite/get_path_to_exe.pro
@@ -11,7 +11,7 @@ known_case=0
 ;
 ; On Linux, this is fine with GDL, IDL & FL
 ;
-if (STRLOWCASE(!version.os) EQ 'linux') then begin
+if (STRLOWCASE(!version.os_family) eq 'unix') then begin
    get_pid=FILE_READLINK('/proc/self')
    get_abspath_to_exe=FILE_READLINK('/proc/'+get_pid+'/exe')
    known_case=1
