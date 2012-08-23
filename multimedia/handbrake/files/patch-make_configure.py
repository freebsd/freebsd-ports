--- ./make/configure.py.orig	2011-01-03 15:32:27.000000000 -0500
+++ ./make/configure.py	2011-05-24 05:50:46.069810487 -0400
@@ -1249,7 +1249,7 @@
         xcodebuild = ToolProbe( 'XCODEBUILD.exe', 'xcodebuild', abort=False )
         lipo       = ToolProbe( 'LIPO.exe',       'lipo', abort=False )
 
-        fetch = SelectTool( 'FETCH.select', 'fetch', ['wget',wget], ['curl',curl] )
+        #fetch = SelectTool( 'FETCH.select', 'fetch', ['wget',wget], ['curl',curl] )
 
     ## run tool probes
     for tool in ToolProbe.tools:
@@ -1512,16 +1512,16 @@
         asm = ''
         if build.match( 'i?86-*' ):
             asm = 'x86'
-            doc.add( 'LIBHB.GCC.D', 'HAVE_MMX', append=True )
+            #doc.add( 'LIBHB.GCC.D', 'HAVE_MMX', append=True )
             doc.add( 'LIBHB.YASM.D', 'ARCH_X86', append=True )
             if build.match( '*-*-darwin*' ):
                 doc.add( 'LIBHB.YASM.f', 'macho32' )
             else:
                 doc.add( 'LIBHB.YASM.f', 'elf32' )
             doc.add( 'LIBHB.YASM.m', 'x86' )
-        elif build.match( 'x86_64-*' ):
+        elif build.match( 'amd64-*' ):
             asm = 'x86'
-            doc.add( 'LIBHB.GCC.D', 'HAVE_MMX ARCH_X86_64', append=True )
+            #doc.add( 'LIBHB.GCC.D', 'HAVE_MMX ARCH_X86_64', append=True )
             if build.match( '*-*-darwin*' ):
                 doc.add( 'LIBHB.YASM.D', 'ARCH_X86_64 PIC', append=True )
                 doc.add( 'LIBHB.YASM.f', 'macho64' )
