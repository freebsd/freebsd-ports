--- admin/SystemStats.py-orig	2010-11-03 13:54:15.000000000 -0300
+++ admin/SystemStats.py	2010-11-17 20:21:01.000000000 -0300
@@ -42,6 +42,9 @@
             _stats = System_stats__Linux()
         elif sys.platform == 'darwin':
             _stats = System_stats__Darwin()
+        elif sys.platform.rstrip('987') == 'freebsd' :
+            _stats = System_stats__FreeBSD()
+        
 
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
+        self.cpu._user_prev = 0
+        self.cpu._sys_prev  = 0
+        self.cpu._nice_prev = 0
+        self.cpu._idle_prev = 0
+
+        # Read valid values
+        self._read_hostname()
+        self._read_cpu()
+        self._read_memory()
+        self._read_cpu_info()
+
+        self.start()
+
+    def _read_hostname (self):
+        import os
+
+	hname = os.uname()[1]
+
+	if not hname:
+          # Execute sysctl 
+          fd = subprocess.Popen ("/sbin/sysctl -n kern.hostname", shell=True, stdout = subprocess.PIPE)
+          hname = fd.stdout.readline().strip()
+
+        self.hostname=hname
+
+    def _read_cpu_info (self):
+	    
+	fd = subprocess.Popen("/sbin/sysctl hw.ncpu  hw.clockrate  kern.threads.virtual_cpu", shell=True, stdout =subprocess.PIPE)    
+        lines = fd.stdout.readlines()
+     
+
+        ncpus=0
+        vcpus=0 
+	clock=''
+
+	for line in lines:
+	    parts = line.split()
+	    if parts[0] == 'hw.ncpu:':
+		ncpus = int(parts[1])
+            elif parts[0] == 'hw.clockrate:':
+		clock = parts[1] 
+            elif parts[0] == 'kern.threads.virtual_cpu:':
+		vcpus = parts[1] 
+
+
+	# FIXME: Is this reliable?
+	self.cpu.num=str(int(vcpus)/int(ncpus))
+ 	self.cpu.cores=vcpus
+        
+	self.cpu.speed = '%s MHz' %(clock)
+
+    def _read_cpu (self):
+	fd = subprocess.Popen("/sbin/sysctl -n kern.cp_time", shell=True, stdout =subprocess.PIPE)    
+        
+	fields = fd.stdout.readline().split()
+
+        user = float(fields[0])
+        sys  = float(fields[1])
+        nice = float(fields[2])
+#	intr = float(fields[3]) # 4th is interrupts, not used
+        idle = float(fields[4])
+
+        total = ((user - self.cpu._user_prev) + (sys - self.cpu._sys_prev) + (nice - self.cpu._nice_prev) + (idle - self.cpu._idle_prev))
+        self.cpu.usage = int(100.0 * ((user + sys + nice) - (self.cpu._user_prev + self.cpu._sys_prev + self.cpu._nice_prev)) / (total + 0.001) + 0.5)
+
+        if (self.cpu.usage > 100):
+            self.cpu.usage = 100
+
+        self.cpu.idle = 100 - self.cpu.usage
+
+        self.cpu._user_prev = user
+        self.cpu._sys_prev  = sys
+        self.cpu._nice_prev = nice
+        self.cpu._idle_prev = idle
+
+    def _read_memory (self):
+
+	# What we need from sysctl:
+	#  * vm.stats.vm.v_free_count
+        #  * vm.stats.vm.v_page_count
+        #  * hw.pagesize
+
+        # physical memory free = v_free_count*page_size;
+        # physical memory size = v_page_count*page_size;
+        # physical memory used = size - free space
+
+	fd = subprocess.Popen("/sbin/sysctl vm.stats.vm.v_active_count vm.stats.vm.v_page_count hw.pagesize", shell=True, stdout =subprocess.PIPE)    
+	lines = fd.stdout.readlines()
+
+        pagesize  = 0
+        pagecount = 0
+        activecount = 0
+
+	for line in lines:
+	    parts = line.split()
+	    if   parts[0] == 'hw.pagesize:':
+               pagesize = int(parts[1])
+            elif parts[0] == 'vm.stats.vm.v_active_count:':   
+               activecount = int(parts[1])
+            elif parts[0] == 'vm.stats.vm.v_page_count:':   
+	       pagecount = int(parts[1])
+
+
+        self.mem.total = (pagesize * pagecount) / 1024
+        self.mem.free  = (pagesize * (pagecount-activecount)) / 1024
+        self.mem.used  = (pagesize * activecount) / 1024
+
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
 
@@ -305,3 +432,5 @@
         print 'free',  sys_stats.mem.free
 
         time.sleep(1)
+
+
