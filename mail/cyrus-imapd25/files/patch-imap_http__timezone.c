--- imap/http_timezone.c.orig	2018-04-10 19:19:55 UTC
+++ imap/http_timezone.c
@@ -388,7 +388,7 @@ static int action_list(struct transaction_t *txn)
 	param = hash_lookup("changedsince", &txn->req_qparams);
 	if (param) {
 	    changedsince = icaltime_from_string(param->s);
-	    if (param->next || !changedsince.is_utc) {  /* once only, UTC */
+	    if (param->next || !icaltime_is_utc(changedsince)) {  /* once only, UTC */
 		return json_error_response(txn, TZ_INVALID_CHANGEDSINCE,
 					   param, &changedsince);
 	    }
@@ -396,7 +396,7 @@ static int action_list(struct transaction_t *txn)
 
 	name = hash_lookup("tzid", &txn->req_qparams);
 	if (name) {
-	    if (changedsince.is_utc) {
+	    if (icaltime_is_utc(changedsince)) {
 		return json_error_response(txn, TZ_INVALID_TZID,
 					   param, &changedsince);
 	    }
@@ -589,7 +589,7 @@ static const struct observance *truncate_vtimezone(ica
 
 	/* Adjust DTSTART observance to UTC */
 	icaltime_adjust(&obs.onset, 0, 0, 0, -obs.offset_from);
-	obs.onset.is_utc = 1;
+	icaltime_set_utc(&obs.onset, 1);
 
 	/* Check DTSTART vs window close */
 	if (!icaltime_is_null_time(end) &&
@@ -651,7 +651,7 @@ static const struct observance *truncate_vtimezone(ica
 		if (!infinite) {
 		    /* Adjust UNTIL to local time (for iterator) */
 		    icaltime_adjust(&rrule.until, 0, 0, 0, obs.offset_from);
-		    rrule.until.is_utc = 0;
+		    icaltime_set_utc(&rrule.until, 0);
 		}
 
 		if (trunc_dtstart) {
@@ -675,7 +675,7 @@ static const struct observance *truncate_vtimezone(ica
 
 		    /* Adjust observance to UTC */
 		    icaltime_adjust(&obs.onset, 0, 0, 0, -obs.offset_from);
-		    obs.onset.is_utc = 1;
+		    icaltime_set_utc(&obs.onset, 1);
 
 		    if (trunc_until && icaltime_compare(obs.onset, end) > 0) {
 			/* Observance is on/after window close */
@@ -776,7 +776,7 @@ static const struct observance *truncate_vtimezone(ica
 
 	    /* Adjust observance to UTC */
 	    icaltime_adjust(&obs.onset, 0, 0, 0, -obs.offset_from);
-	    obs.onset.is_utc = 1;
+	    icaltime_set_utc(&obs.onset, 1);
 
 	    if (!icaltime_is_null_time(end) &&
 		icaltime_compare(obs.onset, end) >= 0) {
@@ -880,7 +880,7 @@ static const struct observance *truncate_vtimezone(ica
 	    case ICAL_DTSTART_PROPERTY:
 		/* Adjust window open to local time */
 		icaltime_adjust(&start, 0, 0, 0, tombstone.offset_from);
-		start.is_utc = 0;
+		icaltime_set_utc(&start, 1);
 
 		icalproperty_set_dtstart(prop, start);
 		break;
@@ -1160,7 +1160,7 @@ static int action_expand(struct transaction_t *txn)
     param = hash_lookup("changedsince", &txn->req_qparams);
     if (param) {
 	changedsince = icaltime_from_string(param->s);
-	if (param->next || !changedsince.is_utc) {  /* once only, UTC */
+	if (param->next || !icaltime_is_utc(changedsince)) {  /* once only, UTC */
 	    return json_error_response(txn, TZ_INVALID_CHANGEDSINCE,
 				       param, &changedsince);
 	}
@@ -1171,13 +1171,13 @@ static int action_expand(struct transaction_t *txn)
 	return json_error_response(txn, TZ_INVALID_START, param, NULL);
 
     start = icaltime_from_string(param->s);
-    if (!start.is_utc)  /* MUST be UTC */
+    if (!icaltime_is_utc(start))  /* MUST be UTC */
 	return json_error_response(txn, TZ_INVALID_START, param, &start);
 
     param = hash_lookup("end", &txn->req_qparams);
     if (param) {
 	end = icaltime_from_string(param->s);
-	if (param->next || !end.is_utc  /* once only, UTC */
+	if (param->next || !icaltime_is_utc(end)  /* once only, UTC */
 	    || icaltime_compare(end, start) <= 0) {  /* end MUST be > start */
 	    return json_error_response(txn, TZ_INVALID_END, param, &end);
 	}
@@ -1435,7 +1435,7 @@ static int json_error_response(struct transaction_t *t
     else if (param->next) fmt = "multiple %s parameters";
     else if (!param->s || !param->s[0]) fmt = "missing %s value";
     else if (!time) fmt = "unknown %s value";
-    else if (!time->is_utc) fmt = "invalid %s UTC value";
+    else if (!icaltime_is_utc(*time)) fmt = "invalid %s UTC value";
 
     switch (tz_code) {
     case TZ_INVALID_TZID:
@@ -1463,4 +1463,13 @@ static int json_error_response(struct transaction_t *t
     }
 
     return json_response(http_code, txn, root, NULL);
+}
+
+EXPORTED void icaltime_set_utc(struct icaltimetype *t, int set)
+{
+#ifdef ICALTIME_HAS_IS_UTC
+    t->is_utc = set;
+#else
+    icaltime_set_timezone(t, set ? icaltimezone_get_utc_timezone() : NULL);
+#endif
 }
