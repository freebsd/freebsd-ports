--- lib/oxidized/web.rb.orig	2022-04-22 14:40:24 UTC
+++ lib/oxidized/web.rb
@@ -26,7 +26,7 @@ module Oxidized
 
       def run
         @thread = Thread.new do
-          Rack::Handler::Puma.run @app, @opts
+          Rack::Handler::Puma.run @app, **@opts
           exit!
         end
       end
