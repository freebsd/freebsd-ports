--- _support/make-gnu-build-id.sh.orig	2022-03-08 22:36:38 UTC
+++ _support/make-gnu-build-id.sh
@@ -13,7 +13,7 @@ main()
         fail "ERROR: Could not extract Go build-id or generate a random hex string."
     fi
 
-    GNU_BUILD_ID=$( echo $GO_BUILD_ID | sha1sum | cut -d' ' -f1 )
+    GNU_BUILD_ID=$( echo $GO_BUILD_ID | sha1 | cut -d' ' -f1 )
     if [ -z "$GNU_BUILD_ID" ] ; then
         fail "ERROR: Could not generate a GNU build-id"
     fi
