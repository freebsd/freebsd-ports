--- src/external/samba.m4.orig	2023-05-05 08:11:07 UTC
+++ src/external/samba.m4
@@ -64,7 +64,7 @@ --without-samba
     else
 
         AC_MSG_CHECKING([Samba's idmap plugin interface version])
-        sambalibdir="`$PKG_CONFIG --variable=libdir smbclient`"/samba
+        sambalibdir="`$PKG_CONFIG --variable=libdir smbclient`"/private
         SAVE_CFLAGS=$CFLAGS
         SAVE_LIBS=$LIBS
         CFLAGS="$CFLAGS $SMBCLIENT_CFLAGS $NDR_NBT_CFLAGS $NDR_KRB5PAC_CFLAGS"
@@ -157,12 +157,16 @@ AC_CHECK_MEMBERS([struct PAC_LOGON_INFO.resource_group
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
