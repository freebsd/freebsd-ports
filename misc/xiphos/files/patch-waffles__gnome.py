--- ./waffles/gnome.py.orig	2010-10-15 17:32:41.000000000 -0400
+++ ./waffles/gnome.py	2010-10-21 11:00:42.000000000 -0400
@@ -216,7 +216,7 @@
 	xsltproc2po = conf.find_program('xsltproc', var='XSLTPROC2PO')
 	conf.env['XML2POFLAGS'] = '-e -p'
 	conf.env['SCROLLKEEPER_DATADIR'] = Utils.cmd_output("scrollkeeper-config --pkgdatadir", silent=1).strip()
-	conf.env['DB2OMF'] = Utils.cmd_output("/usr/bin/pkg-config --variable db2omf gnome-doc-utils", silent=1).strip()
+	conf.env['DB2OMF'] = Utils.cmd_output("pkg-config --variable db2omf gnome-doc-utils", silent=1).strip()
 
 def set_options(opt):
 	opt.add_option('--want-rpath', type='int', default=1, dest='want_rpath', help='set rpath to 1 or 0 [Default 1]')
