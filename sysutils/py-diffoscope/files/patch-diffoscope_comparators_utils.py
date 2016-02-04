commit 8df464ebf0db8b04d0baae6a14504f3796e355a0
Author: Jeremy Bobbio <lunar@debian.org>
Date:   Sat Jan 30 13:47:47 2016 +0000

    Also use libarchive to read metadata from ar archives

    The output is more precise and less dependent on binutils version.

    The command line `ar` tool is not used any more so remove it from the
    required tools.

--- diffoscope/comparators/utils.py.orig	2016-01-31 06:33:12 UTC
+++ diffoscope/comparators/utils.py
@@ -36,14 +36,6 @@ from diffoscope.difference import Differ
 from diffoscope import logger, tool_required, get_temporary_directory
 
 
-@tool_required('ar')
-def get_ar_content(path):
-    if path == '/dev/null':
-        return ''
-    return subprocess.check_output(
-        ['ar', 'tv', path], stderr=subprocess.STDOUT, shell=False).decode('utf-8')
-
-
 class Command(object, metaclass=ABCMeta):
     def __init__(self, path):
         self._path = path
