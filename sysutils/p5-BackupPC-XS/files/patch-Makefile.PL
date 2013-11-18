--- Makefile.PL.orig	2013-05-26 11:32:01.000000000 +0400
+++ Makefile.PL	2013-09-26 09:38:14.000000000 +0400
@@ -14,10 +14,6 @@
             bpc_refCount$(OBJ_EXT)
     ];
 $object =~ s/[\n\r\s]+/ /g;
-my $ldfrom = $object;
-$ldfrom =~ s{(\w+)/}{}g;
-$ldfrom .= ' zlib/libzlib$(LIB_EXT)';
-$ldfrom .= ' md5/libmd5$(LIB_EXT)';
 
 WriteMakefile(
     NAME              => 'BackupPC::XS',
@@ -28,7 +24,7 @@
     DEFINE            => '', # e.g., '-DHAVE_SOMETHING'
     INC               => '-I.', # e.g., '-I. -I/usr/include/other'
     OBJECT            => $object,
-    LDFROM            => $ldfrom,
+    MYEXTLIB          => 'zlib/libzlib$(LIB_EXT) md5/libmd5$(LIB_EXT)',
     DIR               => ['md5', 'zlib'],
     depend            => { 'BackupPC_XS.o' => 'config.h' },
     clean             => { FILES => "config.log config.status config.h" },
@@ -38,7 +34,7 @@
         return <<'EOF';
 
 zlib/libzlib$(LIB_EXT): zlib/Makefile config.h
-	cd md5 && $(MAKE) $(PASSTHRU)
+	cd zlib && $(MAKE) $(PASSTHRU)
 
 md5/libmd5$(LIB_EXT): md5/Makefile config.h
 	cd md5 && $(MAKE) $(PASSTHRU)
