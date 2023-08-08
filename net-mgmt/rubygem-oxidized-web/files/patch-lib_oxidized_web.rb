--- lib/oxidized/web.rb.orig	2023-07-09 23:03:50.799687000 +0100
+++ lib/oxidized/web.rb	2023-07-09 23:04:50.410274000 +0100
@@ -3,9 +3,8 @@
 module Oxidized
   module API
     class Web
-      require 'rack/handler'
+      require 'rack/handler/puma'
       attr_reader :thread
-      Rack::Handler::WEBrick = Rack::Handler.get(:puma)
       def initialize nodes, listen
         require 'oxidized/web/webapp'
         listen, uri = listen.split '/'
@@ -26,7 +25,7 @@
 
       def run
         @thread = Thread.new do
-          Rack::Handler::Puma.run @app, @opts
+          Rack::Handler::Puma.run @app, **@opts
           exit!
         end
       end
