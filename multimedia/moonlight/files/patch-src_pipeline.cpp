
$FreeBSD$

--- src/pipeline.cpp.orig
+++ src/pipeline.cpp
@@ -40,6 +40,23 @@
 #include "deployment.h"
 #include "timesource.h"
 
+#ifdef __FreeBSD__
+int
+sigisemptyset(sigset_t *set)
+{
+	sigset_t empty;
+	int ret = sigemptyset (&empty);
+	if (ret == 0) {
+		if (0 == memcmp (&empty, set, sizeof (sigset_t)))
+			ret = 1;
+		else
+			ret = 0;
+	}
+
+	return ret;
+}
+#endif
+
 /*
  * Media
  */
@@ -2260,7 +2277,7 @@
 	}
 	pthread_mutex_unlock (&mutex);
 	
-	LOG_PIPELINE ("MediaThreadPool::WorkerLoop () %u: Started thread with index %i.\n", (int) pthread_self (), self_index);
+	LOG_PIPELINE ("MediaThreadPool::WorkerLoop () %lu: Started thread with index %i.\n", (long) pthread_self (), self_index);
 	
 	g_return_val_if_fail (self_index >= 0, NULL);
 	
@@ -2316,11 +2333,11 @@
 		
 		media->SetCurrentDeployment (true, true);
 
-		LOG_FRAMEREADERLOOP ("MediaThreadLoop::WorkerLoop () %u: got %s %p for media %p on deployment %p, there are %d nodes left.\n", (int) pthread_self (), node->closure->GetDescription (), node, media, media->GetDeployment (), queue ? queue->Length () : -1);
+		LOG_FRAMEREADERLOOP ("MediaThreadLoop::WorkerLoop () %lu: got %s %p for media %p on deployment %p, there are %d nodes left.\n", (long) pthread_self (), node->closure->GetDescription (), node, media, media->GetDeployment (), queue ? queue->Length () : -1);
 		
 		node->closure->Call ();
 		
-		LOG_FRAMEREADERLOOP ("MediaThreadLoop::WorkerLoop () %u: processed node %p\n", (int) pthread_self (), node);
+		LOG_FRAMEREADERLOOP ("MediaThreadLoop::WorkerLoop () %lu: processed node %p\n", (long) pthread_self (), node);
 		
 		delete node;
 	}
@@ -2333,7 +2350,7 @@
 		pthread_cond_signal (&completed_condition);
 	pthread_mutex_unlock (&mutex);
 	
-	LOG_PIPELINE ("MediaThreadPool::WorkerLoop () %u: Exited (index: %i).\n", (int) pthread_self (), self_index);
+	LOG_PIPELINE ("MediaThreadPool::WorkerLoop () %lu: Exited (index: %i).\n", (long) pthread_self (), self_index);
 	
 	return NULL;
 }
