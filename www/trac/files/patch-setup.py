--- setup.py.orig	Thu Nov  3 11:44:28 2005
+++ setup.py	Thu Nov  3 11:45:01 2005
@@ -225,7 +225,7 @@
                   (_p('share/trac/htdocs'), glob(_p('htdocs/*.*')) + [_p('htdocs/README')]),
                   (_p('share/trac/htdocs/css'), glob(_p('htdocs/css/*'))),
                   (_p('share/trac/htdocs/js'), glob(_p('htdocs/js/*'))),
-                  (_p('share/man/man1'), glob(_p('scripts/*.1'))),
+                  (_p('man/man1'), glob(_p('scripts/*.1'))),
                   (_p('share/trac/wiki-default'), glob(_p('wiki-default/[A-Z]*'))),
                   (_p('share/trac/wiki-macros'), glob(_p('wiki-macros/*.py')))],
       scripts=[_p('scripts/trac-admin'),
