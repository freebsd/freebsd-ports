--- src/interfaces.c~	Sun Jun 18 17:23:33 2006
+++ src/interfaces.c	Sat Oct 14 07:28:41 2006
@@ -271,10 +271,12 @@
 
     if (tty_tmp->debug)
         write_log(0,"\n interfaces_init finish...\n");
 
+    {
     dlist_t *p;
     for (p=interfaces->list;p; p = dlist_next(interfaces->list, p)) {
        iface_data = (struct interface_data *) dlist_data(p);
+    }
     }
     
     return 0;
