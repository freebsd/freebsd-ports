--- buildtools/wafsamba/wafsamba.py.orig	2026-01-20 15:42:53 UTC
+++ buildtools/wafsamba/wafsamba.py
@@ -1199,7 +1199,7 @@ def SAMBAMANPAGES(bld, manpages, extra_source=None):
     bld.env.SAMBA_EXPAND_XSL = bld.srcnode.abspath() + '/docs-xml/xslt/expand-sambadoc.xsl'
     bld.env.SAMBA_MAN_XSL = bld.srcnode.abspath() + '/docs-xml/xslt/man.xsl'
     bld.env.SAMBA_CATALOG = bld.bldnode.abspath() + '/docs-xml/build/catalog.xml'
-    bld.env.SAMBA_CATALOGS = os.getenv('XML_CATALOG_FILES', 'file:///etc/xml/catalog file:///usr/local/share/xml/catalog') + ' file://' + bld.env.SAMBA_CATALOG
+    bld.env.SAMBA_CATALOGS = os.getenv('XML_CATALOG_FILES', 'file:///etc/xml/catalog file://%%LOCALBASE%%/share/xml/catalog') + ' file://' + bld.env.SAMBA_CATALOG
 
     for m in manpages.split():
         source = [m + '.xml']
