--- lib/Publican.pm.orig	2012-08-16 13:21:51.612392924 -0400
+++ lib/Publican.pm	2012-08-16 13:32:40.089394197 -0400
@@ -117,17 +117,17 @@
     classpath => {
         descr => maketext('Path to jar files for FOP.'),
         default =>
-            '/usr/share/java/ant/ant-trax-1.7.0.jar:/usr/share/java/xmlgraphics-commons.jar:/usr/share/java/batik-all.jar:/usr/share/java/xml-commons-apis.jar:/usr/share/java/xml-commons-apis-ext.jar',
+            '%%JAVALIBDIR%%/ant-trax-1.7.0.jar:%%JAVALIBDIR%%/xmlgraphics-commons.jar:%%LOCALBASE%%/share/java/batik/lib/batik-all.jar:%%JAVALIBDIR%%/xml-apis.jar:%%JAVALIBDIR%%/xml-apis-ext.jar',
 
     },
     common_config => {
         descr   => maketext('Path to publican content.'),
-        default => '/usr/share/publican',
+        default => '%%DATADIR%%',
 
     },
     common_content => {
         descr   => maketext('Path to publican common content.'),
-        default => '/usr/share/publican/Common_Content',
+        default => '%%DATADIR%%/Common_Content',
 
     },
     condition => {
