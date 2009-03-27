--- mod_clamav.c.orig	2008-01-05 14:14:27.000000000 -0200
+++ mod_clamav.c	2009-03-25 15:07:37.000000000 -0300
@@ -130,7 +130,7 @@
 } cl_daemon_t;
 
 typedef struct cl_local_t {
-    struct cl_node	*engine;
+    struct cl_engine	*engine;
     time_t		lastreload;
 } cl_local_t;
 
@@ -159,7 +159,9 @@
     const char		*dbdir;		/* local: where are virus patterns */
     int			port;		/* daemon: clamd port number */
     char		*socket;	/* daemon: unix domain socket path */
-    struct cl_limits	lim;		/* clamav limits structure */
+    int			maxfiles;
+    int			maxfilesize;
+    int			maxreclevel;
     int			trickle_interval;
     int			trickle_size;
     int			sizelimit;
@@ -464,11 +466,20 @@
     unsigned int	signo = 0;
     clamav_ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, f->r, "[%d] local init",
 	(int)getpid());
+
+    /* initializa clam */
+    if (0 != (ret = cl_init(CL_INIT_DEFAULT))) {
+	ap_log_rerror(APLOG_MARK, APLOG_ERR, 0, f->r,
+	    "[%d] cannot initialize clamav: %s", (int)getpid(),
+	    cl_strerror(ret));
+	return -1;
+    }
+
     /*  make sure that rec->common->local is allocated			*/
     if (NULL == rec->common->local) {
 	rec->common->local = (cl_local_t *)apr_palloc(rec->pool,
 	    sizeof(cl_local_t));
-	rec->common->local->engine = NULL;
+	rec->common->local->engine = cl_engine_new();
 	rec->common->local->lastreload = 0;
     }
 
@@ -478,7 +489,7 @@
     }
 
     /* reload the database from the directory				*/
-    if (0 != (ret = cl_load(rec->dbdir, &rec->common->local->engine,
+    if (0 != (ret = cl_load(rec->dbdir, rec->common->local->engine,
 	&signo, CL_DB_STDOPT))) {
 	ap_log_rerror(APLOG_MARK, APLOG_ERR, 0, f->r,
 	    "[%d] cannot load clamav patterns: %s", (int)getpid(),
@@ -706,7 +717,7 @@
     case MOD_CLAMAV_LOCAL:
 	/* virus scan using local clamav library */
 	return cl_scanfile(ctx->filename, virname, (unsigned long *)len,
-	    rec->common->local->engine, &rec->lim, CL_ARCHIVE);
+	    rec->common->local->engine, CL_SCAN_ARCHIVE);
 	break;
     case MOD_CLAMAV_DAEMON:
 	/* set reasonable defaults for virname */
@@ -1752,9 +1763,14 @@
     cfg->extendedlogging = 0;
     cfg->perms = 0640;
     cfg->sizelimit = 0;
-    cfg->lim.maxfiles = 100;
-    cfg->lim.maxfilesize = 10 * 1048576;
-    cfg->lim.maxreclevel = 8;
+
+    cfg->maxfiles = 100;
+    cl_engine_set_num(cfg->common->local->engine, CL_ENGINE_MAX_FILES, &cfg->maxfiles);
+    cfg->maxfilesize = 10 * 1048576;
+    cl_engine_set_num(cfg->common->local->engine, CL_ENGINE_MAX_FILESIZE, &cfg->maxfilesize);
+    cfg->maxreclevel = 8;
+    cl_engine_set_num(cfg->common->local->engine, CL_ENGINE_MAX_RECURSION, &cfg->maxreclevel);
+
     cfg->safetypes = apr_table_make(p, 0);
     cfg->safepatterns = apr_array_make(p, 64, sizeof(clamav_safepattern));
     cfg->safeuris = apr_array_make(p, 64, sizeof(clamav_safeuri));
@@ -1800,12 +1816,12 @@
 	child->shmname = parent->shmname;
     if (child->mutexname == NULL)
 	child->mutexname = parent->mutexname;
-    if (child->lim.maxfiles == 0)
-	child->lim.maxfiles = parent->lim.maxfiles;
-    if (child->lim.maxfilesize == 0)
-	child->lim.maxfilesize = parent->lim.maxfilesize;
-    if (child->lim.maxreclevel == 0)
-	child->lim.maxreclevel = parent->lim.maxreclevel;
+    if (child->maxfiles == 0)
+	child->maxfiles = parent->maxfiles;
+    if (child->maxfilesize == 0)
+	child->maxfilesize = parent->maxfilesize;
+    if (child->maxreclevel == 0)
+	child->maxreclevel = parent->maxreclevel;
     if ((!child->tmpdir) && (parent->tmpdir))
 	child->tmpdir = (char *)apr_pstrdup(p, parent->tmpdir);
     if (apr_is_empty_table(child->safetypes))
@@ -2065,19 +2081,19 @@
     ),
     AP_INIT_TAKE1(
 	"ClamavMaxfiles", ap_set_int_slot,
-	(void *)APR_OFFSETOF(clamav_config_rec, lim.maxfiles),
+	(void *)APR_OFFSETOF(clamav_config_rec, maxfiles),
 	RSRC_CONF,
 	"Maximum number of files in an archive"
     ),
     AP_INIT_TAKE1(
 	"ClamavMaxfilesize", ap_set_int_slot,
-	(void *)APR_OFFSETOF(clamav_config_rec, lim.maxfilesize),
+	(void *)APR_OFFSETOF(clamav_config_rec, maxfilesize),
 	RSRC_CONF,
 	"Maximum archive size"
     ),
     AP_INIT_TAKE1(
 	"ClamavRecursion", ap_set_int_slot,
-	(void *)APR_OFFSETOF(clamav_config_rec, lim.maxreclevel),
+	(void *)APR_OFFSETOF(clamav_config_rec, maxreclevel),
 	RSRC_CONF,
 	"Maximum recursion depth when analyzing archives"
     ),
