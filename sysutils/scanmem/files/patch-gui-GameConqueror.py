--- gui/GameConqueror.py.orig	2011-12-02 14:22:35 UTC
+++ gui/GameConqueror.py
@@ -749,7 +749,7 @@ class GameConqueror():
         self.cheatlist_liststore.prepend(['=', False, description, addr, vt, value, True])
 
     def get_process_list(self):
-        return [map(str.strip, e.strip().split(' ',2)) for e in os.popen('ps -wweo pid=,user=,command= --sort=-pid').readlines()]
+        return [map(str.strip, e.strip().split(' ',2)) for e in reversed(os.popen('ps -axww -o pid= -o user= -o command=').readlines())]
 
     def select_process(self, pid, process_name):
         # ask backend for attaching the target process
@@ -778,7 +778,7 @@ class GameConqueror():
             self.cheatlist_liststore[i][1] = False
 
     def read_maps(self):
-        lines = open('/proc/%d/maps' % (self.pid,)).readlines()
+        lines = open('/compat/linux/proc/%d/maps' % (self.pid,)).readlines()
         self.maps = []
         for l in lines:
             item = {}
@@ -980,7 +980,9 @@ class GameConqueror():
         gtk.main_quit()
 
     def main(self):
+        gtk.threads_enter()
         gtk.main()
+        gtk.threads_leave()
 
     def check_backend_version(self):
         if self.backend.version != VERSION:
