--- ./Makefile.PL.orig	2010-04-28 22:04:40.000000000 +0000
+++ ./Makefile.PL	2011-07-09 03:37:35.000000000 +0000
@@ -87,14 +67,7 @@
      DEST_VMWARE_APPS => (
        $Config{perlpath} eq '/usr/bin/perl' ? 
          '/usr/lib/vmware-viperl/apps' :
-         '$(INSTALLSITESCRIPT)/apps'
-     ),
-     # vmware docs
-     INST_VMWARE_DOC => 'doc',
-     DEST_VMWARE_DOC => (
-       $Config{perlpath} eq '/usr/bin/perl' ? 
-         '/usr/share/doc/vmware-viperl/doc' :
-         '$(SITEPREFIX)/doc'
+         '%%EXAMPLESDIR%%'
      ),
    },
 );
