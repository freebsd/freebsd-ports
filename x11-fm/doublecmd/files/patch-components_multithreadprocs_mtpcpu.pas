--- components/multithreadprocs/mtpcpu.pas.orig	2015-09-06 12:19:32 UTC
+++ components/multithreadprocs/mtpcpu.pas
@@ -69,15 +69,17 @@ end;
     t = sysconf(_SC_NPROC_ONLN);
   end;
 {$ELSEIF defined(freebsd) or defined(darwin)}
+type
+  PSysCtl = {$IF FPC_FULLVERSION>=30200}pcint{$ELSE}pchar{$ENDIF};
 var
   mib: array[0..1] of cint;
-  len: cint;
+  len: csize_t;
   t: cint;
 begin
   mib[0] := CTL_HW;
   mib[1] := HW_NCPU;
   len := sizeof(t);
-  fpsysctl(pchar(@mib), 2, @t, @len, Nil, 0);
+  fpsysctl(PSysCtl(@mib), 2, @t, @len, Nil, 0);
   Result:=t;
 end;
 {$ELSEIF defined(linux)}
