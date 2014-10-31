--- htdocs/caldav.php.orig	2013-07-15 01:12:05 UTC
+++ htdocs/caldav.php
@@ -114,6 +114,8 @@ switch ( $request->method ) {
       include('caldav-POST.php');
       break;
     }
+    error_log('the value of add_member is : ', $add_member);
+    $add_member = true;
   case 'PUT':
     switch( $request->content_type ) {
       case 'text/calendar':
