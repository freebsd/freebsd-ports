--- setup.py.orig	2020-09-24 20:13:28 UTC
+++ setup.py
@@ -129,7 +129,7 @@ if 'bdist_wheel' in sys.argv and '--plat-name' not in 
         # https://www.python.org/dev/peps/pep-0425/
         sys.argv.append(name.replace('.', '_').replace('-', '_'))
 
-_UNICORN = "unicorn==1.0.2rc4"
+_UNICORN = "unicorn>=1.0.2rc4"
 
 setup(
     name='angr',
