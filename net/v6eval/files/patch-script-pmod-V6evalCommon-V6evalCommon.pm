--- script/pmod/V6evalCommon/V6evalCommon.pm.orig	2013-06-17 00:13:33.000000000 +0900
+++ script/pmod/V6evalCommon/V6evalCommon.pm	2013-06-17 00:19:20.000000000 +0900
@@ -70,7 +70,7 @@
         $path,           # path  
     ) = @_; 
 	($SeqName,$SeqDir,$SeqSuffix) = fileparse($0,'.seq');
-	$V6EVALPREFIX= "/usr/local/v6eval";
+	$V6EVALPREFIX= "%%PREFIX%%/v6eval";
 	$V6EVALROOT  = $path            || $ENV{V6EVALROOT} || $V6EVALPREFIX;
 	$V6EVALBIN   = $ENV{V6EVALBIN}  || "$V6EVALROOT/bin/";
 	$V6EVALETC   = $ENV{V6EVALETC}  || "./:$V6EVALROOT/etc/";
