--- htdocs/download_binary_attr.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/download_binary_attr.php
@@ -15,7 +15,7 @@ require './common.php';
 
 $request = array();
 $request['dn'] = get_request('dn','GET');
-$request['attr'] = strtolower(get_request('attr','GET',true));
+$request['attr'] = strtolower((string) get_request('attr','GET',true));
 $request['index'] = get_request('index','GET',false,0);
 $request['type'] = get_request('type','GET',false,'octet-stream');
 $request['filename'] = get_request('filename','GET',false,sprintf('%s:%s.bin',get_rdn($request['dn'],true),$request['attr']));
