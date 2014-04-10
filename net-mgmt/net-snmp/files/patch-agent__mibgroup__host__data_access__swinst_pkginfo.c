--- ./agent/mibgroup/host/data_access/swinst_pkginfo.c.orig	2014-04-09 19:21:59.000000000 -0400
+++ ./agent/mibgroup/host/data_access/swinst_pkginfo.c	2014-04-09 19:22:03.000000000 -0400
@@ -32,6 +32,13 @@
 #include <pkginfo.h>
 #endif
 
+#define HAVE_LIBPKG
+
+#ifdef HAVE_LIBPKG
+#define restrict
+#include <pkg.h>
+#endif
+
 #include <net-snmp/net-snmp-includes.h>
 #include <net-snmp/agent/net-snmp-agent-includes.h>
 #include <net-snmp/library/container.h>
@@ -97,52 +104,118 @@
     size_t                date_len;
     int                   i = 1;
     netsnmp_swinst_entry *entry;
+#ifdef HAVE_LIBPKG
+    struct pkgdb *db = NULL;
+    struct pkgdb_it *it = NULL;
+    struct pkg *pkg = NULL;
+    char pkgname[ SNMP_MAXPATH ];
+    char pkgdate[ BUFSIZ ];
+    int pkgng = 0;
+#endif
 
-    if ( !pkg_directory[0] ) {
-        return 1;    /* Can't report installed packages
-                         if there isn't a list of them! */
+#ifdef HAVE_LIBPKG
+    if (pkg_init(NULL, NULL)) {
+	snmp_log( LOG_ERR, "SWInst: error initializing pkgng db\n" );
+	return 1;
     }
-    d = opendir( pkg_directory );
-    if (!d)
+
+    if (pkgdb_open(&db, PKGDB_DEFAULT) != EPKG_OK) {
+	snmp_log( LOG_ERR, "SWInst: error opening pkgng db\n" );
 	return 1;
-    while ((dp = readdir(d)) != NULL) {
-        if ( '.' == dp->d_name[0] )
-            continue;
-        entry = netsnmp_swinst_entry_create( i++ );
-        if (NULL == entry)
-            continue;   /* error already logged by function */
-        CONTAINER_INSERT(container, entry);
+    }
+
+    if (pkg_status(NULL) == PKG_STATUS_ACTIVE) {
+	pkgng = 1;
+    } else {
+	snmp_log( LOG_INFO, "SWInst: not a pkgng system\n" );
+    }
+#endif
+
+#ifdef HAVE_LIBPKG
+    // if we are using FreeBSD's pkgng
+    if (pkgng) {
+	if ((it = pkgdb_query(db, NULL, MATCH_ALL)) == NULL) {
+	    snmp_log( LOG_ERR, "SWInst: error querying pkgng db\n" );
+	    return 1;
+	}
+
+	while (pkgdb_it_next(it, &pkg, PKG_LOAD_BASIC) == EPKG_OK) {
+	    pkg_snprintf(pkgname, sizeof(pkgname), "%n-%v", pkg, pkg);
+	    pkg_snprintf(pkgdate, sizeof(pkgdate), "%t", pkg);
+
+	    entry = netsnmp_swinst_entry_create( i++ );
+
+	    if (NULL == entry)
+		continue;   /* error already logged by function */
+
+	    CONTAINER_INSERT(container, entry);
+
+	    entry->swName_len = snprintf( entry->swName, sizeof(entry->swName),
+					  "%s", pkgname );
+	    if (entry->swName_len >= sizeof(entry->swName))
+		entry->swName_len = sizeof(entry->swName)-1;
+
+            install_time = atoi(pkgdate);
+            cp = date_n_time( &install_time, &date_len );
+            memcpy( entry->swDate, cp, date_len );
+            entry->swDate_len = date_len;
+	}
+
+	pkgdb_it_free(it);
+	pkgdb_close(db);
+	pkg_shutdown();
+    } else {
+#endif
+	if ( !pkg_directory[0] ) {
+	    return 1;    /* Can't report installed packages
+                         if there isn't a list of them! */
+    	}
+
+    	d = opendir( pkg_directory );
+    	if (!d)
+	    return 1;
+
+	while ((dp = readdir(d)) != NULL) {
+	    if ( '.' == dp->d_name[0] )
+		continue;
+	    entry = netsnmp_swinst_entry_create( i++ );
+	    if (NULL == entry)
+		continue;   /* error already logged by function */
+	    CONTAINER_INSERT(container, entry);
 
 #ifdef HAVE_PKGINFO
-        v = pkgparam( dp->d_name, "VERSION" );
-        c = pkgparam( dp->d_name, "CATEGORY" );
+	    v = pkgparam( dp->d_name, "VERSION" );
+	    c = pkgparam( dp->d_name, "CATEGORY" );
 
-        entry->swName_len = snprintf( entry->swName, sizeof(entry->swName),
-                                      "%s-%s", dp->d_name, v );
-	if (entry->swName_len >= sizeof(entry->swName))
-	    entry->swName_len = sizeof(entry->swName)-1;
-        entry->swType = (NULL != strstr( c, "system"))
-                        ? 2      /* operatingSystem */
-                        : 4;     /*  application    */
+	    entry->swName_len = snprintf( entry->swName, sizeof(entry->swName),
+					  "%s-%s", dp->d_name, v );
+	    if (entry->swName_len >= sizeof(entry->swName))
+		entry->swName_len = sizeof(entry->swName)-1;
+	    entry->swType = (NULL != strstr( c, "system"))
+			    ? 2      /* operatingSystem */
+			    : 4;     /*  application    */
 
-        /* Do we need to free 'v' & 'c' ??? */
+	    /* Do we need to free 'v' & 'c' ??? */
 #else
-        entry->swName_len = snprintf( entry->swName, sizeof(entry->swName),
-                                      "%s", dp->d_name );
-	if (entry->swName_len >= sizeof(entry->swName))
-	    entry->swName_len = sizeof(entry->swName)-1;
+	    entry->swName_len = snprintf( entry->swName, sizeof(entry->swName),
+					  "%s", dp->d_name );
+	    if (entry->swName_len >= sizeof(entry->swName))
+		entry->swName_len = sizeof(entry->swName)-1;
 
-        /* no information about O/S vs application packages ??? */
+	    /* no information about O/S vs application packages ??? */
 #endif
 
-        snprintf( buf, BUFSIZ, "%s/%s", pkg_directory, dp->d_name );
-        stat( buf, &stat_buf );
-        install_time = stat_buf.st_mtime;
-        cp = date_n_time( &install_time, &date_len );
-        memcpy( entry->swDate, cp, date_len );
-        entry->swDate_len = date_len;
+	    snprintf( buf, BUFSIZ, "%s/%s", pkg_directory, dp->d_name );
+	    stat( buf, &stat_buf );
+	    install_time = stat_buf.st_mtime;
+	    cp = date_n_time( &install_time, &date_len );
+	    memcpy( entry->swDate, cp, date_len );
+	    entry->swDate_len = date_len;
+	}
+    	closedir( d );
+#ifdef HAVE_LIBPKG
     }
-    closedir( d );
+#endif
 
     DEBUGMSGTL(("swinst:load:arch"," loaded %d entries\n",
                 (int)CONTAINER_SIZE(container)));
