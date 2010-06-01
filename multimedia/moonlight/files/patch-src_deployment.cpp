
$FreeBSD$

--- src/deployment.cpp.orig
+++ src/deployment.cpp
@@ -237,8 +237,8 @@
 		}			
 		
 		if (mismatch) {
-			LOG_DEPLOYMENT ("Deployment::GetCurrent (): Domain mismatch, thread %u, (tls) deployment: %p, deployment->domain: %p, (mono_domain_get) current_domain: %p, root_domain: %p, hash deployment: %p\n",
-				(int) pthread_self (), deployment, deployment->domain, current_domain, root_domain, g_hash_table_lookup (current_hash, current_domain));
+			LOG_DEPLOYMENT ("Deployment::GetCurrent (): Domain mismatch, thread %li, (tls) deployment: %p, deployment->domain: %p, (mono_domain_get) current_domain: %p, root_domain: %p, hash deployment: %p\n",
+			(long)	pthread_self (), deployment, deployment->domain, current_domain, root_domain, g_hash_table_lookup (current_hash, current_domain));
 			pthread_mutex_lock (&hash_mutex);
 			deployment = (Deployment *) g_hash_table_lookup (current_hash, current_domain);
 			pthread_mutex_unlock (&hash_mutex);
@@ -270,9 +270,9 @@
 {
 #if DEBUG
 	if (deployment && mono_domain_get () != deployment->domain) {
-		LOG_DEPLOYMENT ("Deployment::SetCurrent (%p), thread: %i domain mismatch, is: %p\n", deployment, (int) pthread_self (), mono_domain_get ());
+		LOG_DEPLOYMENT ("Deployment::SetCurrent (%p), thread: %li domain mismatch, is: %p\n", deployment, (long) pthread_self (), mono_domain_get ());
 	} else if (pthread_getspecific (tls_key) != deployment) {
-		LOG_DEPLOYMENT ("Deployment::SetCurrent (%p), thread: %i deployment mismatch, is: %p\n", deployment, (int) pthread_self (), pthread_getspecific (tls_key));
+		LOG_DEPLOYMENT ("Deployment::SetCurrent (%p), thread: %li deployment mismatch, is: %p\n", deployment, (long) pthread_self (), pthread_getspecific (tls_key));
 	}
 #endif
 	
