--- setup.py.orig	2025-07-22 07:20:26 UTC
+++ setup.py
@@ -9,10 +9,9 @@ _data_files = [
         ]
 
 _data_files = [
-        ('share/doc/cppman', ['README.rst', 'AUTHORS', 'COPYING', 'ChangeLog']),
         ('share/man/man1', ['misc/cppman.1']),
-        ('share/bash-completion/completions', ['misc/completions/cppman.bash']),
-        ('share/zsh/vendor-completions/', ['misc/completions/zsh/_cppman']),
+        ('etc/bash_completion.d', ['misc/completions/cppman.bash']),
+        ('share/zsh/site-functions/', ['misc/completions/zsh/_cppman']),
         ('share/fish/vendor_completions.d/', ['misc/completions/fish/cppman.fish'])
         ]
 
