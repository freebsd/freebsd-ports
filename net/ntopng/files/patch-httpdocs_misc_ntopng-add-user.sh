--- httpdocs/misc/ntopng-add-user.sh.orig	2020-06-15 13:08:57 UTC
+++ httpdocs/misc/ntopng-add-user.sh
@@ -111,13 +111,13 @@ function validate_username {
 
 function password_md5 {
     #make sure the md5 utility works as expected
-    local admin_md5=`echo -n admin | md5sum | cut -c 1-32`
+    local admin_md5=`echo -n admin | md5 | cut -c 1-32`
     if [[ $admin_md5 != "21232f297a57a5a743894a0e4a801fc3" ]]
     then
 	echo "md5sum not working as expected"
 	return 1
     fi
-    NTOPNG_PASSWORD_MD5=`echo -n $NTOPNG_PASSWORD | md5sum | cut -c 1-32`
+    NTOPNG_PASSWORD_MD5=`echo -n $NTOPNG_PASSWORD | md5 | cut -c 1-32`
     return 0
 }
 
