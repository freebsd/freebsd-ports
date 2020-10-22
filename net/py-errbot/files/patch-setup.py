--- setup.py.orig	2020-10-10 16:25:15 UTC
+++ setup.py
@@ -36,7 +36,6 @@ deps = ['webtest',
         'markdown<3.0',  # rendering stuff, 3.0+ deprecates 'safe()'
         'ansi',
         'Pygments>=2.0.2',
-        'pygments-markdown-lexer>=0.1.0.dev39',  # sytax coloring to debug md
         'dulwich>=0.19.16',  # python implementation of git
         'deepmerge>=0.1.0',
         ]
