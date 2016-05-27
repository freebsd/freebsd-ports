--- app/helpers/knowledgebase_helper.rb.orig	2013-06-25 12:40:55 UTC
+++ app/helpers/knowledgebase_helper.rb
@@ -53,7 +53,11 @@ module KnowledgebaseHelper
   def create_preview_link
     v = Redmine::VERSION.to_a
     if v[0] == 2 && v[1] <= 1
-      link_to_remote(l(:label_preview), { :url => { :controller => 'articles', :action => 'preview' }, :method => 'post', :update => 'preview', :with => "Form.serialize('articles-form')")
+      link_to_remote l(:label_preview), 
+                     { :url => { :controller => 'articles', :action => 'preview' }, 
+                       :method => 'post', 
+                       :update => 'preview', 
+                       :with => "Form.serialize('articles-form')" }
     else
       preview_link({ :controller => 'articles', :action => 'preview' }, 'articles-form')
     end
