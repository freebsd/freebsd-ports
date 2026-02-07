--- bsd-kmod/dahdi/ng_dahdi_iface.c.orig	2016-03-11 07:21:42.746379000 +0000
+++ bsd-kmod/dahdi/ng_dahdi_iface.c	2016-03-11 07:21:07.872394000 +0000
@@ -53,6 +53,10 @@
 struct ng_node *ng_name2noderef(struct ng_node *node, const char *name);
 #endif
 
+#if __FreeBSD_version >= 1100101
+#define taskqueue_enqueue_fast(queue, task)    taskqueue_enqueue(queue, task)
+#endif
+
 #define DAHDI_IFACE_HOOK_UPPER "upper"
 
 static ng_rcvmsg_t ng_dahdi_iface_rcvmsg;
