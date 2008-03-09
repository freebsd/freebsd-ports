--- IkiWiki/Plugin/mdwn.pm.orig	2008-03-08 11:33:50.000000000 +0100
+++ IkiWiki/Plugin/mdwn.pm	2008-03-08 13:37:21.000000000 +0100
@@ -28,14 +28,20 @@ sub htmlize (@) { #{{{
 			$markdown_sub=\&Markdown::Markdown;
 		}
 		else {
-			eval q{use Text::Markdown};
+			eval q{use Text::Markdown 'Markdown'};
 			if (! $@) {
 				$markdown_sub=\&Text::Markdown::Markdown;
 			}
 			else {
-				do "/usr/bin/markdown" ||
-					error(sprintf(gettext("failed to load Markdown.pm perl module (%s) or /usr/bin/markdown (%s)"), $@, $!));
-				$markdown_sub=\&Markdown::Markdown;
+				eval q{use Text::Markdown 'markdown'};
+				if (! $@) {
+					$markdown_sub=\&Text::Markdown::markdown;
+				}
+				else {
+					do "/usr/bin/markdown" ||
+						error(sprintf(gettext("failed to load Markdown.pm perl module (%s) or /usr/bin/markdown (%s)"), $@, $!));
+					$markdown_sub=\&Markdown::Markdown;
+				}
 			}
 		}
 		require Encode;
