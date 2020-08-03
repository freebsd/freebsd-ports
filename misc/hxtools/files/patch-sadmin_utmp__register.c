--- sadmin/utmp_register.c.orig	2020-07-12 09:44:16 UTC
+++ sadmin/utmp_register.c
@@ -71,8 +71,10 @@ static bool get_options(int *argc, const char ***argv)
 		 .help = "Perform operation on lastlog"},
 		{.sh = 'U', .type = HXTYPE_NONE, .ptr = &Opt.op_utmp,
 		 .help = "Perform operation on UTMP"},
+#if 0
 		{.sh = 'W', .type = HXTYPE_NONE, .ptr = &Opt.op_wtmp,
 		 .help = "Perform operation on WTMP"},
+#endif
 		{.sh = 'e', .type = HXTYPE_NONE, .ptr = &Opt.epid,
 		 .help = "Encode PID into ut_id"},
 		{.sh = 'h', .type = HXTYPE_STRING, .ptr = &Opt.host,
@@ -87,8 +89,10 @@ static bool get_options(int *argc, const char ***argv)
 		 .help = "Unique ID 2", .htyp = "sess"},
 		{.sh = 'u', .type = HXTYPE_STRING, .ptr = &Opt.futmp,
 		 .help = "Path to utmp"},
+#if 0
 		{.sh = 'w', .type = HXTYPE_STRING, .ptr = &Opt.fwtmp,
 		 .help = "Path to wtmp"},
+#endif
 		HXOPT_AUTOHELP,
 		HXOPT_TABLEEND,
 	};
@@ -181,8 +185,10 @@ static int main2(int argc, const char **argv)
 			setutxent();
 			pututxline(&entry);
 		}
+#if 0
 		if (Opt.op_wtmp)
 			updwtmpx(Opt.fwtmp, &entry);
+#endif
 		if (Opt.op_lastlog)
 			update_lastlog(Opt.flastlog, &entry);
 	}
@@ -193,11 +199,13 @@ static int main2(int argc, const char **argv)
 			setutxent();
 			pututxline(&entry);
 		}
+#if 0
 		if (Opt.op_wtmp)
 			updwtmpx(Opt.fwtmp, &entry);
+#endif
 	}
 
-	endutent();
+	endutxent();
 	return EXIT_SUCCESS;
 }
 
