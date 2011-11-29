
$FreeBSD$

--- PkgTrackInst/cmd_support.py.orig
+++ PkgTrackInst/cmd_support.py
@@ -24,7 +24,7 @@
 
 INSTHOOK_PATH = '/usr/local/lib/insthook.so'
 IGNORE_PATHS = ['/dev', '/tmp', '/var']
-MTREE_LOCAL = '/etc/mtree/BSD.local.dist'
+MTREE_LOCAL = '/usr/ports/Templates/BSD.local.dist'
 
 def errx(msg):
     echo_msg(msg, sys.stderr)
