--- make/configure.py.orig	2017-02-25 20:56:19 UTC
+++ make/configure.py
@@ -590,6 +590,9 @@ class ArchAction( Action ):
             pass
         elif host.match( '*-*-solaris*' ):
             pass
+        elif host.match( '*-*-freebsd.*' ):
+            self.mode['i386']   = 'i386-portsbuild-freebsd%s' % (host.release)
+            self.mode['amd64'] = 'amd64-portsbuild-freebsd%s' % (host.release)
         else:
             self.msg_pass = 'WARNING'
 
@@ -1294,13 +1297,13 @@ def createCLI():
     h = IfHost( 'enable assembly code in non-contrib modules', 'NOMATCH*-*-darwin*', 'NOMATCH*-*-linux*', none=optparse.SUPPRESS_HELP ).value
     grp.add_option( '--enable-asm', default=False, action='store_true', help=h )
 
-    h = IfHost( 'disable GTK GUI', '*-*-linux*', none=optparse.SUPPRESS_HELP ).value
+    h = IfHost( 'disable GTK GUI', '*-*-linux*', '*-*-freebsd*', none=optparse.SUPPRESS_HELP ).value
     grp.add_option( '--disable-gtk', default=False, action='store_true', help=h )
-    h = IfHost( 'disable GTK GUI update checks', '*-*-linux*', none=optparse.SUPPRESS_HELP ).value
+    h = IfHost( 'disable GTK GUI update checks', '*-*-linux*', '*-*-freebsd*', none=optparse.SUPPRESS_HELP ).value
     grp.add_option( '--disable-gtk-update-checks', default=False, action='store_true', help=h )
     h = IfHost( 'enable GTK GUI (mingw)', '*-*-mingw*', none=optparse.SUPPRESS_HELP ).value
     grp.add_option( '--enable-gtk-mingw', default=False, action='store_true', help=h )
-    h = IfHost( 'disable gstreamer (live preview)', '*-*-linux*', none=optparse.SUPPRESS_HELP ).value
+    h = IfHost( 'disable gstreamer (live preview)', '*-*-linux*', '*-*-freebsd*', none=optparse.SUPPRESS_HELP ).value
     grp.add_option( '--disable-gst', default=False, action='store_true', help=h )
     h = IfHost( 'enable use of Intel Quick Sync Video hardware acceleration', '*-*-*', none=optparse.SUPPRESS_HELP ).value
     grp.add_option( '--enable-qsv', default=False, action='store_true', help=h )
@@ -1352,7 +1355,7 @@ def createCLI():
     h = IfHost( 'Build and use local pkg-config', '*-*-darwin*', none=optparse.SUPPRESS_HELP ).value
     grp.add_option( '--enable-local-pkgconfig', default=False, action='store_true', help=h )
 
-    h = IfHost( 'Build extra contribs for flatpak packaging', '*-*-linux*', none=optparse.SUPPRESS_HELP ).value
+    h = IfHost( 'Build extra contribs for flatpak packaging', '*-*-linux*', '*-*-freebsd*', none=optparse.SUPPRESS_HELP ).value
     grp.add_option( '--flatpak', default=False, action='store_true', help=h )
     cli.add_option_group( grp )
 
@@ -1517,7 +1520,7 @@ try:
     class Tools:
         ar    = ToolProbe( 'AR.exe',    'ar' )
         cp    = ToolProbe( 'CP.exe',    'cp' )
-        gcc   = ToolProbe( 'GCC.gcc',   'gcc', IfHost( 'gcc-4', '*-*-cygwin*' ))
+        gcc   = ToolProbe( 'GCC.gcc',   'gcc', IfHost( os.environ['CC'], '*-*-freebsd*' ))
 
         if host.match( '*-*-darwin*' ):
             gmake = ToolProbe( 'GMAKE.exe', 'make', 'gmake' )
@@ -1924,10 +1927,15 @@ int main()
         doc.add( 'GCC.sysroot', '' )
         doc.add( 'GCC.minver', '' )
 
+    if build.match( '*-*-freebsd*' ):
+        doc.add( 'HAS.pthread', 1 )
+
     if build.match( 'i?86-*' ):
         doc.add( 'LIBHB.GCC.D', 'ARCH_X86_32', append=True )
     elif build.match( 'x86_64-*' ):
         doc.add( 'LIBHB.GCC.D', 'ARCH_X86_64', append=True )
+    elif build.match( 'amd64-*' ):
+        doc.add( 'LIBHB.GCC.D', 'ARCH_X86_64', append=True )
 
     if options.enable_asm and ( not Tools.yasm.fail or options.enable_local_yasm ):
         asm = ''
@@ -1940,7 +1948,7 @@ int main()
             else:
                 doc.add( 'LIBHB.YASM.f', 'elf32' )
             doc.add( 'LIBHB.YASM.m', 'x86' )
-        elif build.match( 'x86_64-*' ):
+        elif build.match( 'x86_64-*' ) or build.match( 'amd64-*' ):
             asm = 'x86'
             doc.add( 'LIBHB.GCC.D', 'HAVE_MMX ARCH_X86_64', append=True )
             if build.match( '*-*-darwin*' ):
