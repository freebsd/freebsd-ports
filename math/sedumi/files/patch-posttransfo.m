--- posttransfo.m~	2008-10-06 10:55:23.000000000 +0900
+++ posttransfo.m	2008-10-06 11:04:36.000000000 +0900
@@ -83,7 +83,7 @@
 % Postprocess the SDP part
 % ----------------------------------------
 if pars.sdp==1 && isfield(prep,'sdp')
-    xpf(1:K.f,1)=xp(1:K.f);
+    xpf=xp(1:K.f);
     xp=xp(K.f+1:end);
     Kf=K.f;
     K.f=0;
