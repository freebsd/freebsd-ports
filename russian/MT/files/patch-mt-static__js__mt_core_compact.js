--- mt-static/js/mt_core_compact.js.orig	2013-12-02 02:40:32.000000000 +0900
+++ mt-static/js/mt_core_compact.js	2014-04-16 15:21:04.000000000 +0900
@@ -1,4 +1,4 @@
-/* Movable Type (r) Open Source (C) 2001-2013 Six Apart, Ltd.
+/* Movable Type (r) Open Source (C) 2001-2014 Six Apart, Ltd.
  * This file is combined from multiple sources.  Consult the source files for their
  * respective licenses and copyrights.
  */defined=function(x){return x!==undefined;};exists=function(x){return(x===undefined||x===null)?false:true;};truth=function(x){return(x&&x!="0")?true:false;};finite=function(x){return isFinite(x)?x:0;};finiteInt=function(x,b){return finite(parseInt(x,b));};finiteFloat=function(x){return finite(parseFloat(x));};max=function(){var a=arguments;var n=a[0];for(var i=1;i<a.length;i++)
