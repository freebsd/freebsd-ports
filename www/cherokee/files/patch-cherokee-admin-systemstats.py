--- admin/SystemStats.py-orig	2010-11-18 07:53:18.000000000 -0300
+++ admin/SystemStats.py	2010-11-25 20:38:23.000000000 -0300
@@ -23,6 +23,7 @@
 #
 
 import os
+import popen
 import re
 import sys
 import time
@@ -42,6 +43,8 @@
             _stats = System_stats__Linux()
         elif sys.platform == 'darwin':
             _stats = System_stats__Darwin()
+        elif sys.platform.startswith ('freebsd'):
+            _stats = System_stats__FreeBSD()
 
     assert _stats, "Not implemented"
     return _stats
@@ -286,6 +289,130 @@
             time.sleep (self.CHECK_INTERVAL)
 
 
+
+# FreeBSD implementation
+class System_stats__FreeBSD (Thread, System_stats):
+    CHECK_INTERVAL = 2
+
+    def __init__ (self):
+        Thread.__init__ (self)
+        System_stats.__init__ (self)
+        
+        self.vmstat_fd = subprocess.Popen ("/usr/bin/vmstat -H -w%d" %(self.CHECK_INTERVAL),
+                                            shell=True, stdout = subprocess.PIPE, close_fds=True )
+
+	#first,second = self.vmstat_fd.stdout.readline(),self.vmstat_fd.stdout.readline()
+
+
+        # Read valid values
+        self._read_hostname()
+        self._read_cpu()
+        self._read_memory()
+        self._read_cpu_and_mem_info()
+
+        self.start()
+
+    def _read_hostname (self):
+        # First try: uname()
+	self.hostname = os.uname()[1]
+        if self.hostname:
+            return
+
+        # Second try: sysctl()
+        ret = popen.popen_sync ("/sbin/sysctl -n kern.hostname")
+        self.hostname = ret['stdout'].rstrip()
+        if self.hostname:
+            return
+
+        # Could not figure it out
+        self.hostname = "Unknown"
+
+    def _read_cpu_and_mem_info (self):
+        # Execute sysctl
+        ret = popen.popen_sync ("/sbin/sysctl hw.ncpu hw.clockrate kern.threads.virtual_cpu hw.pagesize vm.stats.vm.v_page_count")
+        lines = filter (lambda x: x, ret['stdout'].split('\n'))
+
+        # Parse output
+	
+	# cpu related
+        ncpus = 0
+        vcpus = 0
+	clock = ''
+
+        # mem related
+	psize  = 0
+	pcount = 0
+
+	for line in lines:
+	    parts = line.split()
+	    if parts[0] == 'hw.ncpu:':
+		ncpus = int(parts[1])
+            elif parts[0] == 'hw.clockrate:':
+		clock = parts[1]
+            elif parts[0] == 'kern.threads.virtual_cpu:':
+		vcpus = parts[1]
+            elif parts[0] == 'vm.stats.vm.v_page_count:':
+		pcount = int(parts[1])
+            elif parts[0] == 'hw.pagesize:':
+		psize = int(parts[1])
+
+	# Deal with cores
+        if vcpus:
+            self.cpu.num   = str (int(vcpus) / int(ncpus))
+            self.cpu.cores = vcpus
+        else:
+            self.cpu.num   = int (ncpus)
+            self.cpu.cores = int (ncpus)
+
+        # Global speed
+	self.cpu.speed = '%s MHz' %(clock)
+
+
+	# Physical mem
+	self.mem.total = (psize * pcount) / 1024 
+
+    def _read_cpu (self):
+
+	# Read a new line
+        line = self.vmstat_fd.stdout.readline().rstrip('\n')
+
+        # Skip headers
+	if len(filter (lambda x: x not in " .0123456789", line)):
+	    return
+        
+        # Parse
+	parts = filter (lambda x: x, line.split(' '))
+
+	if not len(parts) == 18:
+		return
+
+	self.cpu.idle  = int(parts[17])
+	self.cpu.usage = 100 - self.cpu.idle
+
+    def _read_memory (self):
+
+        line = self.vmstat_fd.stdout.readline().rstrip('\n')
+
+        # Skip headers
+        if len(filter (lambda x: x not in " .0123456789", line)):
+            return
+
+        # Parse
+        values = filter (lambda x: x, line.split(' '))
+
+	if not len(values)==18:
+		return 
+
+        self.mem.free  = int(values[4]) 
+        self.mem.used  = self.mem.total - self.mem.free
+
+    def run (self):
+        while True:
+            self._read_cpu()
+            self._read_memory()
+            time.sleep (self.CHECK_INTERVAL)
+
+
 if __name__ == '__main__':
     sys_stats = get_system_stats()
 
