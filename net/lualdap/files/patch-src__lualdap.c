--- ./src/lualdap.c.orig	2007-12-14 16:11:22.000000000 +0100
+++ ./src/lualdap.c	2013-01-18 00:29:50.000000000 +0100
@@ -6,6 +6,7 @@
 
 #include <stdlib.h>
 #include <string.h>
+#include <assert.h>
 
 #ifdef WIN32
 #include <Winsock2.h>
@@ -19,10 +20,14 @@
 #include "ldap.h"
 #endif
 
-#include "lua.h"
-#include "lauxlib.h"
-#if ! defined (LUA_VERSION_NUM) || LUA_VERSION_NUM < 501
-#include "compat-5.1.h"
+#include <lua.h>
+#include <lauxlib.h>
+
+#if LUA_VERSION_NUM < 502
+/* lua_rawlen: Not entirely correct, but should work anyway */
+#  define lua_rawlen lua_objlen
+#  define luaL_newlib(L,l) (lua_newtable(L), luaL_register(L,NULL,l))
+#  define luaL_setfuncs(L,l,n) (assert(n==0), luaL_register(L,NULL,l))
 #endif
 
 #ifdef WINLDAPAPI
@@ -141,9 +146,9 @@
 /*
 ** Get the field called name of the table at position 2.
 */
-static void strgettable (lua_State *L, const char *name) {
+static void strgettable (lua_State *L, int idx, const char *name) {
 	lua_pushstring (L, name);
-	lua_gettable (L, 2);
+	lua_gettable (L, idx);
 }
 
 
@@ -151,8 +156,8 @@
 ** Get the field named name as a string.
 ** The table MUST be at position 2.
 */
-static const char *strtabparam (lua_State *L, const char *name, char *def) {
-	strgettable (L, name);
+static const char *strtabparam (lua_State *L, int idx, const char *name, char *def) {
+	strgettable (L, idx, name);
 	if (lua_isnil (L, -1))
 		return def;
 	else if (lua_isstring (L, -1))
@@ -168,8 +173,8 @@
 ** Get the field named name as an integer.
 ** The table MUST be at position 2.
 */
-static long longtabparam (lua_State *L, const char *name, int def) {
-	strgettable (L, name);
+static long longtabparam (lua_State *L, int idx, const char *name, int def) {
+	strgettable (L, idx, name);
 	if (lua_isnil (L, -1))
 		return def;
 	else if (lua_isnumber (L, -1))
@@ -183,8 +188,8 @@
 ** Get the field named name as a double.
 ** The table MUST be at position 2.
 */
-static double numbertabparam (lua_State *L, const char *name, double def) {
-	strgettable (L, name);
+static double numbertabparam (lua_State *L, int idx, const char *name, double def) {
+	strgettable (L, idx, name);
 	if (lua_isnil (L, -1))
 		return def;
 	else if (lua_isnumber (L, -1))
@@ -199,7 +204,7 @@
 ** The table MUST be at position 2.
 */
 static int booltabparam (lua_State *L, const char *name, int def) {
-	strgettable (L, name);
+	strgettable (L, 2, name);
 	if (lua_isnil (L, -1))
 		return def;
 	else if (lua_isboolean (L, -1))
@@ -243,7 +248,7 @@
 		value_error (L, n);
 		return NULL;
 	}
-	a->bvals[a->bi].bv_len = lua_strlen (L, -1);
+	a->bvals[a->bi].bv_len = lua_rawlen (L, -1);
 	a->bvals[a->bi].bv_val = (char *)lua_tostring (L, -1);
 	a->bi++;
 	return ret;
@@ -296,7 +301,7 @@
 		A_setval (L, a, name);
 	else if (lua_istable (L, tab)) { /* list of strings */
 		int i;
-		int n = luaL_getn (L, tab);
+		int n = lua_rawlen (L, tab);
 		for (i = 1; i <= n; i++) {
 			lua_rawgeti (L, tab, i); /* push table element */
 			A_setval (L, a, name);
@@ -368,7 +373,7 @@
 		array[1] = NULL;
 	} else if (lua_istable (L, tab)) {
 		int i;
-		int n = luaL_getn (L, tab);
+		int n = lua_rawlen (L, tab);
 		if (limit < (n+1))
 			return luaL_error (L, LUALDAP_PREFIX"too many arguments");
 		for (i = 0; i < n; i++) {
@@ -387,13 +392,25 @@
 
 
 /*
+** Fill in the struct timeval, according to the timeout parameter.
+*/
+static struct timeval *get_timeout_param (lua_State *L, int idx, struct timeval *st) {
+	double t = numbertabparam (L, idx, "timeout", -1);
+	if(t < 0)
+		return NULL; /* No timeout, block */
+	st->tv_sec = (long)t;
+	st->tv_usec = (long)(1000000 * (t - st->tv_sec));
+	return st;
+}
+
+/*
 ** Get the result message of an operation.
 ** #1 upvalue == connection
 ** #2 upvalue == msgid
 ** #3 upvalue == result code of the message (ADD, DEL etc.) to be received.
 */
 static int result_message (lua_State *L) {
-	struct timeval *timeout = NULL; /* ??? function parameter ??? */
+	struct timeval timeout;
 	LDAPMessage *res;
 	int rc;
 	conn_data *conn = (conn_data *)lua_touserdata (L, lua_upvalueindex (1));
@@ -401,7 +418,7 @@
 	/*int res_code = (int)lua_tonumber (L, lua_upvalueindex (3));*/
 
 	luaL_argcheck (L, conn->ld, 1, LUALDAP_PREFIX"LDAP connection is closed");
-	rc = ldap_result (conn->ld, msgid, LDAP_MSG_ONE, timeout, &res);
+	rc = ldap_result (conn->ld, msgid, LDAP_MSG_ONE, get_timeout_param (L, 1, &timeout), &res);
 	if (rc == 0)
 		return faildirect (L, LUALDAP_PREFIX"result timeout expired");
 	else if (rc < 0) {
@@ -424,10 +441,14 @@
 			default:
 				lua_pushnil (L);
 				lua_pushliteral (L, LUALDAP_PREFIX);
-				lua_pushstring (L, msg);
-				lua_pushliteral (L, " ");
 				lua_pushstring (L, ldap_err2string(err));
-				lua_concat (L, 4);
+				lua_concat (L, 2);
+				if (msg != NULL) {
+					lua_pushliteral (L, " (");
+					lua_pushstring (L, msg);
+					lua_pushliteral (L, ")");
+					lua_concat (L, 4);
+				}
 				ret = 2;
 		}
 		ldap_memfree (mdn);
@@ -461,7 +482,11 @@
 	luaL_argcheck(L, conn!=NULL, 1, LUALDAP_PREFIX"LDAP connection expected");
 	if (conn->ld == NULL) /* already closed */
 		return 0;
+#if defined(LDAP_API_FEATURE_X_OPENLDAP) && LDAP_API_FEATURE_X_OPENLDAP >= 20300
+	ldap_unbind_ext (conn->ld, NULL, NULL);
+#else
 	ldap_unbind (conn->ld);
+#endif
 	conn->ld = NULL;
 	lua_pushnumber (L, 1);
 	return 1;
@@ -504,7 +529,7 @@
 	BerValue bvalue;
 	ldap_int_t rc, msgid;
 	bvalue.bv_val = (char *)luaL_checkstring (L, 4);
-	bvalue.bv_len = lua_strlen (L, 4);
+	bvalue.bv_len = lua_rawlen (L, 4);
 	rc = ldap_compare_ext (conn->ld, dn, attr, &bvalue, NULL, NULL, &msgid);
 	return create_future (L, rc, 1, msgid, LDAP_RES_COMPARE);
 }
@@ -666,15 +691,17 @@
 static int next_message (lua_State *L) {
 	search_data *search = getsearch (L);
 	conn_data *conn;
-	struct timeval *timeout = NULL; /* ??? function parameter ??? */
+	struct timeval timeout;
 	LDAPMessage *res;
 	int rc;
 	int ret;
 
+	luaL_checktype(L, 1, LUA_TTABLE);
+
 	lua_rawgeti (L, LUA_REGISTRYINDEX, search->conn);
 	conn = (conn_data *)lua_touserdata (L, -1); /* get connection */
 
-	rc = ldap_result (conn->ld, search->msgid, LDAP_MSG_ONE, timeout, &res);
+	rc = ldap_result (conn->ld, search->msgid, LDAP_MSG_ONE, get_timeout_param (L, 1, &timeout), &res);
 	if (rc == 0)
 		return faildirect (L, LUALDAP_PREFIX"result timeout expired");
 	else if (rc == -1)
@@ -724,8 +751,10 @@
 */
 static int string2scope (lua_State *L, const char *s) {
 	if ((s == NULL) || (*s == '\0'))
-		return LDAP_SCOPE_DEFAULT;
+		return LDAP_SCOPE_SUBTREE;
 	switch (*s) {
+		case 'd':
+			return LDAP_SCOPE_DEFAULT;
 		case 'b':
 			return LDAP_SCOPE_BASE;
 		case 'o':
@@ -784,20 +813,6 @@
 
 
 /*
-** Fill in the struct timeval, according to the timeout parameter.
-*/
-static struct timeval *get_timeout_param (lua_State *L, struct timeval *st) {
-	double t = numbertabparam (L, "timeout", 0);
-	st->tv_sec = (long)t;
-	st->tv_usec = (long)(1000000 * (t - st->tv_sec));
-	if (st->tv_sec == 0 && st->tv_usec == 0)
-		return NULL;
-	else
-		return st;
-}
-
-
-/*
 ** Perform a search operation.
 ** @return #1 Function to iterate over the result entries.
 ** @return #2 nil.
@@ -818,11 +833,11 @@
 		return 2;
 	/* get other parameters */
 	attrsonly = booltabparam (L, "attrsonly", 0);
-	base = (ldap_pchar_t) strtabparam (L, "base", NULL);
-	filter = (ldap_pchar_t) strtabparam (L, "filter", NULL);
-	scope = string2scope (L, strtabparam (L, "scope", NULL));
-	sizelimit = longtabparam (L, "sizelimit", LDAP_NO_LIMIT);
-	timeout = get_timeout_param (L, &st);
+	base = (ldap_pchar_t) strtabparam (L, 2, "base", NULL);
+	filter = (ldap_pchar_t) strtabparam (L, 2, "filter", NULL);
+	scope = string2scope (L, strtabparam (L, 2, "scope", NULL));
+	sizelimit = longtabparam (L, 2, "sizelimit", LDAP_NO_LIMIT);
+	timeout = get_timeout_param (L, 2, &st);
 
 	rc = ldap_search_ext (conn->ld, base, scope, filter, attrs, attrsonly,
 		NULL, NULL, timeout, sizelimit, &msgid);
@@ -831,7 +846,8 @@
 
 	create_search (L, 1, msgid);
 	lua_pushcclosure (L, next_message, 1);
-	return 1;
+	lua_pushvalue(L, 2);
+	return 2;
 }
 
 
@@ -872,7 +888,7 @@
 ** Create a metatable.
 */
 static int lualdap_createmeta (lua_State *L) {
-	const luaL_reg methods[] = {
+	const luaL_Reg methods[] = {
 		{"close", lualdap_close},
 		{"add", lualdap_add},
 		{"compare", lualdap_compare},
@@ -887,7 +903,7 @@
 		return 0;
 
 	/* define methods */
-	luaL_openlib (L, NULL, methods, 0);
+	luaL_setfuncs(L, methods, 0);
 
 	/* define metamethods */
 	lua_pushliteral (L, "__gc");
@@ -939,13 +955,27 @@
 	const char *password = luaL_optstring (L, 3, NULL);
 	int use_tls = lua_toboolean (L, 4);
 	conn_data *conn = (conn_data *)lua_newuserdata (L, sizeof(conn_data));
+#if defined(LDAP_API_FEATURE_X_OPENLDAP) && LDAP_API_FEATURE_X_OPENLDAP >= 20300
+	struct berval cred = { 0, NULL };
+	char *host_with_schema = NULL;
+#endif
 	int err;
 
 	/* Initialize */
 	lualdap_setmeta (L, LUALDAP_CONNECTION_METATABLE);
 	conn->version = 0;
+#if defined(LDAP_API_FEATURE_X_OPENLDAP) && LDAP_API_FEATURE_X_OPENLDAP >= 20300
+	host_with_schema = malloc(strlen(host) + 8);
+	strcpy(host_with_schema, "ldap://");
+	strcat(host_with_schema, host);
+	err = ldap_initialize(&conn->ld, host_with_schema);
+	free(host_with_schema);
+	host_with_schema = NULL;
+	if (err != LDAP_SUCCESS)
+#else
 	conn->ld = ldap_init (host, LDAP_PORT);
 	if (conn->ld == NULL)
+#endif
 		return faildirect(L,LUALDAP_PREFIX"Error connecting to server");
 	/* Set protocol version */
 	conn->version = LDAP_VERSION3;
@@ -959,7 +989,16 @@
 			return faildirect (L, ldap_err2string (rc));
 	}
 	/* Bind to a server */
+#if defined(LDAP_API_FEATURE_X_OPENLDAP) && LDAP_API_FEATURE_X_OPENLDAP >= 20300
+	cred.bv_len = strlen(password);
+	cred.bv_val = malloc(cred.bv_len+1);
+	strcpy(cred.bv_val, password);
+	err = ldap_sasl_bind_s (conn->ld, who, LDAP_SASL_SIMPLE, &cred, NULL, NULL, NULL);
+	free(cred.bv_val);
+	memset(&cred, 0, sizeof(cred));
+#else
 	err = ldap_bind_s (conn->ld, who, password, LDAP_AUTH_SIMPLE);
+#endif
 	if (err != LDAP_SUCCESS)
 		return faildirect (L, ldap_err2string (err));
 
@@ -987,13 +1026,15 @@
 ** Create ldap table and register the open method.
 */
 int luaopen_lualdap (lua_State *L) {
-	struct luaL_reg lualdap[] = {
+	struct luaL_Reg lualdap[] = {
 		{"open_simple", lualdap_open_simple},
 		{NULL, NULL},
 	};
 
 	lualdap_createmeta (L);
-	luaL_openlib (L, LUALDAP_TABLENAME, lualdap, 0);
+	luaL_newlib(L, lualdap);
+	lua_pushvalue(L, -1);
+	lua_setglobal(L, LUALDAP_TABLENAME);
 	set_info (L);
 
 	return 1;
