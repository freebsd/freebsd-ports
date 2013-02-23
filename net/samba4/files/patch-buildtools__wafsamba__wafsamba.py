--- ./buildtools/wafsamba/wafsamba.py.orig	2013-02-05 12:25:25.000000000 +0000
+++ ./buildtools/wafsamba/wafsamba.py	2013-02-06 02:15:45.969880485 +0000
@@ -790,7 +790,7 @@
     '''build and install manual pages'''
     bld.env.SAMBA_EXPAND_XSL = bld.srcnode.abspath() + '/docs-xml/xslt/expand-sambadoc.xsl'
     bld.env.SAMBA_MAN_XSL = bld.srcnode.abspath() + '/docs-xml/xslt/man.xsl'
-    bld.env.SAMBA_CATALOGS = 'file:///etc/xml/catalog file:///usr/local/share/xml/catalog file://' + bld.srcnode.abspath() + '/bin/default/docs-xml/build/catalog.xml'
+    bld.env.SAMBA_CATALOGS = 'file://%%LOCALBASE%%/share/xml/catalog file://' + bld.srcnode.abspath() + '/bin/default/docs-xml/build/catalog.xml'
 
     for m in manpages.split():
         source = m + '.xml'
