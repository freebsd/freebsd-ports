--- node_build/FindPython.js.orig	2020-10-05 21:46:19 UTC
+++ node_build/FindPython.js
@@ -23,7 +23,7 @@ var Fs = require('fs');
 // de-prioritize because the testing script accepts ANY python3 version
 // (as of this writing, we don't know what python3 versions actually work)
 // whereas we know that python2.7 is the only working python2 version.
-var PYTHONS = ["python3.7", "python3", "python2.7", "python2", "python"];
+var PYTHONS = ["python3.9", "python3.8", "python3.7", "python3", "python2.7", "python2", "python"];
 
 var SCRIPT = [
     'import sys',
