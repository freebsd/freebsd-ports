--- make/configure.py.orig	2019-11-09 20:44:32 UTC
+++ make/configure.py
@@ -1413,7 +1413,7 @@ def createCLI( cross = None ):
     grp.add_argument( '--enable-nvenc', dest="enable_nvenc", default=IfHost( True, '*-*-linux*', '*-*-mingw*', none=False).value, action='store_true', help=(( 'enable %s' %h ) if h != argparse.SUPPRESS else h) )
     grp.add_argument( '--disable-nvenc', dest="enable_nvenc", action='store_false', help=(( 'disable %s' %h ) if h != argparse.SUPPRESS else h) )
 
-    h = IfHost( 'Intel QSV video encoder/decoder', '*-*-linux*', '*-*-mingw*', none=argparse.SUPPRESS).value
+    h = IfHost( 'Intel QSV video encoder/decoder', '*-*-linux*', '*-*-freebsd*', '*-*-mingw*', none=argparse.SUPPRESS).value
     grp.add_argument( '--enable-qsv', dest="enable_qsv", default=IfHost(True, "*-*-mingw*", none=False).value, action='store_true', help=(( 'enable %s' %h ) if h != argparse.SUPPRESS else h) )
     grp.add_argument( '--disable-qsv', dest="enable_qsv", action='store_false', help=(( 'disable %s' %h ) if h != argparse.SUPPRESS else h) )
 
@@ -1684,7 +1684,7 @@ try:
                                         none=False).value
                                  and options.enable_x265)
     # Disable QSV on unsupported platforms
-    options.enable_qsv        = IfHost(options.enable_qsv, '*-*-linux*',
+    options.enable_qsv        = IfHost(options.enable_qsv, '*-*-linux*', '*-*-freebsd*',
                                        '*-*-mingw*', none=False).value
     # Disable VCE on unsupported platforms
     options.enable_vce        = IfHost(options.enable_vce, '*-*-linux*', '*-*-mingw*',
@@ -2124,7 +2124,7 @@ int main()
     stdout.write( 'Enable NVENC:       %s' % options.enable_nvenc )
     stdout.write( ' (%s)\n' % note_unsupported ) if not (host_tuple.system == 'linux' or host_tuple.system == 'mingw') else stdout.write( '\n' )
     stdout.write( 'Enable QSV:         %s' % options.enable_qsv )
-    stdout.write( ' (%s)\n' % note_unsupported ) if not (host_tuple.system == 'linux' or host_tuple.system == 'mingw') else stdout.write( '\n' )
+    stdout.write( ' (%s)\n' % note_unsupported ) if not (host_tuple.system == 'linux' or host_tuple.system == 'freebsd' or host_tuple.system == 'mingw') else stdout.write( '\n' )
     stdout.write( 'Enable VCE:         %s' % options.enable_vce )
     stdout.write( ' (%s)\n' % note_unsupported ) if not (host_tuple.system == 'linux' or host_tuple.system == 'mingw') else stdout.write( '\n' )
 
