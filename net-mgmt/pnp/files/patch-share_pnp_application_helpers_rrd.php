--- share/pnp/application/helpers/rrd.php.orig	2017-08-21 15:52:37 UTC
+++ share/pnp/application/helpers/rrd.php
@@ -207,7 +207,7 @@ class rrd_Core {
         if(is_array($cf)){
             foreach($cf as $key => $val){
                 $line .= sprintf("GPRINT:%s:%s:",$vname,$val);
-                if($key == sizeof($cf)-1){
+                if($key == count($cf)-1){
                     $line .= '"'.$text.' '.ucfirst(strtolower($val)).'\\l" ';
                 }else{
                     $line .= '"'.$text.' '.ucfirst(strtolower($val)).'" ';
@@ -234,7 +234,7 @@ class rrd_Core {
         if(is_array($cf)){
             foreach($cf as $key => $val){
                 $line .= sprintf("GPRINT:%s:%s:",$vname,$val);
-                if(($key == sizeof($cf)-1)and($align != "")){
+                if(($key == count($cf)-1)and($align != "")){
                     $line .= '"'.$text.' '.ucfirst(strtolower($val)).$align.'" ';
                 }else{
                     $line .= '"'.$text.' '.ucfirst(strtolower($val)).'" ';
