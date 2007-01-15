--- reconfig.c.orig	Tue Aug 26 10:54:37 2003
+++ reconfig.c	Thu Dec 28 13:31:06 2006
@@ -175,6 +175,7 @@
 
 	rescan = (old->bandwidth != new->bandwidth); /* to force rescan */
 	old->bandwidth = new->bandwidth;
+	old->ignore_state = new->ignore_state;
 
 	splice_var_list(&old->var_list, &new->var_list);
 
@@ -260,6 +261,7 @@
 
 	/* setup new list of peers */
 	old->handconf = new->handconf;
+	old->ignore_state = new->ignore_state;
 	free_bgp_peers(old, 1);
 	old->peer = new->peer;
 	new->peer = NULL;
@@ -340,6 +342,7 @@
 
 	/* setup new list of peers */
 	old->handconf = new->handconf;
+	old->ignore_state = new->ignore_state;
 	free_env_gauges(old, 1);
 	old->gauge = new->gauge;
 	new->gauge = NULL;
@@ -395,7 +398,7 @@
 	OBJECT *parent;
 	OBJECT *old, *new;
 {
-	void *ip_addr;
+	void *ip_addr, *ip_srcaddr;
 	OBJECT *service;
 
 	object_stop(old);
@@ -403,9 +406,13 @@
 	ptrswap(&old->descr, &new->descr);
 	ptrswap(&old->datadir, &new->datadir);
 	ptrswap(&old->address, &new->address);
-	if (parent)
+	if (parent) {
 		ip_addr = &parent->ip_addr;
-	else	ip_addr = &new->ip_addr;
+		ip_srcaddr = &parent->ip_srcaddr;
+	} else {	
+	    ip_addr = &new->ip_addr;
+	    ip_srcaddr = &new->ip_srcaddr;
+	}
 	old->parent = parent;
 
 	if (memcmp(&old->ip_addr, ip_addr, sizeof(old->ip_addr))) {
@@ -418,6 +425,8 @@
 			memset(old->snmpdata, 0, sizeof(SNMP_DATA));
 		}
 	}
+	if (memcmp(&old->ip_srcaddr, ip_srcaddr, sizeof(old->ip_srcaddr))) 
+		memcpy(&old->ip_srcaddr, ip_srcaddr, sizeof(old->ip_srcaddr));
 
 	old->polling = new->polling;
 	old->saving = new->saving;
@@ -450,6 +459,8 @@
 	service = splice_object_list(old, &old->service, &new->service);
 	for (; service; service = service->next) {
 		service->ip_addr = old->ip_addr;
+		service->ip_srcaddr = old->ip_srcaddr;
+		service->ignore_state = old->ignore_state;
 		service->parent = old;
 		object_init(service);
 	}
@@ -516,21 +527,42 @@
 	}
 	if (cf_new->rootdir) free(cf_new->rootdir);
 
+	ptrswap(&cf->chrootdir, &cf_new->chrootdir);
+	if (cf_new->chrootdir) free(cf_new->chrootdir);
+
+	ptrswap(&cf->username, &cf_new->username);
+	if (cf_new->username) free(cf_new->username);
+	cf->uid = cf_new->uid;
+
+	ptrswap(&cf->groupname, &cf_new->groupname);
+	if (cf_new->groupname) free(cf_new->groupname);
+	cf->gid = cf_new->gid;
+
 	ptrswap(&cf->timefmt, &cf_new->timefmt);
 	if (cf_new->timefmt) free(cf_new->timefmt);
 
+	ptrswap(&cf->srcaddress, &cf_new->srcaddress);
+	if (cf_new->srcaddress) free(cf_new->srcaddress);
+	memcpy( &cf->ip_srcaddr, &cf_new->ip_srcaddr, sizeof(struct in_addr));
 	cf->polling = cf_new->polling;
 	cf->saving = cf_new->saving;
 	cf->timeout = cf_new->timeout;
 	cf->retries = cf_new->retries;
+	compatibility_flag = cf->compatibility_flag = cf_new->compatibility_flag;
 
-	if (cf->enable_traps != cf_new->enable_traps) {
+	if ((cf->enable_traps != cf_new->enable_traps) || memcmp(&cf->trap_ip_addr, &cf_new->trap_ip_addr, sizeof(struct in_addr)) ) {
+		ptrswap(&cf->trap_address, &cf_new->trap_address);
+		if (cf_new->trap_address) free(cf_new->trap_address);
+		memcpy( &cf->trap_ip_addr, &cf_new->trap_ip_addr, sizeof(struct in_addr));
 		cf->enable_traps = cf_new->enable_traps;
 		trap_init(cf->enable_traps > 0);
 	}
 	cf->source_traps = cf_new->source_traps;
 
-	if (cf->ns_port != cf_new->ns_port) {
+	if ((cf->ns_port != cf_new->ns_port) || memcmp(&cf->ns_ip_addr, &cf_new->ns_ip_addr, sizeof(struct in_addr))) {
+		ptrswap(&cf->ns_address, &cf_new->ns_address);
+		if (cf_new->ns_address) free(cf_new->ns_address);
+		memcpy( &cf->ns_ip_addr, &cf_new->ns_ip_addr, sizeof(struct in_addr));
 		cf->ns_port = cf_new->ns_port;
 		netstate_init(cf->ns_port);
 	}
@@ -576,6 +608,12 @@
 	free_object_list(cf_cur->target);
 
 	if (cf_cur->rootdir) free(cf_cur->rootdir);
+	if (cf_cur->chrootdir) free(cf_cur->chrootdir);
+	if (cf_cur->username) free(cf_cur->username);
+	if (cf_cur->groupname) free(cf_cur->groupname);
+	if (cf_cur->srcaddress) free(cf_cur->srcaddress);
+	if (cf_cur->ns_address) free(cf_cur->ns_address);
+	if (cf_cur->trap_address) free(cf_cur->trap_address);
 	if (cf_cur->timefmt) free(cf_cur->timefmt);
 
 	trap_init(cf_cur->enable_traps > 0);
@@ -649,6 +687,7 @@
 		if (obj->descr) free(obj->descr);
 		if (obj->datadir) free(obj->datadir);
 		if (obj->address) free(obj->address);
+		if (obj->srcaddress) free(obj->srcaddress);
 		free_trap_list(obj->trap_list);
 		free_var_list(obj->var_list);
 		free_save_list(obj->save_list);
