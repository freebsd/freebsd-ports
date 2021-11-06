--- res/res_fax_spandsp.c.orig	2021-11-02 08:42:19 UTC
+++ res/res_fax_spandsp.c
@@ -167,8 +167,8 @@ struct spandsp_pvt {
 static int spandsp_v21_new(struct spandsp_pvt *p);
 static void session_destroy(struct spandsp_pvt *p);
 static int t38_tx_packet_handler(t38_core_state_t *t38_core_state, void *data, const uint8_t *buf, int len, int count);
-static void t30_phase_e_handler(t30_state_t *t30_state, void *data, int completion_code);
-static void spandsp_log(int level, const char *msg);
+static void t30_phase_e_handler(void *data, int completion_code);
+static void spandsp_log(void *user_data, int level, const char *msg);
 static int update_stats(struct spandsp_pvt *p, int completion_code);
 static int spandsp_modems(struct ast_fax_session_details *details);
 
@@ -375,10 +375,11 @@ static int update_stats(struct spandsp_pvt *p, int com
  * This function pulls stats from the spandsp stack and stores them for res_fax
  * to use later.
  */
-static void t30_phase_e_handler(t30_state_t *t30_state, void *data, int completion_code)
+static void t30_phase_e_handler(void *data, int completion_code)
 {
 	struct ast_fax_session *s = data;
 	struct spandsp_pvt *p = s->tech_pvt;
+	t30_state_t *t30_state = p->t30_state;
 	char headerinfo[T30_MAX_PAGE_HEADER_INFO + 1];
 	const char *c;
 	t30_stats_t stats;
@@ -430,7 +431,7 @@ static void t30_phase_e_handler(t30_state_t *t30_state
  *
  * \note This function is a callback function called by spandsp.
  */
-static void spandsp_log(int level, const char *msg)
+static void spandsp_log(void *user_data, int level, const char *msg)
 {
 	if (level == SPAN_LOG_ERROR) {
 		ast_log(LOG_ERROR, "%s", msg);
@@ -449,7 +450,7 @@ static void set_logging(logging_state_t *state, struct
 		level = SPAN_LOG_DEBUG_3;
 	}
 
-	span_log_set_message_handler(state, spandsp_log);
+	span_log_set_message_handler(state, spandsp_log, NULL);
 	span_log_set_level(state, SPAN_LOG_SHOW_SEVERITY | SPAN_LOG_SHOW_PROTOCOL | level);
 }
 
@@ -479,7 +480,7 @@ static void set_file(t30_state_t *t30_state, struct as
 static void set_ecm(t30_state_t *t30_state, struct ast_fax_session_details *details)
 {
 	t30_set_ecm_capability(t30_state, details->option.ecm);
-	t30_set_supported_compressions(t30_state, T30_SUPPORT_T4_1D_COMPRESSION | T30_SUPPORT_T4_2D_COMPRESSION | T30_SUPPORT_T6_COMPRESSION);
+	t30_set_supported_compressions(t30_state, T4_COMPRESSION_T4_1D | T4_COMPRESSION_T4_2D | T4_COMPRESSION_T6);
 }
 
 static int spandsp_v21_new(struct spandsp_pvt *p)
@@ -1256,7 +1257,7 @@ static int load_module(void)
 	}
 
 	/* prevent logging to stderr */
-	span_set_message_handler(NULL);
+	span_set_message_handler(NULL, NULL);
 
 	return AST_MODULE_LOAD_SUCCESS;
 }
