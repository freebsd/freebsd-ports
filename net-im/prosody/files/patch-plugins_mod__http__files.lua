--- plugins/mod_http_files.lua.orig	2020-01-19 15:50:32 UTC
+++ plugins/mod_http_files.lua
@@ -112,7 +112,7 @@ function serve(opts)
 		local last_modified = os_date('!%a, %d %b %Y %H:%M:%S GMT', attr.modification);
 		response_headers.last_modified = last_modified;
 
-		local etag = ('"%02x-%x-%x-%x"'):format(attr.dev or 0, attr.ino or 0, attr.size or 0, attr.modification or 0);
+		local etag = ('"%x-%x-%x"'):format(attr.change or 0, attr.size or 0, attr.modification or 0);
 		response_headers.etag = etag;
 
 		local if_none_match = request_headers.if_none_match
