--- make/configure.py.orig	2018-01-13 05:30:25 UTC
+++ make/configure.py
@@ -1515,7 +1515,7 @@ try:
     class Tools:
         ar    = ToolProbe( 'AR.exe',    'ar' )
         cp    = ToolProbe( 'CP.exe',    'cp' )
-        gcc   = ToolProbe( 'GCC.gcc',   'gcc', IfHost( 'gcc-4', '*-*-cygwin*' ))
+        gcc   = ToolProbe( 'GCC.gcc',   'gcc', IfHost( os.environ['CC'], '*-*-freebsd*' ), IfHost( 'gcc-4', '*-*-cygwin*' ))
 
         if host.match( '*-*-darwin*' ):
             gmake = ToolProbe( 'GMAKE.exe', 'make', 'gmake' )
