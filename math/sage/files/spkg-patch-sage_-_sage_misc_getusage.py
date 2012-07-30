--- sage-5.0.beta13/sage/misc/getusage.py-orig	2012-04-11 00:14:47.000000000 +0000
+++ sage-5.2/sage/misc/getusage.py	2012-04-11 00:47:03.000000000 +0000
@@ -20,6 +20,8 @@
     """
     Return the 'top' or 'prstat' line that contains this running Sage
     process.
+    For FreeBSD, return the line containing this running Sage process from
+    'ps -axwww -o pid,user,vsz,rss,state,pri,nice,time,cpu,comm'.
 
     OUTPUT:
 
@@ -53,6 +55,8 @@
         cmd = 'top -l 1 |grep "^ *%s "' % pid
     elif U == 'sunos':
         cmd = '/usr/bin/prstat -n 100000 1 1  | grep "^ *%s "' % pid
+    elif U == 'freebsd':
+        cmd = 'ps -axwww -o pid,user,vsz,rss,state,pri,nice,time,cpu,comm | grep "^ *%s "' % pid
     else:
         raise NotImplementedError("top not implemented on platform %s" % U)
     
@@ -83,6 +87,9 @@
       usage, ``prstat`` will output the data in KB, MB or GB. In each
       case, the value returned by this function will always be in MB.
 
+    - ``FreeBSD`` - Returns float number (in megabytes) that matches
+      RSS column of ``ps -auxwww``
+
     - ``other`` - not implemented for any other operating systems
 
     EXAMPLES::
@@ -129,6 +136,9 @@
             m = float(memory_in_KB_MB_or_GB.strip("M"))
         elif memory_in_KB_MB_or_GB.endswith("G"):
             m = float(memory_in_KB_MB_or_GB.strip("G")) * 1024
+    elif U == 'freebsd':
+        memory_in_KB = top().split()[3]
+        m = float(memory_in_KB) / 1024
     else:
         raise NotImplementedError("memory usage not implemented on platform %s" % U)
     
