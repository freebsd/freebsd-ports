--- setup.py.orig	2022-01-13 02:59:07 UTC
+++ setup.py
@@ -29,7 +29,7 @@ setup(
     keywords='sphinx markdown tables',
     packages=['sphinx_markdown_tables'],
     install_requires=['markdown>=3.0.1'],
-    data_files=[('', ['LICENSE'])],
+#    data_files=[('', ['LICENSE'])],
     project_urls={
         'Bug Reports': 'https://github.com/ryanfox/sphinx-markdown-tables/issues',
         'Say Thanks!': 'https://foxrow.com',
