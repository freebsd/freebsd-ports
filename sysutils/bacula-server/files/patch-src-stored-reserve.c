Index: src/stored/reserve.c
===================================================================
--- src/stored/reserve.c	(revision 8426)
+++ src/stored/reserve.c	(working copy)
@@ -1,7 +1,7 @@
 /*
    Bacula® - The Network Backup Solution
 
-   Copyright (C) 2000-2008 Free Software Foundation Europe e.V.
+   Copyright (C) 2000-2009 Free Software Foundation Europe e.V.
 
    The main author of Bacula is Kern Sibbald, with contributions from
    many others, a complete list can be found in the file AUTHORS.
@@ -498,7 +498,6 @@
 void DCR::unreserve_device()
 {
    lock_volumes();
-   dev->dlock();
    if (is_reserved()) {
       clear_reserved();
       reserved_volume = false;
@@ -514,7 +513,6 @@
          volume_unused(this);
       }
    }
-   dev->dunlock();
    unlock_volumes();
 }
