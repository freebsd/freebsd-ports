--- dstumbler/main.c.orig	Tue Feb 26 01:16:07 2002
+++ dstumbler/main.c	Mon Jul 21 13:26:23 2003
@@ -177,12 +177,24 @@
 /*
  * start the input/output handling loop
  */
-#define SETMONCHAN() \
- if(monmode && chanlock && (apchange || apnew))\
- {\
-   ch = aps[(aps_new && autosel) ? aps_new : aps_cur]->chan;\
-   setdebugchan(iface, ch);\
+
+static void __inline 
+SETMONCHAN(const char *iface)
+{
+ if (monmode && chanlock && (apchange || apnew))
+ {
+   int apidx = (aps_new && autosel) ? aps_new : aps_cur;
+   /*
+    * Don't set the channel if no IBSS/ESSes have been
+    * discovered yet.
+    */
+   if (aps[apidx] != NULL) {
+     ch = aps[apidx]->chan;
+     setdebugchan(iface, ch);
+   }
  }
+}
+
 void
 start_loop(const char *iface)
 {
@@ -271,7 +283,7 @@
      */
     if(monmode && mon_next(iface) == -1)
     {
-      SETMONCHAN();
+      SETMONCHAN(iface);
       smart_redraw();
       continue;
     }
@@ -279,7 +291,7 @@
     parse_ap(iface);
     parse_node(iface);
 
-    SETMONCHAN();
+    SETMONCHAN(iface);
     smart_redraw();
 
     apchange = apnew = 0;
