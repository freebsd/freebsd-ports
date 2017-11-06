--- htdocs/caldav.php.orig	2017-01-30 20:16:26 UTC
+++ htdocs/caldav.php
@@ -119,6 +119,8 @@ try {
         include('caldav-POST.php');
         break;
       }
+      error_log('the value of add_member is : ', $add_member);
+      $add_member = true;
       // fall through if POST add member
     case 'PUT':
       switch( $request->content_type ) {
