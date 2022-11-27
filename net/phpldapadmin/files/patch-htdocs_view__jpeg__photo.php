--- htdocs/view_jpeg_photo.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/view_jpeg_photo.php
@@ -15,7 +15,7 @@ require './common.php';
 
 $request = array();
 $request['dn'] = get_request('dn','GET');
-$request['attr'] = strtolower(get_request('attr','GET',false,'jpegphoto'));
+$request['attr'] = strtolower((string) get_request('attr','GET',false,'jpegphoto'));
 $request['index'] = get_request('index','GET',false,0);
 $request['type'] = get_request('type','GET',false,'image/jpeg');
 $request['filename'] = get_request('filename','GET',false,sprintf('%s.jpg',get_rdn($request['dn'],true)));
