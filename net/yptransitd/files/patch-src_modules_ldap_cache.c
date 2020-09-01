--- src/modules/ldap/cache.c.orig	2001-10-09 02:34:51 UTC
+++ src/modules/ldap/cache.c
@@ -278,8 +278,8 @@ int assemble_passwd(valdat *val, LDAPMes
 			} else
 			if(!strcasecmp(attr, "userpassword"))
 			{
-				pwinfo->userpassword = fix_password(values);
-				pwinfo->size += strlen(pwinfo->userpassword);
+				pwinfo->userpassword = safe_strdup("*");
+				pwinfo->size += strlen("*");
 			} else
 			if(!strcasecmp(attr, "uidnumber"))
 			{
@@ -322,6 +322,73 @@ int assemble_passwd(valdat *val, LDAPMes
 	return (rval);
 }
 
+int assemble_master_passwd(valdat *val, LDAPMessage *user, struct pwinfo *pwinfo)
+{
+	ypstat rval;
+	char *attr;
+	BerElement *ber = NULL;
+
+	rval = YP_YPERR;
+	fill_pwinfo(pwinfo);
+	
+	for (attr = ldap_first_attribute (ldaprefs.ldap, user, &ber); attr; attr = ldap_next_attribute (ldaprefs.ldap, user, ber))
+	{
+		char **values;
+
+		values = ldap_get_values (ldaprefs.ldap, user, attr);
+		if (values)
+		{
+			if(!strcasecmp(attr, "uid"))
+			{
+				pwinfo->uid = safe_strdup(values[0]);
+				pwinfo->size += strlen(values[0]);
+			} else
+			if(!strcasecmp(attr, "userpassword"))
+			{
+				pwinfo->userpassword = fix_password(values);
+				pwinfo->size += strlen(pwinfo->userpassword);
+			} else
+			if(!strcasecmp(attr, "uidnumber"))
+			{
+				pwinfo->uidnumber = safe_strdup(values[0]);
+				pwinfo->size += strlen(values[0]);
+			} else
+			if(!strcasecmp(attr, "gidnumber"))
+			{
+				pwinfo->gidnumber = safe_strdup(values[0]);
+				pwinfo->size += strlen(values[0]);
+			} else
+			if(!strcasecmp(attr, "gecos"))
+			{
+				pwinfo->gecos = safe_strdup(values[0]);
+				pwinfo->size += strlen(values[0]);
+			} else
+			if(!strcasecmp(attr, "homedirectory"))
+			{
+				pwinfo->homedirectory = safe_strdup(values[0]);
+				pwinfo->size += strlen(values[0]);
+			} else
+			if(!strcasecmp(attr, "loginshell"))
+			{
+				pwinfo->loginshell = safe_strdup(values[0]);
+				pwinfo->size += strlen(values[0]);
+			}
+			ldap_value_free(values);
+		}
+	}
+	if (check_pwinfo(pwinfo) == YP_TRUE)
+	{
+		val->valdat_len = pwinfo->size + MPWLINE_SIZE;
+		val->valdat_val = safe_malloc(val->valdat_len + 1);
+		sprintf(val->valdat_val, MPWLINE, pwinfo->uid, pwinfo->userpassword, pwinfo->uidnumber, pwinfo->gidnumber, pwinfo->gecos, pwinfo->homedirectory, pwinfo->loginshell);
+		rval = YP_TRUE;
+	} else {
+		rval = YP_NOKEY;
+	}
+
+	return (rval);
+}
+
 int assemble_group(valdat *val, LDAPMessage *group, struct gwinfo *gwinfo)
 {
 	ypstat rval;
@@ -452,7 +519,7 @@ struct mapcache *create_cache (ypmaplist
 	valdat *val;
 	int rval;
 
-	(void *) mapcache_current = (void *) mapcache_head = (void *) ldapreturn = (void *) record = NULL;
+	mapcache_current = mapcache_head = ldapreturn = record = NULL;
 	val = safe_malloc(sizeof(valdat));
 
 	for(maplist_current = maps; maplist_current; maplist_current = maplist_current->next)
@@ -538,6 +605,80 @@ struct mapcache *create_cache (ypmaplist
 			free(filter);
 			free(base);
 		}
+		else if (!strcmp((char *) mapcache_current->map, "master.passwd.byname"))
+		{
+			/* XXX Add preferences for filter and basedn */
+			base = safe_malloc(strlen(ldaprefs.basedn) + strlen("ou=Staffs,") + 1);
+			sprintf(base, "%s%s", "ou=Staffs,", ldaprefs.basedn);
+			filter = safe_strdup("(objectClass=posixAccount)");
+
+			if(ldap_search_s(ldaprefs.ldap,
+						base,
+						LDAP_SCOPE_ONELEVEL,
+						filter,
+						user_attributes,
+						0,
+						&ldapreturn) != -1)
+			{
+				for (record = ldap_first_entry(ldaprefs.ldap, ldapreturn); record; record = ldap_next_entry(ldaprefs.ldap, record))
+				{
+					pwinfo = safe_malloc(sizeof(struct pwinfo));
+					rval = assemble_master_passwd(val, record, pwinfo);
+					if(rval == YP_TRUE);
+					{
+						if(check_unique(mapcache_current, pwinfo->uid) == YP_NOKEY)
+						{
+							mapentry_current = safe_malloc(sizeof(struct mapentry));
+							mapentry_current->key = safe_strdup(pwinfo->uid);
+							mapentry_current->val = val->valdat_val;
+							mapentry_current->next = mapcache_current->mapentry;
+							mapcache_current->mapentry = mapentry_current;
+						}
+					}
+					clean_pwinfo(pwinfo);
+				}
+			}
+			ldap_msgfree(ldapreturn);
+			free(filter);
+			free(base);
+		}
+		else if (!strcmp((char *) mapcache_current->map, "master.passwd.byuid"))
+		{
+			/* XXX Add preferences for filter and basedn */
+			base = safe_malloc(strlen(ldaprefs.basedn) + strlen("ou=Staffs,") + 1);
+			sprintf(base, "%s%s", "ou=Staffs,", ldaprefs.basedn);
+			filter = safe_strdup("(objectClass=posixAccount)");
+
+			if(ldap_search_s(ldaprefs.ldap,
+						base,
+						LDAP_SCOPE_ONELEVEL,
+						filter,
+						user_attributes,
+						0,
+						&ldapreturn) != -1)
+			{
+				for (record = ldap_first_entry(ldaprefs.ldap, ldapreturn); record; record = ldap_next_entry(ldaprefs.ldap, record))
+				{
+					pwinfo = safe_malloc(sizeof(struct pwinfo));
+					rval = assemble_master_passwd(val, record, pwinfo);
+					if(rval == YP_TRUE);
+					{
+						if(check_unique(mapcache_current, pwinfo->uidnumber) == YP_NOKEY)
+						{
+							mapentry_current = safe_malloc(sizeof(struct mapentry));
+							mapentry_current->key = safe_strdup(pwinfo->uidnumber);
+							mapentry_current->val = val->valdat_val;
+							mapentry_current->next = mapcache_current->mapentry;
+							mapcache_current->mapentry = mapentry_current;
+						}
+					}
+					clean_pwinfo(pwinfo);
+				}
+			}
+			ldap_msgfree(ldapreturn);
+			free(filter);
+			free(base);
+		}
 		else if (!strcmp((char *) mapcache_current->map, "group.byname"))
 		{
 			/* XXX Add preferences for filter and basedn */
