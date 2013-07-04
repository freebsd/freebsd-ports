--- ./components/doublecmd/dcosutils.pas.orig	2013-06-30 21:33:09.530448529 +0200
+++ ./components/doublecmd/dcosutils.pas	2013-06-30 21:33:24.841789000 +0200
@@ -184,11 +184,11 @@
   Windows, JwaWinNetWk;
 {$ENDIF}
 {$IF DEFINED(UNIX)}
-  {$IF DEFINED(DARWIN)}
+  {$IF DEFINED(BSD)}
     {$DEFINE FPC_USE_LIBC}
   {$ENDIF}
 uses
-  {$IF NOT DEFINED(FPC_USE_LIBC)}
+  {$IF (NOT DEFINED(FPC_USE_LIBC)) OR (DEFINED(BSD) AND NOT DEFINED(DARWIN))}
   SysCall,
   {$ENDIF}
   BaseUnix, Unix, dl, DCStrUtils;
