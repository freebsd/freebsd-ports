--- lib/oxidized/web/webapp.rb.orig	2025-01-13 18:59:48 UTC
+++ lib/oxidized/web/webapp.rb
@@ -17,6 +17,7 @@ module Oxidized
       helpers Sinatra::UrlForHelper
       set :public_folder, proc { File.join(root, 'public') }
       set :haml, { escape_html: false }
+      set :host_authorization, { permitted_hosts: [] }
 
       get '/' do
         redirect url_for('/nodes')
