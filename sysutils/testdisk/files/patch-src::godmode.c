diff -ruw src/godmode.c src/godmode.c
--- src/godmode.c	2004-03-12 22:36:04.000000000 +0100
+++ src/godmode.c	2004-04-05 14:20:58.000000000 +0200
@@ -656,13 +656,6 @@
     }
     LBA2CHS(disk_car,deb->part->lba-1,&start);
     start.sector=1;
-    if(start.head>0)
-      start.head--;
-    else
-    {
-      start.head=disk_car->CHS.head;
-      start.cylinder--;
-    }
     if(deb->prev && CHS2LBA(disk_car,&start)<=deb->prev->part->lba+deb->prev->part->part_size-1)
     {
       LBA2CHS(disk_car,deb->part->lba-1,&start);
