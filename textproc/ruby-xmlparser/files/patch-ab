--- lib/wget.rb.orig	Tue Mar 23 17:30:30 1999
+++ lib/wget.rb	Fri Aug 11 03:23:28 2000
@@ -19,17 +19,18 @@
     if url =~ /^\/|^\./ || (url !~ /^http:|^ftp:/ && FileTest.exist?(url))
       File::open(url, *rest)
     else
-      ENV['http_proxy'] = PARAM['http_proxy'] if PARAM['http_proxy']
-      ENV['ftp_proxy'] = PARAM['ftp_proxy'] if PARAM['ftp_proxy']
+      ENV['HTTP_PROXY'] = ENV['http_proxy'] = PARAM['http_proxy'] if PARAM['http_proxy']
+      ENV['FTP_PROXY'] = ENV['ftp_proxy'] = PARAM['ftp_proxy'] if PARAM['ftp_proxy']
       IO::popen(PARAM['wget'] + ' ' + PARAM['opts'] + ' ' + url)
     end
   end
   module_function :open
 end
 
-[ '/usr/local/bin/wget', '/usr/bin/wget',
-  '/usr/local/bin/lynx', '/usr/bin/lynx',
-  '/usr/local/bin/lwp-request', '/usr/bin/lwp-request' ].each do |p|
+[ '%%PREFIX%%/bin/wget',
+  '%%PREFIX%%/bin/lynx',
+  '%%PREFIX%%/bin/lwp-request',
+  '/usr/bin/fetch' ].each do |p|
   if FileTest.executable?(p)
     WGET::PARAM['wget'] = p
     case p
@@ -39,6 +40,8 @@
       WGET::PARAM['opts'] = '-source'
     when /lwp-request$/
       WGET::PARAM['opts'] = '-m GET'
+    when /fetch$/
+      WGET::PARAM['opts'] = '-o -'
     end
     break
   end
