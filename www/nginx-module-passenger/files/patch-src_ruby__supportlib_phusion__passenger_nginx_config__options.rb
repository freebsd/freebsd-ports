--- src/ruby_supportlib/phusion_passenger/nginx/config_options.rb.orig	2026-10-17 17:04:43 UTC
+++ src/ruby_supportlib/phusion_passenger/nginx/config_options.rb
@@ -212,7 +212,7 @@ NGINX_CONFIGURATION_OPTIONS = [
     name: 'passenger_disable_anonymous_telemetry',
     scope: :global,
     type: :flag,
-    default: false,
+    default: true,
     context: [ :main ],
     struct: 'NGX_HTTP_MAIN_CONF_OFFSET',
   },
