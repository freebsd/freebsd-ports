--- setup.py.orig	2005-10-16 19:07:03.000000000 -0400
+++ setup.py	2010-01-27 22:53:23.749001522 -0500
@@ -25,7 +25,10 @@
         d = {}
         if os.path.exists(os.path.join(cfg['include_dirs'][0], 'pcap-int.h')):
             d['HAVE_PCAP_INT_H'] = 1
-        buf = open(os.path.join(cfg['include_dirs'][0], 'pcap.h')).read()
+        if os.uname()[2][0] >= '8':
+            buf = open(os.path.join(cfg['include_dirs'][1], 'pcap.h')).read()
+        else:
+            buf = open(os.path.join(cfg['include_dirs'][0], 'pcap.h')).read()
         if buf.find('pcap_file(') != -1:
             d['HAVE_PCAP_FILE'] = 1
         if buf.find('pcap_compile_nopcap(') != -1:
@@ -46,6 +49,7 @@
                 incdirs = [ os.path.join(d, sd) ]
                 if os.path.exists(os.path.join(d, sd, 'pcap.h')):
                     cfg['include_dirs'] = [ os.path.join(d, sd) ]
+                    cfg['include_dirs'].append(os.path.join(d, 'include/pcap'))
                     for sd in ('lib', ''):
                         for lib in (('pcap', 'libpcap.a'),
                                     ('pcap', 'libpcap.dylib'),
