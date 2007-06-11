--- lib/jpgraph/src/jpgraph.php-orig	Mon Apr 30 08:34:06 2007
+++ lib/jpgraph/src/jpgraph.php	Mon Apr 30 21:48:45 2007
@@ -56,7 +56,7 @@
 	  DEFINE('TTF_DIR', $sroot.'/fonts/');
         }
     } else {
-	DEFINE('TTF_DIR','/usr/X11R6/lib/X11/fonts/truetype/');
+	DEFINE('TTF_DIR','/usr/X11R6/lib/X11/fonts/webfonts/');
     }
 }
 
@@ -701,6 +701,8 @@
 //---------------
 // PUBLIC METHODS	
     function Set($aLocale) {
+	$query = "SELECT 'config_value' FROM 'config' WHERE 'config_name = host_locale'";
+	$aLocale = mysql_query ($query);
 	if ( in_array($aLocale, array_keys($this->iDayAbb)) ){ 
 	    $this->iLocale = $aLocale;
 	    return TRUE;  // already cached nothing else to do!
