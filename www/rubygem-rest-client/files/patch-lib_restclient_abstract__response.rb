--- lib/restclient/abstract_response.rb.orig	2015-06-01 12:01:41 UTC
+++ lib/restclient/abstract_response.rb
@@ -1,10 +1,11 @@
 require 'cgi'
+require 'http-cookie'
 
 module RestClient
 
   module AbstractResponse
 
-    attr_reader :net_http_res, :args
+    attr_reader :net_http_res, :args, :request
 
     # HTTP status code
     def code
@@ -22,11 +23,36 @@ module RestClient
       @raw_headers ||= @net_http_res.to_hash
     end
 
+    def response_set_vars(net_http_res, args, request)
+      @net_http_res = net_http_res
+      @args = args
+      @request = request
+    end
+
     # Hash of cookies extracted from response headers
     def cookies
-      @cookies ||= (self.headers[:set_cookie] || {}).inject({}) do |out, cookie_content|
-        out.merge parse_cookie(cookie_content)
+      hash = {}
+
+      cookie_jar.cookies.each do |cookie|
+        hash[cookie.name] = cookie.value
       end
+
+      hash
+    end
+
+    # Cookie jar extracted from response headers.
+    #
+    # @return [HTTP::CookieJar]
+    #
+    def cookie_jar
+      return @cookie_jar if @cookie_jar
+
+      jar = HTTP::CookieJar.new
+      headers.fetch(:set_cookie, []).each do |cookie|
+        jar.parse(cookie, @request.url)
+      end
+
+      @cookie_jar = jar
     end
 
     # Return the default behavior corresponding to the response code:
@@ -61,25 +87,28 @@ module RestClient
 
     # Follow a redirection
     def follow_redirection request = nil, result = nil, & block
+      new_args = @args.dup
+
       url = headers[:location]
       if url !~ /^http/
-        url = URI.parse(args[:url]).merge(url).to_s
+        url = URI.parse(request.url).merge(url).to_s
       end
-      args[:url] = url
+      new_args[:url] = url
       if request
         if request.max_redirects == 0
           raise MaxRedirectsReached
         end
-        args[:password] = request.password
-        args[:user] = request.user
-        args[:headers] = request.headers
-        args[:max_redirects] = request.max_redirects - 1
-        # pass any cookie set in the result
-        if result && result['set-cookie']
-          args[:headers][:cookies] = (args[:headers][:cookies] || {}).merge(parse_cookie(result['set-cookie']))
-        end
+        new_args[:password] = request.password
+        new_args[:user] = request.user
+        new_args[:headers] = request.headers
+        new_args[:max_redirects] = request.max_redirects - 1
+
+        # TODO: figure out what to do with original :cookie, :cookies values
+        new_args[:headers]['Cookie'] = HTTP::Cookie.cookie_value(
+          cookie_jar.cookies(new_args.fetch(:url)))
       end
-      Request.execute args, &block
+
+      Request.execute(new_args, &block)
     end
 
     def AbstractResponse.beautify_headers(headers)
