--- setup.py.orig	2019-05-28 18:59:20 UTC
+++ setup.py
@@ -17,7 +17,6 @@ setup(
     name='socli',
     include_package_data=True,
     packages=["socli"],
-    data_files=[('socli', ['socli/user_agents.txt'])],
     entry_points = {"console_scripts": ['socli = socli.socli:main']},
     install_requires=['BeautifulSoup4','requests','colorama','Py-stackExchange', 'urwid'],
     requires=['BeautifulSoup4','requests','colorama','PyStackExchange', 'urwid'],
