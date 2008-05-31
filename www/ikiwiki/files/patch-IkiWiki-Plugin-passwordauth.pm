--- IkiWiki/Plugin/passwordauth.pm.orig	2008-05-06 20:14:05.000000000 +0200
+++ IkiWiki/Plugin/passwordauth.pm	2008-05-31 10:50:03.000000000 +0200
@@ -76,6 +76,7 @@ sub formbuilder_setup (@) { #{{{
 					name => "password",
 					validate => sub {
 						length $form->field("name") &&
+						length $_[0] &&
 						shift eq IkiWiki::userinfo_get($form->field("name"), 'password');
 					},
 				);
