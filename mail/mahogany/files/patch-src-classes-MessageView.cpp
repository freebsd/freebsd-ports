--- src/classes/MessageView.cpp.orig	Mon Jan  1 18:26:12 2007
+++ src/classes/MessageView.cpp	Mon Jan  1 18:51:17 2007
@@ -2473,7 +2473,7 @@
    CHECK( !cidOrig.empty(), false, "empty CID not allowed" );
 
    String cid;
-   if ( *cidOrig.begin() == '<' && *cidOrig.rbegin() == '>' )
+   if ( *cidOrig.begin() == '<' && cidOrig.Last() == '>' )
       cid.assign(cidOrig, 1, cidOrig.length() - 2);
    else
       cid = cidOrig;
