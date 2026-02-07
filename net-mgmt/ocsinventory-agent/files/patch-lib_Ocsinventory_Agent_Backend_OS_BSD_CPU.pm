--- lib/Ocsinventory/Agent/Backend/OS/BSD/CPU.pm.orig	2024-11-12 14:35:48 UTC
+++ lib/Ocsinventory/Agent/Backend/OS/BSD/CPU.pm
@@ -64,8 +64,8 @@ sub run {
     if ($cpu->{NBSOCKET} and $cpu->{CORES} and $cpu->{THREADS} ){
         if ($cpu->{THREADS} >= $cpu->{CORES}) {
             $cpu->{THREADS}=$cpu->{THREADS}/$cpu->{CORES};
-        } elsif ($cpu->{THREADS} >= $cpu->{NBSOCKETS}) {
-            $cpu->{THREADS}=$cpu->{THREADS}/$cpu->{NBSOCKETS};
+        } elsif ($cpu->{THREADS} >= $cpu->{NBSOCKET}) {
+            $cpu->{THREADS}=$cpu->{THREADS}/$cpu->{NBSOCKET};
         }
     }
 
