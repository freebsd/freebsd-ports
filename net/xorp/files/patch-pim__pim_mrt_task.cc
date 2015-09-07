--- pim/pim_mrt_task.cc.orig	2012-01-11 17:56:10 UTC
+++ pim/pim_mrt_task.cc
@@ -166,7 +166,8 @@ PimMrt::add_task_delete_mrib_entries(con
     //
     list<PimMreTask *>::reverse_iterator iter;
     iter = pim_mre_task_list().rbegin();
-    if (iter != pim_mre_task_list().rend()) {
+//  if (iter != pim_mre_task_list().rend()) {
+    if (pim_mre_task_list().end() != pim_mre_task_list().begin()) {
 	pim_mre_task = *iter;
 	if (pim_mre_task->input_state()
 	    == PimMreTrackState::INPUT_STATE_IN_REMOVE_MISC) {
@@ -1159,7 +1160,8 @@ PimMrt::add_task_add_pim_mre(PimMre *pim
     //
     list<PimMreTask *>::reverse_iterator iter;
     iter = pim_mre_task_list().rbegin();
-    if (iter != pim_mre_task_list().rend()) {
+//  if (iter != pim_mre_task_list().rend()) {
+    if (pim_mre_task_list().end() != pim_mre_task_list().begin()) {
 	pim_mre_task = *iter;
 	if (pim_mre_task->input_state() == input_state) {
 	    pim_mre_task->add_pim_mre(pim_mre);
@@ -1224,7 +1226,8 @@ PimMrt::add_task_delete_pim_mre(PimMre *
     //
     list<PimMreTask *>::reverse_iterator iter;
     iter = pim_mre_task_list().rbegin();
-    if (iter != pim_mre_task_list().rend()) {
+//  if (iter != pim_mre_task_list().rend()) {
+    if (pim_mre_task_list().end() != pim_mre_task_list().begin()) {
 	pim_mre_task = *iter;
 	if (pim_mre_task->input_state() == input_state) {
 	    pim_mre_task->add_pim_mre(pim_mre);		// XXX
@@ -1266,7 +1269,8 @@ PimMrt::add_task_delete_pim_mfc(PimMfc *
     //
     list<PimMreTask *>::reverse_iterator iter;
     iter = pim_mre_task_list().rbegin();
-    if (iter != pim_mre_task_list().rend()) {
+//  if (iter != pim_mre_task_list().rend()) {
+    if (pim_mre_task_list().end() != pim_mre_task_list().begin()) {
 	pim_mre_task = *iter;
 	if (pim_mre_task->input_state()
 	    == PimMreTrackState::INPUT_STATE_IN_REMOVE_PIM_MFC) {
