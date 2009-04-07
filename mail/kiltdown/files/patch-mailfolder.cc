--- kiltdown/mailfolder.cc	2001-05-13 23:25:23.000000000 -0400
+++ kiltdown/mailfolder.cc	2008-05-21 23:27:13.000000000 -0400
@@ -263,5 +263,5 @@
 
         item.boldEntry = unread;
-        item.itemData = (unsigned int)(message);
+        item.itemData = (void *)(message);
         er = populateColumnsFromInfo(&item.columns, ccolumns, columns, message);
         RETURN_ON_FAILURE(er);
@@ -354,5 +354,5 @@
         K_ASSERT((int)hdr[x].itemData >= 0 && (int)hdr[x].itemData <= MC_LAST, "Bogus MC_ Code!!!");
 
-        info[x].which = (enum MailColumn)hdr[x].itemData;
+        info[x].which = (enum MailColumn)(uintptr_t)hdr[x].itemData;
         info[x].fixed = hdr[x].type == CW_FIXED;
         info[x].width = hdr[x].width;
@@ -497,5 +497,5 @@
 {
     int fewerUnread = 0;
-    unsigned int *rg;
+    void **rg;
     ReadStatus rs;
     bool ignoreAsk = false;
@@ -530,8 +530,8 @@
      * First, try and remove them from the UI
      */
-    rg = (unsigned int *)localAlloc(count * sizeof(unsigned int));
+    rg = (void **)localAlloc(count * sizeof(void *));
     if (!rg) return E_OUTOFMEMORY;
     for (int x = 0; x < count; x++)
-        rg[x] = (unsigned int)deleteme[x];
+        rg[x] = (void *)deleteme[x];
     messageView->removeRows(count, rg);
     localFree(rg);
@@ -655,8 +655,8 @@
 ERRCODE MailFolder::enableMailListPopupItems()
 {
-    LinkList<unsigned int> selectedItemDataList;
+    LinkList<void *> selectedItemDataList;
     bool enableUnread = false;
     bool enableRead = false;
-    unsigned int ui;
+    void *ui;
     ReadStatus rs;
     ERRCODE er;
@@ -1127,6 +1127,6 @@
 )
 {
-    LinkList<unsigned int> list;
-    unsigned int a;
+    LinkList<void *> list;
+    void *a;
     ERRCODE er;
     int x;
@@ -1221,6 +1221,6 @@
 )
 {
-    LinkList<unsigned int> selectedItemDataList;
-    unsigned int itemData;
+    LinkList<void *> selectedItemDataList;
+    void * itemData;
     MailMessage *message;
     ReadStatus rs;
@@ -1354,8 +1354,8 @@
         localFree(pstr);
     }
-    messagePreview->setUndoEnabled(false);
+    //messagePreview->setUndoEnabled(false);
     messagePreview->setText(body);
     messagePreview->setCursorPosition(0, 0);
-    messagePreview->setUndoEnabled(true);
+    //messagePreview->setUndoEnabled(true);
 
     er = S_OK;
@@ -1709,6 +1709,6 @@
 )
 {
-    LinkList<unsigned int> selectedItemDataList;
-    unsigned int itemData;
+    LinkList<void *> selectedItemDataList;
+    void * itemData;
     ERRCODE er;
 
@@ -1777,5 +1777,5 @@
     KMailListItem *item;
 
-    item = messageView->nextItem((unsigned int)index);
+    item = messageView->nextItem((void *)index);
     
     return item ? (MailMessage *)item->itemData : NULL;
@@ -1802,5 +1802,5 @@
     KMailListItem *item;
 
-    item = messageView->previousItem((unsigned int)index);
+    item = messageView->previousItem((void *)index);
 
     return item ? (MailMessage *)item->itemData : NULL;
@@ -2414,5 +2414,5 @@
 {
 //    updateMessageStatus(m);
-    messageView->selectRowFromItemData((unsigned int)m);
+    messageView->selectRowFromItemData((void *)m);
 }
  
@@ -2470,5 +2470,5 @@
     for (int x = 0; x < ccolumns; x++) {
         
-        headers[x].itemData = columns[x].which;
+        headers[x].itemData = (void *)(uintptr_t)columns[x].which;
         headers[x].width = columns[x].width;
         headers[x].type = columns[x].fixed ? CW_FIXED : CW_PERCENTAGE;
@@ -2610,5 +2610,5 @@
                 break;
         }
-        item.itemData = (unsigned int)(messages[x]);
+        item.itemData = (void *)(messages[x]);
 
         er = populateColumnsFromInfo(&item.columns, ccolumns, columns, messages[x]);
@@ -2750,5 +2750,5 @@
             memset(&item, 0, sizeof(KMailListItem));
             item.boldEntry = (rsNew == MSG_UNOPENED);
-            item.itemData = (unsigned int)(message);
+            item.itemData = (void *)(message);
             er = populateColumnsFromInfo(&item.columns, ccolumns, columns, message);
             GOTO_ON_FAILURE(er, Error);
