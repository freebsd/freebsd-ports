--- ./pim/pim_mrt_task.cc.orig	2011-09-20 00:33:28.000000000 +0000
+++ ./pim/pim_mrt_task.cc	2014-02-26 21:17:13.000000000 +0000
@@ -166,7 +166,8 @@
     //
     list<PimMreTask *>::reverse_iterator iter;
     iter = pim_mre_task_list().rbegin();
-    if (iter != pim_mre_task_list().rend()) {
+//  if (iter != pim_mre_task_list().rend()) {
+    if (pim_mre_task_list().end() != pim_mre_task_list().begin()) {
 	pim_mre_task = *iter;
 	if (pim_mre_task->input_state()
 	    == PimMreTrackState::INPUT_STATE_IN_REMOVE_MISC) {
@@ -1159,7 +1160,8 @@
     //
     list<PimMreTask *>::reverse_iterator iter;
     iter = pim_mre_task_list().rbegin();
-    if (iter != pim_mre_task_list().rend()) {
+//  if (iter != pim_mre_task_list().rend()) {
+    if (pim_mre_task_list().end() != pim_mre_task_list().begin()) {
 	pim_mre_task = *iter;
 	if (pim_mre_task->input_state() == input_state) {
 	    pim_mre_task->add_pim_mre(pim_mre);
@@ -1224,7 +1226,8 @@
     //
     list<PimMreTask *>::reverse_iterator iter;
     iter = pim_mre_task_list().rbegin();
-    if (iter != pim_mre_task_list().rend()) {
+//  if (iter != pim_mre_task_list().rend()) {
+    if (pim_mre_task_list().end() != pim_mre_task_list().begin()) {
 	pim_mre_task = *iter;
 	if (pim_mre_task->input_state() == input_state) {
 	    pim_mre_task->add_pim_mre(pim_mre);		// XXX
@@ -1266,7 +1269,8 @@
     //
     list<PimMreTask *>::reverse_iterator iter;
     iter = pim_mre_task_list().rbegin();
-    if (iter != pim_mre_task_list().rend()) {
+//  if (iter != pim_mre_task_list().rend()) {
+    if (pim_mre_task_list().end() != pim_mre_task_list().begin()) {
 	pim_mre_task = *iter;
 	if (pim_mre_task->input_state()
 	    == PimMreTrackState::INPUT_STATE_IN_REMOVE_PIM_MFC) {
