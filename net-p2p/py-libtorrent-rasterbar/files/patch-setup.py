--- setup.py.orig	2018-10-06 18:51:57 UTC
+++ setup.py
@@ -131,11 +131,11 @@ else:
 	source_list = os.listdir(os.path.join(os.path.dirname(__file__), "src"))
 	source_list = [os.path.abspath(os.path.join(os.path.dirname(__file__), "src", s)) for s in source_list if s.endswith(".cpp")]
 
-	if extra_cmd:
+	if True or extra_cmd:
 		flags = flags_parser()
 		# ldflags must be parsed first to ensure the correct library search path order
-		extra_link = flags.parse(ldflags)
-		extra_compile = flags.parse(extra_cmd)
+		extra_link = flags.parse(os.environ['LDFLAGS'])
+		extra_compile = flags.parse(os.environ['CFLAGS'])
 
 		# for some reason distutils uses the CC environment variable to determine
 		# the compiler to use for C++
