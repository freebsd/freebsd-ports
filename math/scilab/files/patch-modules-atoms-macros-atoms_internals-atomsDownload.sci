--- modules/atoms/macros/atoms_internals/atomsDownload.sci.orig	2010-12-16 23:27:03.000000000 -0800
+++ modules/atoms/macros/atoms_internals/atomsDownload.sci	2010-12-16 23:41:40.000000000 -0800
@@ -71,6 +71,7 @@
     CURL         = %F;
     WGET         = %F;
     HTTPDOWNLOAD = %F;
+    FETCH        = %F;
 
     // Maybe the detection has already been done
 
@@ -83,10 +84,16 @@
     elseif atomsGetConfig("downloadTool") == "httpdownload" & getos() == 'Windows' then
         HTTPDOWNLOAD=%T;
 
+    elseif atomsGetConfig("downloadTool") == "fetch" then
+        FETCH=%T;
+
     else
 
         // Default values according to platform
-        if LINUX | SOLARIS | BSD then
+        if BSD then
+            FETCH = %T;
+
+        elseif LINUX | SOLARIS then
 
             // Need to detect under Linux platforms
             [rep,stat,err] = unix_g("wget --version");
@@ -125,9 +132,12 @@
         if CURL then
             // Curl
             timeout_arg = " --connect-timeout ";
-        else
+        elseif WGET then
             // wget
             timeout_arg = " --timeout=";
+        else
+            // fetch
+            timeout_arg = " -T ";
         end
 
         timeout = string(strtod(atomsGetConfig("downloadTimeout")));
@@ -141,6 +151,9 @@
         timeout_arg = timeout_arg + " ";
 
         // Proxy configuration
+        //
+        // fetch should set environment variables for proxy - see fetch(3)
+        //
         if (atomsGetConfig("useProxy") == "True") & (atomsGetConfig("proxyHost") <> "") then
 
             // Host
@@ -155,7 +168,7 @@
             if CURL then
                 // Curl
                 proxy_host_arg = " --proxy "+ proxy_host;
-            else
+            elseif WGET then
                 // wget
                 proxy_host_arg = " http_proxy="""+proxy_host+""" ";
             end
@@ -165,7 +178,7 @@
                 if CURL then
                     // Curl
                     proxy_user_arg = " --proxy-user "+atomsGetConfig("proxyUser")+":"+atomsGetConfig("proxyPassword");
-                else
+                elseif WGET then
                     // wget
                     proxy_user_arg = " --proxy-user="""+atomsGetConfig("proxyUser")+""" --proxy-password="""+atomsGetConfig("proxyPassword")+"""";
                 end
@@ -179,9 +192,12 @@
         elseif CURL then
             // curl
             download_cmd = "curl "+proxy_host_arg+proxy_user_arg+timeout_arg+" -s "+url_in + " -o " + file_out;
-        else
+        elseif WGET
             // wget
             download_cmd = proxy_host_arg+"wget"+proxy_user_arg+timeout_arg+" "+url_in + " -O " + file_out;
+        else
+            // fetch
+            download_cmd = "fetch " + timeout_arg + "-o " + file_out + " " + url_in;
         end
 
         [rep,stat,err] = unix_g(download_cmd);
