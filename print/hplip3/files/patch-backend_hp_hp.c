--- backend/hp/hp.c.orig	Tue May 23 15:18:48 2006
+++ backend/hp/hp.c	Tue May 23 15:19:33 2006
@@ -427,6 +427,7 @@
    int len, vstatus, cnt;
    char buf[BUFFER_SIZE+HEADER_SIZE];
    MsgAttributes ma;
+   int hd=-1, channel=-1, n, total, retry=0, size;
 
    if (argc > 1)
    {
@@ -474,8 +475,6 @@
       }
       copies = atoi(argv[4]);
    }
-
-   int hd=-1, channel=-1, n, total, retry=0, size;
 
    hplip_Init();
 
