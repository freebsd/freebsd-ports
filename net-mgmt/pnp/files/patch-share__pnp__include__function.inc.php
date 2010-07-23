--- ./share/pnp/include/function.inc.php.orig	2010-05-29 21:26:22.000000000 +0200
+++ ./share/pnp/include/function.inc.php	2010-05-29 21:32:24.000000000 +0200
@@ -1030,7 +1030,7 @@
 		}
 	}
 
-	$pdf =& new PDF('P', 'mm', 'A4');
+	$pdf = new PDF('P', 'mm', 'A4');
 	$pdf->AliasNbPages();
         $pdf->SetAutoPageBreak('off');
 	$pdf->SetMargins(12.5,25,10);
@@ -1540,7 +1540,7 @@
                 $NAGIOS['RRD'][$tag][$dsl] = urldecode($value);
             }
 
-            if($level == 2 && $type == "complete" && eregi("^NAGIOS_",$tag)){
+            if($level == 2 && $type == "complete" && preg_match("/^NAGIOS_/i",$tag)){
                 if(isset($xml_elem['value'])){
                     $value = $xml_elem['value'];
                 }else{
@@ -1571,7 +1571,7 @@
 	$PAGE="";
 	$allowed_tags = array("page", "graph");
 	foreach($data as $line){
-		if(ereg('(^#|^;)',$line)) {
+		if(preg_match('/(^#|^;)/',$line)) {
 			continue;
 		}
 
