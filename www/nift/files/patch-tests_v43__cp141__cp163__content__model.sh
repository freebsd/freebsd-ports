--- tests/v43_cp141_cp163_content_model.sh.orig	2026-10-20 16:01:23 UTC
+++ tests/v43_cp141_cp163_content_model.sh
@@ -56,12 +56,12 @@ EOF2
 [[ $(cd "$R" && j '(project.taxonomies.tag[1].content).size()') == '2' ]]
 [[ $(cd "$R" && j 'project.taxonomies.section[0].parent') == '"docs"' ]]
 # tracked/frontmatter type disagreement is a hard error
-sed -i 's/type: post/type: page/' "$R/content/a.md"
+sed -i.bak 's/type: post/type: page/' "$R/content/a.md"
 if (cd "$R" && "$BIN" build --all >/tmp/cm.out 2>/tmp/cm.err); then echo expected type conflict >&2; exit 1; fi
 grep -q 'tracked type conflicts' /tmp/cm.err
-sed -i 's/type: page/type: post/' "$R/content/a.md"
+sed -i.bak 's/type: page/type: post/' "$R/content/a.md"
 (cd "$R" && "$BIN" build --repair >/dev/null)
 # schema diagnostics
-sed -i 's/title: Alpha/title: 42/' "$R/content/a.md"
+sed -i.bak 's/title: Alpha/title: 42/' "$R/content/a.md"
 if (cd "$R" && "$BIN" build --all >/tmp/cm.out 2>/tmp/cm.err); then echo expected schema failure >&2; exit 1; fi
 grep -q "schema post field 'title': expected string" /tmp/cm.err
