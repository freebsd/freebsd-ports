$FreeBSD$

Stop the port conflicting with devel/py-ll-core

--- setup.py.orig	2011-08-11 11:51:22.000000000 +0100
+++ setup.py	2014-02-19 21:45:27.310309976 +0000
@@ -241,16 +241,11 @@
 	packages=["ll", "ll.scripts", "ll.xist", "ll.xist.ns", "ll.xist.scripts", "ll.orasql", "ll.orasql.scripts"],
 	package_data={"ll.xist": ["data/js/*.js", "data/px/*.gif"]},
 	ext_modules=[
-		tools.Extension("ll._url", ["src/ll/_url.c"]),
-		tools.Extension("ll._ansistyle", ["src/ll/_ansistyle.c"]),
-		tools.Extension("ll._misc", ["src/ll/_misc.c", "src/ll/_misc_include.c"]),
-		tools.Extension("ll._xml_codec", ["src/ll/_xml_codec.c", "src/ll/_xml_codec_include.c"]),
 		tools.Extension("ll.xist.sgmlop", ["src/ll/xist/sgmlop.c"], define_macros=[("SGMLOP_UNICODE_SUPPORT", None)]),
 	],
 	entry_points=dict(
 		console_scripts=[
 			"uls = ll.scripts.uls:main",
-			"ucp = ll.scripts.ucp:main",
 			"ucat = ll.scripts.ucat:main",
 			"uhpp = ll.xist.scripts.uhpp:main",
 			"db2ul4 = ll.scripts.db2ul4:main",
@@ -269,7 +264,6 @@
 	),
 	scripts=[
 		"scripts/uls.py",
-		"scripts/ucp.py",
 		"scripts/ucat.py",
 		"scripts/uhpp.py",
 		"scripts/db2ul4.py",
