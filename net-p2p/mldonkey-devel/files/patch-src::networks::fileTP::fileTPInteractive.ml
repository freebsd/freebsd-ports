--- src/networks/fileTP/fileTPInteractive.ml.orig	Mon Jan 31 00:29:00 2005
+++ src/networks/fileTP/fileTPInteractive.ml	Mon Jan 31 00:32:08 2005
@@ -354,13 +354,13 @@
 
 let rec op_network_parse_url url = 
   lprintf "filetp.op_network_parse_url\n";
-  let location_regexp = "Location: \([^\n]+\)\n" in
+  let location_regexp = "Location: \\(.*\\)" in
   let real_url = get_regexp_string url (Str.regexp location_regexp) in
     lprintf "real url: %s\n" real_url;
   if (is_http_torrent url real_url) then false else    
     if (String2.check_prefix real_url "http://") then (
       lprintf "http download\n";
-      let length_regexp = "Content-Length: \([0-9]+\)\n" in
+      let length_regexp = "Content-Length: \\(.*\\)" in
  try let length = get_regexp_int url (Str.regexp length_regexp) in
    if (length > 0) then begin
      download_file real_url; true
