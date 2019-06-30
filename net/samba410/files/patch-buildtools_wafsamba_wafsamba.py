--- ./buildtools/wafsamba/wafsamba.py.orig	2015-07-21 09:47:48 UTC
+++ ./buildtools/wafsamba/wafsamba.py
@@ -892,7 +892,7 @@
     bld.env.SAMBA_EXPAND_XSL = bld.srcnode.abspath() + '/docs-xml/xslt/expand-sambadoc.xsl'
     bld.env.SAMBA_MAN_XSL = bld.srcnode.abspath() + '/docs-xml/xslt/man.xsl'
     bld.env.SAMBA_CATALOG = bld.srcnode.abspath() + '/bin/default/docs-xml/build/catalog.xml'
-    bld.env.SAMBA_CATALOGS = 'file:///etc/xml/catalog file:///usr/local/share/xml/catalog file://' + bld.env.SAMBA_CATALOG
+    bld.env.SAMBA_CATALOGS = 'file:///etc/xml/catalog file://%%LOCALBASE%%/share/xml/catalog file://' + bld.env.SAMBA_CATALOG
 
     for m in manpages.split():
         source = m + '.xml'
