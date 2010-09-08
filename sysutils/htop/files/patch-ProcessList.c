--- ProcessList.c.orig	2010-01-26 03:58:10.000000000 +0800
+++ ProcessList.c	2010-01-26 04:22:58.000000000 +0800
@@ -313,7 +313,7 @@
    unsigned int pid = p->pid;
    int index = Vector_indexOf(this->processes, p, Process_pidCompare);
    assert(index != -1);
-   Vector_remove(this->processes, index);
+   if (index >= 0) Vector_remove(this->processes, index);
    assert(Hashtable_get(this->processTable, pid) == NULL); (void)pid;
    assert(Hashtable_count(this->processTable) == Vector_count(this->processes));
 }
@@ -730,7 +730,7 @@
 
 void ProcessList_scan(ProcessList* this) {
    unsigned long long int usertime, nicetime, systemtime, systemalltime, idlealltime, idletime, totaltime;
-   unsigned long long int swapFree;
+   unsigned long long int swapFree = 0;
 
    FILE* status;
    char buffer[128];
