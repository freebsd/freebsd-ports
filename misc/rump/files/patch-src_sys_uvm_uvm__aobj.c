--- src/sys/uvm/uvm_aobj.c.orig	2017-07-25 14:56:13 UTC
+++ src/sys/uvm/uvm_aobj.c
@@ -883,7 +883,7 @@ uao_get(struct uvm_object *uobj, voff_t 
 				    (flags & PGO_ALLPAGES) != 0)
 					/* need to do a wait or I/O! */
 					done = false;
-					continue;
+				continue;
 			}
 
 			/*
