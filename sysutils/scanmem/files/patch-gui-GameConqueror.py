--- gui/GameConqueror.py.orig	2017-10-13 21:53:16 UTC
+++ gui/GameConqueror.py
@@ -909,7 +909,7 @@ class GameConqueror():
 
     def get_process_list(self):
         plist = []
-        for proc in os.popen('ps -wweo pid=,user:16=,command= --sort=-pid').readlines():
+        for proc in reversed(os.popen('ps -axww -o pid= -o user= -o command=').readlines()):
             (pid, user, pname) = [tok.strip() for tok in proc.split(None, 2)]
             plist.append((int(pid), user, pname))
         return plist
@@ -942,7 +942,7 @@ class GameConqueror():
             self.cheatlist_liststore[i][1] = False
 
     def read_maps(self):
-        lines = open('/proc/%d/maps' % (self.pid,)).readlines()
+        lines = open('/compat/linux/proc/%d/maps' % (self.pid,)).readlines()
         self.maps = []
         for l in lines:
             item = {}
@@ -1190,7 +1190,6 @@ if __name__ == '__main__':
     args = parser.parse_args()
 
     # Init application
-    GObject.threads_init()
     Gdk.threads_init()
     gc_instance = GameConqueror()
 
