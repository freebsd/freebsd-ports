--- setup.py.orig	2012-10-08 16:34:53 UTC
+++ setup.py
@@ -19,7 +19,7 @@ else:
   sys.exit(1)
 
 # Remove the old installation
-sphinxdir = os.path.dirname(sphinx.__file__)
+sphinxdir = sys.argv[2]
 olddst = os.path.join(sphinxdir, "numfig.py")
 olddstc = os.path.join(sphinxdir, "numfig.pyc")
 sphinxextdir = os.path.join(sphinxdir, "ext")
@@ -39,7 +39,7 @@ shutil.copyfile("numfig.py", dst)
 # Compile to bytecode
 import py_compile
 print "Compiling", dst, "to bytecode."
-py_compile.compile(dst)
+py_compile.compile(dst, dstc, sys.argv[3])
 
 # Fix perms
 mode = stat.S_IRUSR | stat.S_IWUSR | stat.S_IRGRP | stat.S_IWGRP | stat.S_IROTH
