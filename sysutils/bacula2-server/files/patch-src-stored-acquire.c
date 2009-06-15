Index: src/stored/acquire.c
===================================================================
--- src/stored/acquire.c	(revision 8426)
+++ src/stored/acquire.c	(working copy)
@@ -1,7 +1,7 @@
 /*
    Bacula® - The Network Backup Solution
 
-   Copyright (C) 2002-2008 Free Software Foundation Europe e.V.
+   Copyright (C) 2002-2009 Free Software Foundation Europe e.V.
 
    The main author of Bacula is Kern Sibbald, with contributions from
    many others, a complete list can be found in the file AUTHORS.
@@ -647,8 +647,8 @@
 
    /* Detach this dcr only if attached */
    if (dcr->attached_to_dev && dev) {
+      dev->dlock();
       dcr->unreserve_device();
-      dev->dlock();
       dcr->dev->attached_dcrs->remove(dcr);  /* detach dcr from device */
       dcr->attached_to_dev = false;
 //    remove_dcr_from_dcrs(dcr);      /* remove dcr from jcr list */
