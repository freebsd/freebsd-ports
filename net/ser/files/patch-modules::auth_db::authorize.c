
$FreeBSD$

--- modules/auth_db/authorize.c
+++ modules/auth_db/authorize.c
@@ -101,7 +101,7 @@
 	}
 	pkg_free(col);
 
-	if ((RES_ROW_N(*res) == 0) || VAL_NULL(ROW_VALUES(RES_ROWS(*res)))) {
+	if (RES_ROW_N(*res) == 0) {
 		DBG("get_ha1(): no result for user \'%.*s@%.*s\'\n",
 		    _username->user.len, ZSW(_username->user.s), (use_domain ? (_domain->len) : 0), ZSW(_domain->s));
 		return 1;
@@ -212,9 +212,7 @@
 		rpid.s = NULL;
 		rpid.len = 0;
 		for (i = 0; i < avps_str_n; i++) {
-			if (avps_str[i].len != 4
-					|| VAL_NULL(&(result->rows[0].values[1 + avps_int_n + i]))
-					|| memcmp(avps_str[i].s, "rpid", 4) != 0)
+			if (avps_str[i].len != 4 || memcmp(avps_str[i].s, "rpid", 4) != 0)
 				continue;
 			rpid.s = (char*)VAL_STRING(&(result->rows[0].values[1 + avps_int_n + i]));
 			if(rpid.s!=NULL)
@@ -230,8 +228,6 @@
 			return -1;
 		case AUTHORIZED:
 			for (i = 0; i < avps_int_n; i++) {
-				if(VAL_NULL(&(result->rows[0].values[1 + i])))
-					continue;
 				iname.s = &(avps_int[i]);
 				ivalue.n = VAL_INT(&(result->rows[0].values[1 + i]));
 				add_avp(AVP_NAME_STR, iname, ivalue);
@@ -240,8 +236,7 @@
 			}
 			for (i = 0; i < avps_str_n; i++) {
 				value.s = (char*)VAL_STRING(&(result->rows[0].values[1 + avps_int_n + i]));
-				if(VAL_NULL(&(result->rows[0].values[1 + avps_int_n + i]))
-						|| value.s==NULL)
+				if(value.s==NULL)
 					continue;
 				iname.s = &(avps_str[i]);
 				value.len = strlen(value.s);
