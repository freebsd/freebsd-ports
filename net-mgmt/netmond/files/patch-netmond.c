--- netmond.c.orig	Tue Jul 20 17:57:19 2004
+++ netmond.c	Thu Dec 28 13:31:06 2006
@@ -62,6 +62,8 @@
 pid_t mypid;			/* my self PID */
 int syslog_initialized;		/* syslog ready to use */
 int syslog_facility;		/* current syslog facility */
+int compatibility_flag = 1;	/* version backward compatibility flag.
+                                   default - work like previous version  */
 
 #ifdef	HAVE_PTHREAD
 pthread_t main_thr;
@@ -79,7 +81,6 @@
 static int reconfig_pending;
 static int watchdog_timeout;
 static int watchdog_pending;
-
 static struct sighandler_ent {
 	int sig;
 	int flags;
@@ -254,8 +255,7 @@
 	/*
 	 * Make pid file.
 	 */
-	(void)strcpy(buf, program_name);
-	(void)strcat(buf, ".pid");
+	snprintf(buf, sizeof(buf), "%s/%s.pid", PIDFILE_PATH, program_name);
 	if ((fp = fopen(buf, "w")) != NULL) {
 		fprintf(fp, "%d\n", (int)mypid);
 		fclose(fp);
@@ -380,7 +380,8 @@
 #ifdef	HAVE_PTHREAD
 					reconfig_pending = 0;
 #else
-					reconfig_pending = -1;
+				//	reconfig_pending = -1;
+					reconfig_pending = 0;
 #endif
 				}
 			}
@@ -626,73 +627,159 @@
 	TIMEVAL tv;
 	VARIABLE *var;
 	OBJECT *service;
+	INTERFACE *interface;
+	BGP_AS	*bgp;
+	BGP_PEER *bgp_peer;
+	ENV_MON	*env;
+	ENV_GAUGE *gauge;
+	char *buf;
+	ssize_t buf_len; 
 
 	/* current timestamp */
 	gettimeofday(&tv, NULL);
-
 	/* save method diagnostic */
-	if (method && diag && (var = get_var(object->var_list, method->name)) != NULL)
-		str2var(var, diag);
-
-	if (!method || !ok) {
-		/*
-		 * Method list aborted or Start Trap received.
-		 */
-
-		/* update object operational status */
-		object->prev_state = object->state;
+	if (method && diag && (var = get_var(object->var_list, method->name)) != NULL) {
+	    str2var(var, diag);
+	    /* save method return value */
+	    buf_len = strlen(method->name)+4;
+	    buf = malloc(buf_len);
+	    if ( buf ) {
+		snprintf(buf,buf_len,"%s.ok",method->name);	    
+		if ((var = get_var(object->var_list, buf)) != NULL)
+		    set_var(var, INTEGER, &ok, sizeof(ok));
+		free(buf);    
+	    } else {
+		report(LOG_ERR, "method_finished(%s!):.ok malloc: %m", object->name,method->name);			
+	    }
+	}
+	if ( compatibility_flag ) {
+	    if (!method || !ok) {
 		object->state = STATE_DOWN;
-
 		if (object->state != object->prev_state)
 			object->last_change = tv;
-
 #ifdef	DEBUG
 		if (object->prev_state != STATE_DOWN)
 			dprintf(("object \"%s\" change state to DOWN\n", object->name));
 #endif
-
 		/* stop anything here */
 		object_stop(object);
-
 		for (service = object->service; service; service = service->next)
 			object_stop(service);
 
 		set_none_state(object);
-
 		save_object_state(object);
-
 		/* stop data saving on the object */
 		remove_event(save_object_data, object);
-
 		/* keep touching the object if required */
 		if (object->polling > 0) {
 			tv.tv_sec += object->polling / 2;
 			add_event(&tv, start_method_list, object);
 		}
 		return;
-	}
-
-	if (method->next) {
-		/*
-		 * Advance to next object method.
-		 */
-
+	    }	
+	    if (method->next) {
+		method = method->next;
+		(*method->start)(method);
+	    	return;
+	    }
+    	    object->prev_reply = object->last_reply;
+	    object->last_reply = tv; /* last reply timestamp */
+    	
+	    /* update object operational status */
+	    object->prev_state = object->state;
+	    object->state = STATE_UP;	    
+
+	} else {
+	    if (!method || !ok) {
+		object->mths_fail++;
+	    }  else {
+	    	object->mths_ok++;
+	    }
+	    if (method && method->next) {
+		/*  Advance to next object method.  */		 
 		method = method->next;
 		(*method->start)(method);
 		return;
-	}
+	    }
+	    /* Method list done. */
+	    object->prev_reply = object->last_reply;
+	    object->last_reply = tv; /* last reply timestamp */
+	
+	    /* update object operational status */
+	    object->prev_state = object->state;
+	    if ( object->mths_ok == 0 ) {
+		object->state = STATE_DOWN;
 
-	/*
-	 * Method list done.
-	 */
+		if (object->state != object->prev_state)
+			object->last_change = tv;
+#ifdef	DEBUG
+		if (object->prev_state != STATE_DOWN)
+			dprintf(("object \"%s\" change state to DOWN\n", object->name));
+#endif
+		/* stop anything here */
+		object_stop(object);
 
-	object->prev_reply = object->last_reply;
-	object->last_reply = tv; /* last reply timestamp */
+		for (service = object->service; service; service = service->next)
+			object_stop(service);
 
-	/* update object operational status */
-	object->prev_state = object->state;
-	object->state = STATE_UP;
+		set_none_state(object);
+
+		save_object_state(object);
+
+		/* stop data saving on the object */
+		remove_event(save_object_data, object);
 
+		/* keep touching the object if required */
+		if (object->polling > 0) {
+			tv.tv_sec += object->polling / 2;
+			add_event(&tv, start_method_list, object);
+		}
+		return;
+	    } else {
+		if ( object->mths_fail ) {
+		    object->state = STATE_DEGRADED;
+		} else {
+		    object->state = STATE_UP;
+		    for (service = object->service; service; service = service->next) {		
+			if (!service->ignore_state && service->state != STATE_UP) {
+			    object->state = STATE_WARNING;		
+			    break;
+			}
+		    }
+		    for (interface = object->interface; interface; interface = interface->next) {
+			if (!interface->ignore_state && interface->state != STATE_UP) {
+			    object->state = STATE_WARNING;		
+			    break;
+			}
+		    }
+		    for ( bgp = object->bgp; bgp; bgp = bgp->next) {    
+			if (bgp->ignore_state ) continue;
+			for ( bgp_peer = bgp->peer; bgp_peer; bgp_peer=bgp_peer->next) {
+			    if ( bgp_peer->state != BGP_ESTABLISHED){
+				object->state = STATE_WARNING;		
+				break;
+			    }
+			}
+			if (object->state == STATE_WARNING)
+			    break;		    
+		    }	    
+		    for (env = object->env; env; env = env->next) {
+			if (env->ignore_state ) continue;
+			for( gauge = env->gauge; gauge; gauge=gauge->next) {
+			    if (gauge->state != ENV_NORMAL && gauge->state != ENV_NOTPRESENT ) {
+				object->state = STATE_WARNING;		
+				break;
+			    }
+			}	
+			if (object->state == STATE_WARNING)
+				break;		    
+		    }	
+		}
+	    }
+	    object->mths_ok = 0;
+	    object->mths_fail = 0;
+	    object->smths_fail = 0;
+	}
 	if (object->state != object->prev_state)
 		object->last_change = tv;
 
@@ -827,10 +914,25 @@
 		/* child would be terminated by signals */
 		sigprocmask(SIG_SETMASK, NULL, &sigmask);
 		sigprocmask(SIG_UNBLOCK, &sigmask, NULL);
-
+		close(netstate_sock);
+		
 		/* make session leader to be able killpg() latter */
 		setsid();
 
+		if ( cf->chrootdir) {
+		    if ( chroot( cf->chrootdir ) < 0 ) {
+			report(LOG_ERR, "chroot %s: %s", cf->chrootdir,strerror(*(__error())) );
+			_exit(127);
+		    }
+		}
+		if ( setgid(cf->gid) < 0 ) {
+		    report(LOG_ERR, "setgid %s[%d]: %s", cf->groupname, cf->gid, strerror(*(__error())) );
+		    _exit(127);
+		}			
+		if ( (cf->uid != 0) & (setuid(cf->uid) < 0) ) {
+		    report(LOG_ERR, "setuid %s[%d]: %s", cf->username, cf->uid, strerror(*(__error())) );
+		    _exit(127);
+		}		
 		execve(file, av, environ);
 		report(LOG_ERR, "execve %s: %m", file);
 		_exit(127);
@@ -928,8 +1030,7 @@
 #endif
 	{
 		char pidfile[100];
-		(void)strcpy(pidfile, program_name);
-		(void)strcat(pidfile, ".pid");
+		snprintf(pidfile, sizeof(pidfile), "%s/%s.pid", PIDFILE_PATH, program_name);
 		(void)unlink(pidfile);
 		report(LOG_CRIT, "aborted by signal %d", sig);
 	} else	report(LOG_INFO, "interrupted by signal %d", sig);
