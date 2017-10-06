--- setup.py.orig	2017-03-28 11:46:30.892170000 -0700
+++ setup.py	2017-03-28 11:50:53.885121000 -0700
@@ -45,8 +45,7 @@ is_py3 = sys.version_info[0] >= 3
 
 # We will embed this metadata into the package so it can be recalled for debugging.
 version = '0.3.2'
-git_commit, _ = Popen(['git', 'describe', '--tags'], stdout=PIPE, stderr=PIPE).communicate()
-git_commit = git_commit.strip()
+git_commit = 'v0.3.2-aac37a1'
 
 
 def get_library_config(name):
