--- lib/htmlfilter.php.orig	2007-06-14 19:00:15 UTC
+++ lib/htmlfilter.php
@@ -106,8 +106,8 @@ function casenormalize(&$val){
 function skipspace($body, $offset){
     $me = 'skipspace';
     preg_match('/^(\s*)/s', substr($body, $offset), $matches);
-    if (sizeof($matches{1})){
-        $count = strlen($matches{1});
+    if (is_array($matches[1]) && sizeof($matches[1])){
+        $count = strlen($matches[1]);
         spew("$me: skipped $count chars\n");
         $offset += $count;
     }
@@ -159,10 +159,10 @@ function findnxreg($body, $offset, $reg){
         spew("$me: No matches found.\n");
         $retarr = false;
     } else {
-        $retarr{0} = $offset + strlen($matches{1});
-        $retarr{1} = $matches{1};
-        $retarr{2} = $matches{2};
-        spew("$me: '$reg' found at pos $offset matching '".$matches{2}."'\n");
+        $retarr[0] = $offset + strlen($matches[1]);
+        $retarr[1] = $matches[1];
+        $retarr[2] = $matches[2];
+        spew("$me: '$reg' found at pos $offset matching '".$matches[2]."'\n");
     }
     return $retarr;
 }
@@ -335,13 +335,13 @@ function getnxtag($body, $offset){
          */
         $matches = Array();
         preg_match('%^(\s*)(>|/>)%s', substr($body, $pos), $matches);
-        if (isset($matches{0}) && $matches{0}){
+        if (isset($matches[0]) && $matches[0]){
             /**
              * Yep. So we did.
              */
             spew("$me: Arrived at the end of the tag.\n");
-            $pos += strlen($matches{1});
-            if ($matches{2} == '/>'){
+            $pos += strlen($matches[1]);
+            if ($matches[2] == '/>'){
                 $tagtype = 3;
                 $pos++;
             }
@@ -409,7 +409,7 @@ function getnxtag($body, $offset){
             spew("$me: Additionally, end of tag found at $pos\n");
             spew("$me: Attname is '$attname'\n");
             spew("$me: Setting attvalue to 'yes'\n");
-            $attary{$attname} = '"yes"';
+            $attary[$attname] = '"yes"';
             return Array($tagname, $attary, $tagtype, $lt, $pos);
             break;
         default:
@@ -449,7 +449,7 @@ function getnxtag($body, $offset){
                     list($pos, $attval, $match) = $regary;
                     spew("$me: Attvalue is '$attval'\n");
                     $pos++;
-                    $attary{$attname} = '\'' . $attval . '\'';
+                    $attary[$attname] = '\'' . $attval . '\'';
                 } else if ($quot == '"'){
                     spew("$me: In fact, this is attribute type 2\n");
                     spew("$me: looking for closing quote\n");
@@ -462,7 +462,7 @@ function getnxtag($body, $offset){
                     list($pos, $attval, $match) = $regary;
                     spew("$me: Attvalue is \"$attval\"\n");
                     $pos++;
-                    $attary{$attname} = '"' . $attval . '"';
+                    $attary[$attname] = '"' . $attval . '"';
                 } else {
                     spew("$me: This looks like attribute type 3\n");
                     /**
@@ -482,7 +482,7 @@ function getnxtag($body, $offset){
                     spew("$me: translating '\"' into &quot;\n");
                     $attval = preg_replace('/\"/s', '&quot;', $attval);
                     spew("$me: wrapping in quotes\n");
-                    $attary{$attname} = '"' . $attval . '"';
+                    $attary[$attname] = '"' . $attval . '"';
                 }
             } else if (preg_match('|[\w/>]|', $char)) {
                 /**
@@ -490,7 +490,7 @@ function getnxtag($body, $offset){
                  */
                 spew("$me: attribute type 4 found.\n");
                 spew("$me: Setting value to 'yes'\n");
-                $attary{$attname} = '"yes"';
+                $attary[$attname] = '"yes"';
             } else {
                 /**
                  * An illegal character. Find next '>' and return.
@@ -533,7 +533,7 @@ function deent(&$attvalue, $regex, $hex=false){
                 $numval = hexdec($numval);
                 spew("$me: hex! Numval is now $numval\n");
             }
-            $repl{$matches[0][$i]} = chr($numval);
+            $repl[$matches[0][$i]] = chr($numval);
         }
         $attvalue = strtr($attvalue, $repl);
         spew("$me: attvalue after translation: $attvalue\n");
@@ -621,7 +621,7 @@ function fixatts($tagname, 
                     if (preg_match($matchattr, $attname)){
                         spew("$me: Attribute '$attname' defined as bad.\n");
                         spew("$me: Removing.\n");
-                        unset($attary{$attname});
+                        unset($attary[$attname]);
                         continue;
                     }
                 }
@@ -652,7 +652,7 @@ function fixatts($tagname, 
                         $newvalue = preg_replace($valmatch,$valrepl,$attvalue);
                         if ($newvalue != $attvalue){
                             spew("$me: attvalue is now $newvalue\n");
-                            $attary{$attname} = $newvalue;
+                            $attary[$attname] = $newvalue;
                         }
                     }
                 }
@@ -927,10 +927,10 @@ function sanitize($body, 
                     $skip_content = false;
                 } else {
                     if ($skip_content == false){
-                        if (isset($open_tags{$tagname}) && 
-                            $open_tags{$tagname} > 0){
+                        if (isset($open_tags[$tagname]) && 
+                            $open_tags[$tagname] > 0){
                             spew("$me: popping '$tagname' from open_tags\n");
-                            $open_tags{$tagname}--;
+                            $open_tags[$tagname]--;
                         } else {
                             spew("$me: '$tagname' was never opened\n");
                             spew("$me: removing\n");
@@ -972,10 +972,10 @@ function sanitize($body, 
                         } else {
                             if ($tagtype == 1){
                                 spew("$me: adding '$tagname' to open_tags\n");
-                                if (isset($open_tags{$tagname})){
-                                    $open_tags{$tagname}++;
+                                if (isset($open_tags[$tagname])){
+                                    $open_tags[$tagname]++;
                                 } else {
-                                    $open_tags{$tagname} = 1;
+                                    $open_tags[$tagname] = 1;
                                 }
                             }
                             /**
