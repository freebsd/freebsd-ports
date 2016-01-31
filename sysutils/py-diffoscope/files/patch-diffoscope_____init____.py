commit 8df464ebf0db8b04d0baae6a14504f3796e355a0
Author: Jeremy Bobbio <lunar@debian.org>
Date:   Sat Jan 30 13:47:47 2016 +0000

    Also use libarchive to read metadata from ar archives
    
    The output is more precise and less dependent on binutils version.
    
    The command line `ar` tool is not used any more so remove it from the
    required tools.

--- diffoscope/__init__.py.orig	2016-01-31 06:30:01 UTC
+++ diffoscope/__init__.py
@@ -39,9 +39,7 @@ OS_NAMES = { 'arch': 'Arch Linux'
            }
 
 class RequiredToolNotFound(Exception):
-    PROVIDERS = { 'ar':         { 'debian': 'binutils-multiarch',
-                                  'arch': 'binutils'}
-                , 'bzip2':      { 'debian': 'bzip2',
+    PROVIDERS = { 'bzip2':      { 'debian': 'bzip2',
                                   'arch': 'bzip2'}
                 , 'cbfstool':   {}
                 , 'cmp':        { 'debian': 'diffutils',
