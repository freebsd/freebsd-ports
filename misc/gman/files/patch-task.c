--- task.c.bak	2007-08-12 18:47:02.000000000 +0200
+++ task.c	2007-08-12 18:47:32.000000000 +0200
@@ -112,12 +112,12 @@
 	do {
 		have_task = 0;
 		task = (Task *)NULL;
-		int flag = 0;
+		intptr_t flag = 0;
 		pthread_mutex_lock(&task_group->lock);
 		j = task_group->tasks->get_size();
 		for(i = 0; i<j && !have_task ;i++) {
 			if((task = (Task*)task_group->tasks->get_item(i))->signals[0]->get_size()) {
-				flag = ((int)task->signals[0]->get_item(0) & ~1) | (task->state & 1);
+				flag = ((intptr_t)task->signals[0]->get_item(0) & ~1) | (task->state & 1);
 				task->signals[0]->delete_item(0);
 				have_task++;
 			}
@@ -126,7 +126,7 @@
 				have_task++;
 			}
 			else if (task->signals[1]->get_size()) {
-				flag = ((int)task->signals[1]->get_item(1) & ~1);
+				flag = ((intptr_t)task->signals[1]->get_item(1) & ~1);
 				task->signals[1]->delete_item(0);
 				have_task++;
 			}
