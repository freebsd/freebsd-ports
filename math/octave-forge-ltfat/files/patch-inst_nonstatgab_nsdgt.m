--- ../inst/nonstatgab/nsdgt.m.orig	2021-02-21 22:07:54.880669000 -0600
+++ ../inst/nonstatgab/nsdgt.m	2021-02-21 22:08:12.573573000 -0600
@@ -149,8 +149,8 @@
         col = ceil(Lg/M(ii));
         
         temp = zeros(col*M(ii),W,assert_classname(f,g{1}));
-        temp([end-floor(Lg/2)+1:end,1:ceil(Lg/2)],:) = bsxfun(@ ...
-                                                          times,f(win_range,:),g{ii}(idx));
+        temp([end-floor(Lg/2)+1:end,1:ceil(Lg/2)],:) = bsxfun(@times, ...
+                                                          f(win_range,:),g{ii}(idx));
         
         temp = reshape(temp,M(ii),col,W);
         X = squeeze(fft(sum(temp,2)));
