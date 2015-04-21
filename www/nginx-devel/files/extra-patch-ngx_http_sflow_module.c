--- ../nginx-sflow-module-0.9.7/ngx_http_sflow_module.c.orig	2015-04-21 21:21:17.020547000 +0300
+++ ../nginx-sflow-module-0.9.7/ngx_http_sflow_module.c	2015-04-21 21:22:26.994714000 +0300
@@ -8,10 +8,6 @@
 #include <ngx_http.h>
 #include <nginx.h>
 
-#if (NGX_THREADS)
-#include <ngx_thread.h>
-#endif
-
 #include "ngx_http_sflow_api.h"
 #include "ngx_http_sflow_config.h"
 
@@ -42,18 +38,10 @@
     /* keep log ptr for callbacks */
     ngx_log_t *log;
 
-#if (NGX_THREADS)
-    ngx_mutex_t *mut;
-#define SFWB_LOCK(_s) ngx_mutex_lock((_s)->mut)
-#define SFWB_UNLOCK(_s) ngx_mutex_unlock((_s)->mut)
-#define SFWB_INC_CTR(_c) ngx_atomic_fetch_add(&(_c), 1)
-#define SFWB_COUNTDOWN(_c) (ngx_atomic_fetch_add(&(_c), -1) == 1)
-#else
 #define SFWB_LOCK(_s) /* no-op */
 #define SFWB_UNLOCK(_s) /* no-op */
 #define SFWB_INC_CTR(_c) (_c)++
 #define SFWB_COUNTDOWN(_c) (--(_c) == 0)
-#endif
 
     /* delegate acquiring the sflow config */
     SFWBConfigManager *config_manager;
@@ -411,13 +399,8 @@
 static int32_t ngx_http_sflow_add_random_skip(SFWB *sm)
 {
     ngx_atomic_t next_skip = sfl_sampler_next_skip(sm->sampler);
-#if (NGX_THREADS)
-    ngx_atomic_int_t test_skip = ngx_atomic_fetch_add(&sm->sflow_skip, next_skip);
-    return (test_skip + next_skip);
-#else
     sm->sflow_skip = next_skip;
     return next_skip;
-#endif
 }
 
 /*_________________---------------------------__________________
@@ -528,13 +511,6 @@
     /* a pool to use for the agent so we can recycle the memory easily on a config change */
     sm->masterPool = ngx_create_pool(SFWB_POOL_SIZ, cf->log);
 
-#if (NGX_THREADS)
-    /* a mutex to lock the sFlow agent when taking a sample (only needed if there
-       is more that one worker thread - right now it seems like threads are not even
-       an option in the configure script) */
-    sm->mut = ngx_mutex_init(cf->log, 0);
-#endif
-
     /* create and initialze the config_manager */
     sm->config_manager = ngx_pcalloc(cf->pool, sizeof(SFWBConfigManager));
     sfwb_config_init(sm->config_manager, cf->log);
