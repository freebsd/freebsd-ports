--- src/external/samba.m4.orig	2024-05-16 11:35:27 UTC
+++ src/external/samba.m4
@@ -63,7 +63,7 @@ --without-samba
             AC_MSG_ERROR([Illegal value -$with_smb_idmap_interface_version- for option --with-smb-idmap-interface-version])
         fi
     else
-        sambalibdir="`$PKG_CONFIG --variable=libdir smbclient`"/samba
+        sambalibdir="`$PKG_CONFIG --variable=libdir smbclient`"/private
         AC_MSG_CHECKING([Samba's idmap library])
         if test -f "${sambalibdir}/libidmap-private-samba.so"; then
                 IDMAP_SAMBA_LIBS=idmap-private-samba
@@ -166,12 +166,16 @@ AC_CHECK_MEMBERS([struct PAC_LOGON_INFO.resource_group
 SAVE_CFLAGS=$CFLAGS
 CFLAGS="$CFLAGS $SMBCLIENT_CFLAGS $NDR_NBT_CFLAGS $NDR_KRB5PAC_CFLAGS"
 AC_CHECK_MEMBERS([struct PAC_LOGON_INFO.resource_groups], , ,
-                 [[ #include <ndr.h>
-                    #include <gen_ndr/krb5pac.h>
+                 [[ #include <sys/types.h>
+                    #include <sys/time.h>
+                    #include <time.h>
+                    #include <ndr.h>
                     #include <gen_ndr/krb5pac.h>]])
 AC_CHECK_MEMBERS([struct PAC_UPN_DNS_INFO.ex], ,
                  [AC_MSG_NOTICE([union PAC_UPN_DNS_INFO_EX is not available, PAC checks will be limited])],
-                 [[ #include <ndr.h>
-                    #include <gen_ndr/krb5pac.h>
+                 [[ #include <sys/types.h>
+                    #include <sys/time.h>
+                    #include <time.h>
+                    #include <ndr.h>
                     #include <gen_ndr/krb5pac.h>]])
 CFLAGS=$SAVE_CFLAGS
