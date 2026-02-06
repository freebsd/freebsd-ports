--- logsource/logsource_file.go.orig	2026-11-07 09:51:47 UTC
+++ logsource/logsource_file.go
@@ -83,7 +83,7 @@ func (f *fileLogSourceFactory) Init(app *kingpin.Appli
 }
 
 func (f *fileLogSourceFactory) Init(app *kingpin.Application) {
-	app.Flag("postfix.logfile_path", "Path where Postfix writes log entries.").Default("/var/log/mail.log").StringVar(&f.path)
+	app.Flag("postfix.logfile_path", "Path where Postfix writes log entries.").Default("/var/log/maillog").StringVar(&f.path)
 	app.Flag("postfix.logfile_must_exist", "Fail if the log file doesn't exist.").Default("true").BoolVar(&f.mustExist)
 	app.Flag("postfix.logfile_debug", "Enable debug logging for the log file.").Default("false").BoolVar(&f.debug)
 	app.Flag("postfix.logfile_poll", "Poll for file changes instead of using inotify.").Default("false").BoolVar(&f.poll)
