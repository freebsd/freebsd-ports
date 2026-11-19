--- tools/make_readme.py.orig	2026-09-08 14:07:06 UTC
+++ tools/make_readme.py
@@ -58,6 +58,8 @@ def create_readme():
     platform_str = 'Windows 32-bit'
   elif platform == 'win64':
     platform_str = 'Windows 64-bit'
+  elif platform == 'freebsd':
+    platform_str = 'FreeBSD 64-bit'
   elif platform == 'macosx64':
     platform_str = 'Mac OS-X 64-bit'
   elif platform == 'linux32':
@@ -67,7 +69,7 @@ def create_readme():
 
   data = data.replace('$PLATFORM$', platform_str)
 
-  write_file(os.path.join(output_dir, 'README.txt'), data.encode('utf-8'))
+  write_file(os.path.join(output_dir, 'README.txt'), data)
   if not options.quiet:
     sys.stdout.write('Creating README.TXT file.\n')
 
@@ -109,7 +111,7 @@ platform = options.platform
 
 # Test the operating system.
 platform = options.platform
-if (platform != 'linux32' and platform != 'linux64' and
+if (platform != 'linux32' and platform != 'linux64' and platform != 'freebsd' and
     platform != 'macosx64' and platform != 'win32' and platform != 'win64'):
   print('Unsupported target \"' + platform + '\"')
   sys.exit(1)
@@ -125,11 +127,11 @@ read_readme_file(os.path.join(jcef_dir, 'jcef_build', 
 read_readme_file(os.path.join(jcef_dir, 'jcef_build', 'README.txt'), args)
 
 # retrieve url and revision information for CEF
-if not git.is_checkout(jcef_dir):
-  raise Exception('Not a valid checkout: %s' % (jcef_dir))
+#if not git.is_checkout(jcef_dir):
+#  raise Exception('Not a valid checkout: %s' % (jcef_dir))
 
-jcef_commit_number = git.get_commit_number(jcef_dir)
-jcef_commit_hash = git.get_hash(jcef_dir)
+jcef_commit_number = "%%CI_NBR%%"
+jcef_commit_hash = "%%CI_HASH%%"
 jcef_url = git.get_url(jcef_dir)
 jcef_ver = '%s.%s.%s.%s+g%s' % (args['CEF_MAJOR'], args['CEF_MINOR'],
                                 args['CEF_PATCH'], jcef_commit_number,
