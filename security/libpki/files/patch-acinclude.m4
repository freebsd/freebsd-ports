--- acinclude.m4.orig	2023-06-27 08:58:28.460201000 +0200
+++ acinclude.m4	2023-06-27 13:17:52.671338000 +0200
@@ -116,7 +116,12 @@
 
 		AC_MSG_RESULT([Searching OpenSSL Version: $library_includes]);
 		ver=`grep "^ *# *define  *OPENSSL_VERSION_NUMBER" "$library_includes" | sed 's/.*0x/0x/g' | sed 's|\L||g'`;
-		detected_v=`echo $((ver))`
+		if [[ "x$ver" == "x" ]] ; then
+		   pver=`grep "^ *# *define OPENSSL_VERSION_PRE_RELEASE" "$library_includes" | sed 's|.* "|"|g' | sed 's|""|fL|g' | sed 's|".*"|0L|g'`
+		   bver=`grep "^ *# *define OPENSSL_VERSION_STR" "$library_includes"  | sed 's|.* "||g' | sed 's|".*||g' | sed 's|\.| |g' | xargs printf "0x%1x%02X%02X" `
+		   ver="$bver$pver"
+		fi
+                detected_v=`echo $((ver))`
 		required_v=`echo $(($_version))`
 
 		dnl ver=`grep "^ *# *define  *SHLIB_VERSION_NUMBER" $library_includes | sed 's/[#_a-zA-Z" ]//g' | sed 's|\.|0|g'`;
